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

#ifndef SRC_VEINS_MODULES_APPLICATION_ICARNEW_MESSAGEMANAGER_H_
#define SRC_VEINS_MODULES_APPLICATION_ICARNEW_MESSAGEMANAGER_H_

#include <omnetpp.h>
#include <veins/modules/application/icarnew/AgentPair.h>
#include <veins/modules/application/icarnew/AgentPairList.h>
#include <veins/modules/application/icarnew/GeneralCommunicationService.h>
#include "messages/ICRMessage_m.h"
#include <vector>
#include "Agent.h"
#include "RemoteAgent.h"
#include "LocalAgent.h"
#include "LocalMobilityTraci.h"
#include "RemoteAgentGroup.h"
#include "../../mobility/traci/TraCIMobility.h"
#include "Routing.h"
#include "KnownGlobal.h"
#include "veins/base/phyLayer/PhyToMacControlInfo.h"
#include "veins/modules/phy/DeciderResult80211.h"
//#include "veins/modules/messages/WaveShortMessage_m.h"
#include "veins/modules/application/icarnew/messages/ICRNode.h"
#include "Icarqoc.h"
#include "ICarRoute.h"
#include "IcarContext.h"


namespace veins{


class Icarqoc;
class MessageManager {
public:
    MessageManager();

    MessageManager(Icarqoc * pIcarQoc);

    virtual ~MessageManager();
    std::string getMsgHeaderInfoTrace(ICRMessage * wsm, std::string evento,
            bool header, simtime_t pEventTime, int maxNumberHop, int myDataID);
    // message from network
    ICRMessage * wsm;
    Icarqoc * oIcarQoc;
    vector<Agent *> agentRoute;
    void sendICRMessage(ICRMessage * wsm, std::string evento, std::string ruleRoute);

    double getMsgRecvSnr(ICRMessage* m);
    double getMsgRecvPower_dBm(ICRMessage* m);

    //ICRMessage * sendIcarMessageService(ForwardingNode* fowardNode, int64_t destination, double timetoLiveApp, unsigned int pMsgType);
    std::string  getMsgHeaderInfoTraceNode(ICRNode pNode);
    ICRMessage * sendIcarMessageService(int64_t sourceId, int64_t nextId, int64_t destination, double timetoLiveApp, unsigned int pMsgType);
    const ICRNode prepareICRNode(Agent * a);

};
}
#endif /* SRC_VEINS_MODULES_APPLICATION_ICARNEW_MESSAGEMANAGER_H_ */
