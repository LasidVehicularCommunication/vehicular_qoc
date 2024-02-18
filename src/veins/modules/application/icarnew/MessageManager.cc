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

#include <veins/modules/application/icarnew/MessageManager.h>

namespace veins{

MessageManager::MessageManager() {
    // TODO Auto-generated constructor stub

}
MessageManager::MessageManager(Icarqoc * pIcarQoc){
    this->oIcarQoc = pIcarQoc;
    this->oIcarQoc->dataNetwork << getMsgHeaderInfoTrace( wsm,"", true, 0, 32, -1)<< std::endl;
}

MessageManager::~MessageManager() {
    // TODO Auto-generated destructor stub
}


double MessageManager::getMsgRecvPower_dBm(ICRMessage* m){

    DeciderResult80211 *macRes = dynamic_cast<DeciderResult80211 *>(PhyToMacControlInfo::getDeciderResult(m));
    ASSERT(macRes);

    return macRes->getRecvPower_dBm();
}

double MessageManager::getMsgRecvSnr(ICRMessage* m){

    DeciderResult80211 *macRes = dynamic_cast<DeciderResult80211 *>(PhyToMacControlInfo::getDeciderResult(m));
    ASSERT(macRes);

    return macRes->getSnr();
}

ICRMessage* MessageManager::sendIcarMessageService(ForwardingNode* pfowardNode,
        int64_t destination, double timetoLiveApp, unsigned int pMsgType) {

    ICRMessage * wsm = NULL;

    ForwardingNode * fowardNode=NULL;

    if (destination != -1)
    fowardNode = oIcarQoc->oIcarContext->getRouting()->getFowardNode(destination, oIcarQoc->oIcarContext->getMyData()->getId(), -1, timetoLiveApp, Coord(0,0,0), Coord(0,0,0));

    if (simTime()< this->oIcarQoc->oIcarContext->oKnownGlobal->finishSimulation)
    {
        int sizeNodeICRM=1;

        //preparing transmition wsm message
            wsm = new ICRMessage();

            //prepareing icmessage
            wsm->setMsgType(pMsgType);
            wsm->setNumMsg(++this->oIcarQoc->seqMsg);
            wsm->setName("data");

            //User priority with which this packet was sent (note the AC mapping rules in Mac1609_4::mapUserPriority)
            wsm->setUserPriority(7);
            //Unique number to identify the service
            wsm->setPsid(-1);

            //populateWSM(wsm);
            wsm->setKind(pMsgType);

            //Channel Number on which this packet was sent
            wsm->setChannelNumber(static_cast<int>(Channel::cch));

            wsm->setMsgLifeTime(simTime() + timetoLiveApp);
            wsm->setTimestamp(simTime());
            wsm->setHopNumber(1);

            // agent next data
            RemoteAgent * fowardAgent = NULL;

           if (fowardNode!= NULL)
           {
               if (fowardNode->getFowardId() != -1)
               {
                   fowardAgent = oIcarQoc->oIcarContext->agentGroup->getRemoteAgent(fowardNode->getFowardId());
                   if (fowardAgent != NULL)
                   {
                       sizeNodeICRM++;
                   }
               }
           }


           RemoteAgent * destinyNode=NULL;
           if (destination!=-1){
               destinyNode = oIcarQoc->oIcarContext->agentGroup->getRemoteAgent(destination);
               if (destinyNode!=NULL)
                   if (destinyNode->getId()!=-1)
                   {
                      sizeNodeICRM++;
                   }
           }


            wsm->setRouteNodeArraySize(sizeNodeICRM);

            //ICRMessage icrMessage;
            //ICRNode nodeCopy = icrMessage.getRouteNode(0); // Faz uma cópia do objeto retornado
            //nodeCopy.prepareICRNode(oIcarQoc->oIcarContext->myData); // Chama a função na cópia modificada

            ICRNode nodeCopy = wsm->getRouteNode(0); // Faz uma cópia do objeto retornado
            nodeCopy.prepareICRNode(oIcarQoc->oIcarContext->myData); // Chama a função na cópia modificada

            //wsm->getRouteNode(0).prepareICRNode(oIcarQoc->oIcarContext->myData);

            // forwarding data
            std::string ruleRouting = "-1";
            if (fowardNode!= NULL)
            {
                if (fowardNode->getFowardId() != -1)
                {
                    ruleRouting = fowardNode->getRule();
                    //Adicionado
                    ICRNode nodeCopy2 = wsm->getRouteNode(1); // Faz uma cópia do objeto retornado para o índice 1
                    nodeCopy2.prepareICRNode(fowardAgent); // Chama a função na cópia modificada
                    //Até aqui
                    //wsm->getRouteNode(1).prepareICRNode(fowardAgent);
                    ruleRouting = fowardNode->getRule();
                }
            }


            if (destinyNode!=NULL){
                if (destinyNode->getId()!=-1)
                {
                    //Adicionado
                    ICRNode nodeCopy3 = wsm->getRouteNode(sizeNodeICRM-1); // Faz uma cópia do objeto retornado para o índice sizeNodeICRM-1
                    nodeCopy3.prepareICRNode(destinyNode); // Chama a função na cópia modificada
                    //wsm->getRouteNode(sizeNodeICRM-1).prepareICRNode(destinyNode);
                    //até aqui
                }
            }

            sendICRMessage(wsm, "transmitting", ruleRouting ,false);

    }

        return (wsm);

}



void MessageManager::sendICRMessage(ICRMessage * wsm, std::string evento, std::string ruleRoute, bool header)
{

    int calcRang = rand() % 2;
    if ((this->oIcarQoc->oIcarContext->oKnownGlobal->lostMessageRate!=0
            && calcRang ==0
            && (this->oIcarQoc->getLostMsgAmount()
            <= (this->oIcarQoc->oKnownGlobal->lostMessageRate/100)*this->oIcarQoc->oKnownGlobal->maxMsgAmountVehicle)))
    {
        //emulating lost messages using parameter lostMessageRate
        this->oIcarQoc->addLostMsgAmount();

    }else {
        // sending message
        this->oIcarQoc->dataNetwork  << this->getMsgHeaderInfoTrace( wsm,evento, header, wsm->getTimestamp(), 32, this->oIcarQoc->getMyData()->getId()) << std::endl;
        this->oIcarQoc->sendDown( ((cMessage*)(wsm)));
        this->oIcarQoc->oIcarContext->getMyData()->getLocalCommInfo()->getLocalAgentCommPerformance()->addCorrectMsgTransmittedMsg();
    }

}


std::string MessageManager::getMsgHeaderInfoTrace(ICRMessage * wsm, std::string evento,
        bool header, simtime_t pEventTime, int maxNumberHop, int myDataID)
{
   // std::cout << endl << "getMsgHeaderInfoTrace" << "   timeX= " << simTime().dbl();

    std::ostringstream ost;
    if (header){
        ost      << ";event"
                 << ";eventTime"
                 << ";transmitterNodeID"
                 << ";messageNumber"
                 << ";MsgType"
                 << ";MSG Time"
                 << ";delayMSG"
                 << ";MsgLifeTime"
                 << ";hopNumber"
                 << ";ValidityDataTimeStamp"
                 << ";Data";

                for (int i=0; i < maxNumberHop; i++)
                {
                    ost  << ";nodeId_" << i  // source id node - 32bits
                    << ";posX"  //source x - 32 bits
                    << ";posY" // source y - 32 bits
                    << ";posZ" // source z - 32 bits
                    << ";maxSpeed" // max speed node - 32 bits
                    << ";angle" // angulo do agente de origem -  32 bits
                    << ";aceleration"  // aceleracao do agente de origem -  32 bits
                    << ";speed"// speed value -  32 bits
                    << ";neighber" // vizinho do proximo no
                    << ";validityTimeToNext" // alcance do sinal de comunicacao do agente de origem  - 32 bits
                    << ";posTimeStamp" // timestamp da da coleta da posicao do agente antecessor
                    << ";msgTimeStamp";
                }

    } else {
        ost     << ";" << evento
                << ";" << pEventTime
                << ";" << myDataID
                << ";" << wsm->getNumMsg()
                 << ";" << wsm->getMsgType()
                << ";" << wsm->getTimestamp()
                << ";" << pEventTime - wsm->getTimestamp()
                << ";" << wsm->getMsgLifeTime()
                << ";" << wsm->getHopNumber()
                << ";"<< wsm->getValidityDataTimeStamp();
                //<< ";"<< wsm->getWsmData();
                //<< ";"
                //    << this->oKnownGlobal->calcTraciDistanceMobility(wsm->getRouteNodes(0).nodeId,
                //            wsm->getRouteNodes(wsm->getRouteNodesArraySize()-1).nodeId);

                for (int i=0; i < wsm->getRouteNodeArraySize(); i++)
                {
                    ost  << ";" << wsm->getRouteNode(i).nodeId  // source id node - 32bits
                    << ";" << wsm->getRouteNode(i).posX  //source x - 32 bits
                    << ";" << wsm->getRouteNode(i).posY // source y - 32 bits
                    << ";" << wsm->getRouteNode(i).posZ // source z - 32 bits
                    << ";" << wsm->getRouteNode(i).maxSpeed // max speed node - 32 bits
                    << ";" << wsm->getRouteNode(i).angle // angulo do agente de origem -  32 bits
                    << ";" << wsm->getRouteNode(i).aceleration  // aceleracao do agente de origem -  32 bits
                    << ";" << wsm->getRouteNode(i).speed// speed value -  32 bits
                    << ";" << wsm->getRouteNode(i).neighber // vizinho do proximo no
                    << ";" << wsm->getRouteNode(i).validityTimeToNext // alcance do sinal de comunicacao do agente de origem  - 32 bits
                    << ";" << wsm->getRouteNode(i).posTimeStamp // timestamp da da coleta da posicao do agente antecessor
                    << ";" << wsm->getRouteNode(i).msgTimeStamp;
                }
    }

             return ost.str();
}
}
