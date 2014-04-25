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

#ifndef RSU_H_
#define RSU_H_

#include "VAPacket_m.h"
#include "Ieee80211Frame_m.h"
#include "MACAddress.h"

#include <vector>
#include <omnetpp.h>

class RSU : public cSimpleModule
{
  private:
    // configuration
    int myPrefix; //the prefix of this RSU
    int packetLengthBytes; //length of packets which the RSU sends (to maintain compatibility with cPacket)
    double beaconInterval; //interval between RSU beacon broadcasts

    // state
    cMessage *rsuBeaconTimer; //used to time beacons
    VAPacket *rsuBeaconPkt; //used for beacons

  public:
    RSU();
    virtual ~RSU();

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

#endif /* RSU_H_ */
