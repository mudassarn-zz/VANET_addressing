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

//Our VANET Addressing module
//Note that while we target IPv6, due to much
//of INET being IPv4 only, we assume here that
//the prefix+suffix is 32 bits instead of 128 bit.
simple VanetAddressing {
   gates:
       input lowerLayerIn;
       output lowerLayerOut;
       input upperLayerIn;
       output upperLayerOut;
}