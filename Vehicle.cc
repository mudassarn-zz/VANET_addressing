//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "Vehicle.h"
#include <iostream>

Define_Module(Vehicle);

Vehicle::Vehicle() {
}

Vehicle::~Vehicle() {
	delete rsuBeaconACK;
}

void Vehicle::initialize() {
	isMalicious = par("malicious").boolValue();
    myPrefix = -1; //initially unassigned
    mySuffix = par("suffix").longValue();
    myKey = par("key").longValue();
    packetLengthBytes = par("packetLength").longValue();
    
    //create RSU Beacon ACK packet
    rsuBeaconACK = new VAPacket("RSU_BEACON_ACK");
    rsuBeaconACK->setByteLength(packetLengthBytes);
    rsuBeaconACK->setSourceSuffix(mySuffix);
    rsuBeaconACK->setDestPrefix(-1);
    rsuBeaconACK->setDestSuffix(-1);
    rsuBeaconACK->setKey(myKey);
    rsuBeaconACK->setType(RSU_BEACON_REPLY);

    WATCH(myPrefix); //this will display the prefix during the simulation under the appropriate module
}

void Vehicle::handleMessage(cMessage *msg)
{
    //decapsulate the packet from the frame
    Ieee80211DataFrame *frame = dynamic_cast<Ieee80211DataFrame*>(msg);
		
	if(frame == 0) {
		//dunno what this is, delete it
		EV << "Received an unknown message, deleting..." << endl;
		delete msg;
		return;
	}
		
	VAPacket *packet = dynamic_cast<VAPacket*>(frame->getEncapsulatedPacket());
		
	if(packet == 0) {
		//dunno what this is, delete it
		EV << "Received an unknown encapsulated packet, deleting..." << endl;
		delete msg;
		return;
	}
		
	switch(packet->getType()) {
		case APP_DATA:
			EV << "Received APP_DATA from suffix " << packet->getSourceSuffix() << ", to suffix " << packet->getDestSuffix() << endl;
			if(strcmp(msg->getArrivalGate()->getBaseName(), "upperLayerIn") == 0) {
				/* forward this packet along */
				EV << "Forwarding downward..." << endl;
				send(msg, "lowerLayerOut");
			}
			else {
				if(!isMalicious && packet->getSourceSuffix() == mySuffix) {
					EV << "SPOOFED PACKET!!  Sender claims to be me!!" << endl;
					if (ev.isGUI()) {
						 getParentModule()->bubble("Hey!  Who is spoofing me??");
					}
				}
				
				if(packet->getDestSuffix() == mySuffix) {
					/* came from lower layer */
					EV << "Attempting to decrypt..." << endl;	
					
					//'decrypt' message
					if(packet->getKey() == myKey) {
						//success!!
						EV << "Decryption successful, passing to application..." << endl;
						
						send(msg, "upperLayerOut");
					}
					else {
						// doh!!
						EV << "Decryption failed!!  I do not have the proper private key!!" << endl;
						EV << "Dropping packet..." << endl;
						
						if (isMalicious && ev.isGUI()) {
							 getParentModule()->bubble("NOO!! My evil plan ruined, again!!");
						}
						
						frame->decapsulate(); //officially decapsulate the packet
						delete msg; //must delete this first, before deleting the packet
						delete packet;
					}
				}
				else {
					// packet aint for me
					EV << "This packet aint for me, dropping..." << endl;
					
					frame->decapsulate(); //officially decapsulate the packet
					delete msg; //must delete this first, before deleting the packet
					delete packet;
				}
			}
			break;
		case RSU_BEACON:
			EV << "Received RSU_BEACON from prefix: " << packet->getSourcePrefix() << endl;
			if(packet->getSourcePrefix() != -1) {
				//check if the prefix has changed
				if(packet->getSourcePrefix() != myPrefix) {
					//update our prefix
					EV << "Zone update, received prefix = " << packet->getSourcePrefix() << "[old prefix = " << myPrefix << "]" << endl;
					myPrefix = packet->getSourcePrefix();
					
					/** statistics **/
					std::cout << mySuffix << " " << myPrefix << std::endl;
					
					if (ev.isGUI()) {
						char newPrefixMsg[50];
						sprintf(newPrefixMsg, "Zone update, new prefix: %d", myPrefix);
						getParentModule()->bubble(newPrefixMsg);
					}
				}
				
				// send ACK
				Ieee80211DataFrame *newFrame = new Ieee80211DataFrame("RSU_BEACON_REPLY_FRAME");
				newFrame->setReceiverAddress(MACAddress(1)); //doesn't matter, we hack it at the receiver
				
				rsuBeaconACK->setSourcePrefix(myPrefix);
				
				newFrame->encapsulate(rsuBeaconACK->dup());
				
				send(newFrame, "lowerLayerOut");
			}
			
			frame->decapsulate(); //officially decapsulate the packet
			delete msg; //must delete this first, before deleting the packet
			delete packet;
			
			break;
	}
}
