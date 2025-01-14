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
   // this->oIcarQoc->dataNetwork << getMsgHeaderInfoTrace( wsm,"", true, 0, 32, -1)<< std::endl;
}

MessageManager::~MessageManager() {
    // TODO Auto-generated destructor stub
}


double MessageManager::getMsgRecvPower_dBm(ICRMessage* m){

    DeciderResult80211 *macRes = dynamic_cast<DeciderResult80211 *>(PhyToMacControlInfo::getDeciderResult(m));
    ASSERT(macRes);
    // TESTE PARA get the mac address  ainda nao resolvido...
    //PhyToMacControlInfo * x = new PhyToMacControlInfo(macRes);
    //cout << endl << "SourceAddress " << x->getSourceAddress() << endl;
    return macRes->getRecvPower_dBm();
}

double MessageManager::getMsgRecvSnr(ICRMessage* m){

    //std::cout << endl << "begin  Returns the signal to noise ratio of the transmission from message "<< endl;

    DeciderResult80211 *macRes = dynamic_cast<DeciderResult80211 *>(PhyToMacControlInfo::getDeciderResult(m));
    ASSERT(macRes);

    //std::cout << endl << "end  Returns the signal to noise ratio of the transmission from message " << macRes->getSnr() << endl;

    return macRes->getSnr();
}

ICRMessage * MessageManager::sendIcarMessageService(int64_t sourceId, int64_t nextId, int64_t destinationId, double timetoLiveApp, unsigned int pMsgType)
{

     ICRMessage * wsm = NULL;
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

     wsm->setTransmissorNode(prepareICRNode(oIcarQoc->oIcarContext->myData));

     if (oIcarQoc->oIcarContext->myData->getId()==sourceId || sourceId==-1){
         wsm->setSourceNode(prepareICRNode(oIcarQoc->oIcarContext->myData));
     }else {
         wsm->setSourceNode(prepareICRNode(oIcarQoc->oIcarContext->agentGroup->getRemoteAgent(sourceId)));
     }

     wsm->setDestinyNode(prepareICRNode(oIcarQoc->oIcarContext->agentGroup->getRemoteAgent(destinationId)));

     wsm->setNextNode(prepareICRNode(oIcarQoc->oIcarContext->agentGroup->getRemoteAgent(nextId)));

     //sendown message
     sendICRMessage(wsm, "transmitting", "msgIcar");
     return(wsm);
}



void MessageManager::sendICRMessage(ICRMessage * wsm, std::string evento, std::string ruleRoute)
{

    int calcRang;
    if ((this->oIcarQoc->oKnownGlobal->maxMsgAmountVehicle >= this->oIcarQoc->seqMsg) )
    {
        calcRang = rand() % 2;
        if ((this->oIcarQoc->oIcarContext->oKnownGlobal->lostMessageRate!=0
                && calcRang ==0
                && (this->oIcarQoc->getLostMsgAmount()
                <= (this->oIcarQoc->oKnownGlobal->lostMessageRate/100)*this->oIcarQoc->oKnownGlobal->maxMsgAmountVehicle)))
        {
            //emulating lost messages using parameter lostMessageRate
            this->oIcarQoc->addLostMsgAmount();
        }else {
            // sending message
            this->oIcarQoc->sendDown( ((cMessage*)(wsm)));
            this->oIcarQoc->dataNetwork  << this->getMsgHeaderInfoTrace( wsm,evento, false, wsm->getTimestamp(), 32, this->oIcarQoc->getMyData()->getId()) << std::endl;
            this->oIcarQoc->oIcarContext->getMyData()->getLocalCommInfo()->getLocalAgentCommPerformance()->addCorrectMsgTransmittedMsg();
        }
        //std::cout  << "this->oIcarQoc->lostMsgAmount = " <<  this->oIcarQoc->lostMsgAmount <<
        //        "oKnownGlobal->maxMsgAmountVehicle= " << this->oIcarQoc->oKnownGlobal->maxMsgAmountVehicle <<
        //        "this->oIcarQoc->seqMsg = " << this->oIcarQoc->seqMsg << endl;
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
                 << ";localNodeID"
                 << ";messageNumber"
                 << ";MsgType"
                 << ";MSG Time"
                 //<< ";delayMSG"
                 << ";MsgLifeTime"
                 << ";hopNumber"
                 << ";ValidityDataTimeStamp";
                 //<< ";Data";
                char typeNode;
                for (int i=0; i < 4; i++)
                {

                    switch(i) {
                      case 0: typeNode = 'S';
                        break;
                      case 1: typeNode = 'T';
                       break;
                      case 2: typeNode = 'N';
                       break;
                      case 3: typeNode = 'D';
                       break;
                    }

                    ost  << ";nodeId_" << typeNode  // source id node - 32bits
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
                //<< ";" << pEventTime - wsm->getTimestamp()
                << ";" << wsm->getMsgLifeTime()
                << ";" << wsm->getHopNumber()
                << ";"<< wsm->getValidityDataTimeStamp()
                //<< ";"<< wsm->getWsmData();
                //<< ";"
                //    << this->oKnownGlobal->calcTraciDistanceMobility(wsm->getRouteNodes(0).nodeId,
                //            wsm->getRouteNodes(wsm->getRouteNodesArraySize()-1).nodeId);
                <<  getMsgHeaderInfoTraceNode(wsm->getSourceNode())
                <<  getMsgHeaderInfoTraceNode(wsm->getTransmissorNode())
                <<  getMsgHeaderInfoTraceNode(wsm->getNextNode())
                <<  getMsgHeaderInfoTraceNode(wsm->getDestinyNode());

    }

    return ost.str();
}

std::string  MessageManager::getMsgHeaderInfoTraceNode(ICRNode  pNode)
{
    std::ostringstream ost;

    ost  << ";" << pNode.nodeId  // source id node - 64bits
    << ";" << pNode.posX  //source x  32bits
    << ";" << pNode.posY // source y 32bits
    << ";" << pNode.posZ // source z - 64bits
    << ";" << pNode.maxSpeed // max speed node - 32 bits
    << ";" << pNode.angle // angulo do agente de origem -  32 bits
    << ";" << pNode.aceleration  // aceleracao do agente de origem -  32 bits
    << ";" << pNode.speed// speed value -  32 bits
    << ";" << pNode.neighber // vizinho do proximo no
    << ";" << pNode.validityTimeToNext // alcance do sinal de comunicacao do agente de origem  - 32 bits
    << ";" << pNode.posTimeStamp // timestamp da da coleta da posicao do agente antecessor
    << ";" << pNode.msgTimeStamp;

    return ost.str();
}

const ICRNode MessageManager::prepareICRNode(Agent * a) {

    ICRNode node;
    node.initializeICRNode();
    if (a!=NULL){
        node.maxSpeed = a->getMobilityInfo()->getMaxSpeed();
        node.angle = a->getMobilityInfo()->getAngle();
        node.aceleration = a->getMobilityInfo()->getAcceleration();
        node.posTimeStamp = a->getMobilityInfo()->getActualMove()->getStartTime().dbl();
        node.speed = a->getMobilityInfo()->getActualMove()->getSpeed();
        node.posX = a->getMobilityInfo()->getActualMove()->getStartPos().x;
        node.posY = a->getMobilityInfo()->getActualMove()->getStartPos().y;
        node.posZ = a->getMobilityInfo()->getActualMove()->getStartPos().z;
        node.msgTimeStamp = simTime().dbl();
        node.nodeId = a->getId();
        node.validityTimeToNext = 0;
    }

    return node;
}

}
