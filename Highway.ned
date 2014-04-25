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

package inet.examples.cmu.vanet.addressing;
import inet.world.radio.ChannelControl;

network Highway
{
    parameters:
        int numVehicles = default(2); //number of vehicles on the highway
        int numMalicious = default(0); //number of malicious vehicles on the highway
        int numRSUs = default(1); //number of RSUs along the highway
    submodules:
        vehicle[numVehicles]: VehicleModule {
            @display("p=196,163");
        }
        malicious[numMalicious]: VehicleMalicious { //vectore of malicious vehicles on the highway
            @display("p=150,334");
        }
        rsu[numRSUs]: RSUStation { //vector of RSUs along the highway

            @display("p=69,72");
        }
        //manages wireless connections (must be named channelControl)
        channelControl: ChannelControl {
            parameters:
                pMax = default(301mW);
                @display("p=196,53;i=misc/sun");
        }
    connections allowunconnected:
}
