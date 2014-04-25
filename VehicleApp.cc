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

#include "VehicleApp.h"
#include <iostream>

Define_Module(VehicleApp);

VehicleApp::VehicleApp() {
}

VehicleApp::~VehicleApp() {
	cancelAndDelete(appDataTimer);
    delete appDataPkt;
}

void VehicleApp::initialize() {
	isMalicious = par("malicious").boolValue();
    packetLengthBytes = par("packetLength").longValue();
    sendInterval = par("sendInterval").longValue();
    mySuffix = par("suffix").longValue();
    destSuffix = par("destination").longValue();
    destKey = par("destinationKey").longValue();
    forwardSuffix = par("forwardSuffix").longValue();
    forwardKey = par("forwardKey").longValue();
    
	//create APP_DATA packet
	appDataPkt = new VAPacket("APP_DATA");
	appDataPkt->setByteLength(packetLengthBytes);
	appDataPkt->setSourceSuffix(mySuffix);
	appDataPkt->setSourcePrefix(-1);
	appDataPkt->setDestPrefix(-1);
	appDataPkt->setDestSuffix(destSuffix);
	appDataPkt->setKey(destKey);
	appDataPkt->setType(APP_DATA);
	appDataTimer = new cMessage("APP_DATA_TIMER");
	
	if(sendInterval != -1) {	
		// create and schedule first beacon timer
		scheduleAt(sendInterval, appDataTimer);
	}
    
}

void VehicleApp::handleMessage(cMessage *msg)
{	
	if (msg == appDataTimer)               // should periodically send beacons to all nodes in the destAddresses list
    {
        // gots us a packet to send
        
        char pkname[40];
        sprintf(pkname,"pk-%d", mySuffix);
        EV << "generating app_data " << pkname << endl;
		
		//create MAC layer IEEE80211 frame
		//encapsulate in a Ieee80211DataOrMgmtFrame and send to vehicle layer
		Ieee80211DataFrame *frame = new Ieee80211DataFrame("APP_DATA_FRAME");
		frame->setReceiverAddress(MACAddress(1)); //doesn't matter, we hack it at the receiver
		frame->encapsulate(appDataPkt->dup());
		
        send(frame,"appOut");
		
		if(sendInterval != -1) {
			scheduleAt(simTime() + sendInterval, appDataTimer);
		}
        
        if (ev.isGUI() && isMalicious) {
			getParentModule()->bubble("HAHA, I send malicious packet!!!");
		}
    }
    else
    {
		//decapsulate the packet from the frame
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
			//put stuff here if receiving packets
			case APP_DATA:
				EV << "Vehicle application received a packet..." << endl;
				//depending on config, send a packet to another vehicle
				if(forwardSuffix != -1) {
					EV << "forwarding a new packet to: " << forwardSuffix << " using key: " << forwardKey << endl;
					//create a new packet to forward
					VAPacket *newPkt = packet->dup();
					
					newPkt->setKey(forwardKey); //'public' key for encryption (yep both public/private are the same)
					newPkt->setDestSuffix(forwardSuffix);
					newPkt->setSourceSuffix(mySuffix);
					
					//encapsulate in a Ieee80211DataOrMgmtFrame and send to vehicle layer
					Ieee80211DataFrame *newFrame = new Ieee80211DataFrame("APP_DATA_FRAME");
					newFrame->setReceiverAddress(MACAddress(1)); //doesn't matter, we hack it at the receiver
					newFrame->encapsulate(newPkt);
					
					send(newFrame, "appOut");
				}
			break;
		}
		
		delete msg; //must delete this first, before deleting the packet
		delete packet;	
	}
}
