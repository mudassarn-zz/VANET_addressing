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

#include "MACHack.h"

Define_Module(MACHack);

MACHack::MACHack() {
}

MACHack::~MACHack() {
   
}

void MACHack::initialize() {
    address = par("address").stringValue();
    
    // created the spoofed sender address
    for(int i = 0; i < 12; i++) {
		if(address[i] == '\0') {
			/* invalid mac address passed to us */
			error("Invalid macAddress parameter, needs to be 12 characters long");
		}
		
		if(address[i] == 'f' || address[i] == 'F') {
			spoofedSenderAddress[i] = '0';
		}
		else {
			spoofedSenderAddress[i] = address[i] + 1;
		}
	}
	spoofedSenderAddress[12] = '\0';
	
	EV << "MACHack config: src[" << spoofedSenderAddress << "], dst[" << address << "]" << endl;
}

void MACHack::handleMessage(cMessage *msg)
{
    Ieee80211TwoAddressFrame *twoAddressFrame = dynamic_cast<Ieee80211TwoAddressFrame *>(msg);
    
    if(twoAddressFrame == 0) {
		EV << msg << " is not MACHackable!" << endl;
	}
	else {
	
		twoAddressFrame->setTransmitterAddress(MACAddress(spoofedSenderAddress)); //differentiate the sender from the receiver
		twoAddressFrame->setReceiverAddress(MACAddress(address)); //set the receiver as this MAC layer address
    
		EV << msg << " Airframe MACHacked: " << "src[" << spoofedSenderAddress << "], dst[" << address << "]" << endl;
	}
    
    /* send this hacked frame out yo */
    send(msg, "hackedOut");
}
