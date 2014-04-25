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

#ifndef MACHACK_H_
#define MACHACK_H_

#include "Ieee80211Frame_m.h"
#include "MACAddress.h"

#include <omnetpp.h>

/* Thanks to the decision to have the MAC layer in Inet use destination and source
 * MAC addresses in the frames, it has come down to this: manually hacking incoming
 * frames so the MAC doesn't drop them.  */
class MACHack : public cSimpleModule
{
  private:
    // configuration
    const char *address; //sets the MAC address of this RSU
    char spoofedSenderAddress[13]; //the spoofed sender address
    
  public:
    MACHack();
    virtual ~MACHack();

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

#endif /* MACHACK_H_ */
