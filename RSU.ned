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

// RSU simple module; used in RSUStation
simple RSU {
    parameters:
        int prefix; //The prefix of an IPv6 address.  Also corresponds to a zone ID
        int packetLength = default(50); //length of packets that RSUs send
        double beaconInterval = default(10000.0);  //how long to wait between sending beacons
        @display("i=block/segm");
	gates:
	    input rsuIn;
	    output rsuOut;   
}