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

//The CCU of a vehicle.  Provides the addressing
//from our protocol
simple VehicleApp {
    parameters:
        bool malicious;
        
        int packetLength = default(50); //length of packets that RSUs send
        int sendInterval = default(-1); //if given, interval between sending packets
        int suffix;
        
        int destination = default(-1);
        int destinationKey = default(-1);
        int forwardSuffix = default(-1); //if given, a suffix to forward packets too
        int forwardKey = default(-1);
        
        @display("i=block/app");
    gates:
        input appIn;
        output appOut;
}