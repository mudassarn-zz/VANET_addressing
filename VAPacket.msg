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

enum VAType {
	RSU_BEACON = 1; //RSU beacons
	RSU_BEACON_REPLY = 2; //reply to an RSU beacon
	RSU_BASESTATION_FORWARD = 3; //packet forwarding between basestations
	APP_DATA = 4; //vehicle app packets 
}

packet VAPacket {
	int sourcePrefix;
	int sourceSuffix;
	int destPrefix;
	int destSuffix;
	int key; //The key which this packet is 'encrypted' with
	int type enum(VAType);  
}