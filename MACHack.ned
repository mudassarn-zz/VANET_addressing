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

// hacks airframes so the MAC layer works without having to specify sender/receiver
// MAC addresses
simple MACHack {
    parameters:
        string address; //must match the MAC address of the host.  Easiest to simply set all hosts to the same MAC address.
        @display("i=vanet/troll");
    gates:
        input hackedIn;
        output hackedOut;
}