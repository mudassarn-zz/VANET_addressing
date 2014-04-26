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

#include "RSU.h"
#include <iostream>

Define_Module(RSU);

RSU::RSU() {
}

RSU::~RSU() {
    cancelAndDelete(rsuBeaconTimer);
    delete rsuBeaconPkt;
}

void RSU::initialize() {
    myPrefix = par("prefix").longValue();
    packetLengthBytes = par("packetLength").longValue();
    beaconInterval = par("beaconInterval").doubleValue();

    WATCH(myPrefix); //this will display the prefix during the simulation under the appropriate module
	
	//create RSU Beacon packet
    rsuBeaconPkt = new VAPacket("RSU_BEACON");
    rsuBeaconPkt->setByteLength(packetLengthBytes);
    rsuBeaconPkt->setSourcePrefix(myPrefix);
    rsuBeaconPkt->setSourceSuffix(-1);
    rsuBeaconPkt->setDestPrefix(-1);
    rsuBeaconPkt->setDestSuffix(-1);
    rsuBeaconPkt->setKey(-1);
    rsuBeaconPkt->setType(RSU_BEACON);
    
    // create and schedule first beacon timer
    rsuBeaconTimer = new cMessage("RSU_BEACON_TIMER");
    scheduleAt(beaconInterval, rsuBeaconTimer);
}

void RSU::handleMessage(cMessage *msg)
{
    if (msg == rsuBeaconTimer)               // should periodically send beacons to all nodes in the destAddresses list
    {
        // gots us a beacon to send
        
        char pkname[40];
        sprintf(pkname,"pk-%d", myPrefix);
        EV << "generating beacon " << pkname << endl;
		
		//create MAC layer IEEE80211 frame
		//encapsulate in a Ieee80211DataOrMgmtFrame and send to MAC layer
		Ieee80211DataFrame *frame = new Ieee80211DataFrame("RSU_BEACON_FRAME");
		frame->setReceiverAddress(MACAddress(1)); //doesn't matter, we hack it at the receiver
		frame->encapsulate(rsuBeaconPkt->dup());
		
        send(frame,"rsuOut");

        scheduleAt(simTime() + beaconInterval, rsuBeaconTimer);
        //if (ev.isGUI()) getParentModule()->bubble("Generating RSU_Beacon...");
    }
    else
    {
		Ieee80211DataFrame *frame = dynamic_cast<Ieee80211DataFrame*>(msg);
		
		if(frame == 0) {
			//dunno what this is, delete it
			EV << "Received an unknown message, deleting..." << endl;
			delete msg;
			return;
		}
		
		VAPacket *packet = dynamic_cast<VAPacket*>(frame->decapsulate());
		
		if(packet == 0) {
			//dunno what this is, delete it
			EV << "Received an unknown encapsulated packet, deleting..." << endl;
			delete msg;
			return;
		}
		
		switch(packet->getType()) {
			case RSU_BEACON:
				//add RSU as a neighbour
				EV << "Received RSU_BEACON from RSU: " << packet->getSourcePrefix() << endl;
				break;
			case RSU_BEACON_REPLY:
				EV << "Received RSU_BEACON_REPLY from Vehicle: " << packet->getSourceSuffix() << endl;
				if (ev.isGUI()) {
					 char ack[60];
					 sprintf(ack, "Received: RSU_BEACON_REPLY [from: %d]", packet->getSourceSuffix());
					 getParentModule()->bubble(ack);
				}
		}
		
		delete msg; //must delete this first, before deleting the packet
		delete packet;
    }
}
