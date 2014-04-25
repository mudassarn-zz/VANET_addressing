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

#ifndef VEHICLEAPP_H_
#define VEHICLEAPP_H_

#include "VAPacket_m.h"
#include "Ieee80211Frame_m.h"
#include "MACAddress.h"

#include <omnetpp.h>

class VehicleApp : public cSimpleModule
{
  private:
    // configuration
    bool isMalicious;
    int packetLengthBytes; //length of packets which the vehicle sends (to maintain compatibility with cPacket)
    int sendInterval; //interval to send APP_DATA packets
    int mySuffix; //vehicle suffix
    int destSuffix; //destination suffix to send packets
    int destKey; //key of the destination
    int forwardSuffix; //suffix to forward packets to
    int forwardKey; //key of the forwarded node
    
    cMessage *appDataTimer; //used to time APP_DATA packets
    VAPacket *appDataPkt; //used for APP_DATA

  public:
    VehicleApp();
    virtual ~VehicleApp();

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

#endif /* VEHICLEAPP_H_ */
