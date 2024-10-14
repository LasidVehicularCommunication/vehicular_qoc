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

#include <veins/modules/application/icarnew/IcarContext.h>

namespace veins{

IcarContext::IcarContext(LocalAgent * oMyData, KnownGlobal * pKnownGlobal, Icarqoc * pIcar) {
        this->oKnownGlobal = pKnownGlobal;
        this->oIcarModule = pIcar;
        this->agentGroup = new RemoteAgentGroup();
        this->myData = oMyData;
        this->agentPairList = new AgentPairList();
        // data analysec
        AgentPair * inic = new AgentPair();
        this->dataAgentPair
                 << textDataAgentPair(-1, inic, true) << ";"  << std::endl;
        this->routing = new IcarRouting(agentGroup, agentPairList);
}

IcarContext::IcarContext() {
}

IcarContext::~IcarContext() {
    // TODO Auto-generated destructor stub
}

void IcarContext::callFinish() {
}


void IcarContext::updateAgentPairsFromMsg(ICRMessage * wsm, simtime_t pMsgReceivingTime)
{
     //int sizeRouteNodes = wsm->getRouteNodeArraySize();
     ICRNode icrSource, icrDestiny;
     simtime_t  VTofNext;
     Agent * s = NULL;
     Agent * t = NULL;
     Agent * n = NULL;
     Agent * d = NULL;
     AgentPair * pair = NULL;

     //std::cout << endl << "begin updateAgentPairsFromMsg "<< wsm->getSourceNode().nodeId << endl;

     if (wsm->getSourceNode().nodeId != myData->getId())
     {
         s = updateAgentGroup(wsm->getSourceNode(), pMsgReceivingTime);
         pair = agentPairList->updatePairListFromMsg(wsm->getNumMsg(),s,
                 myData, pMsgReceivingTime, wsm->getSourceNode().msgTimeStamp,
                 this->oKnownGlobal->oRadiusEstimatorAgentPair, true,
                   0, 0.00, this->oKnownGlobal->loadPeriodApp,
                   this->oIcarModule->oMsgManager->getMsgRecvPower_dBm(wsm), this->oIcarModule->oMsgManager->getMsgRecvSnr(wsm));


         this->dataAgentPair
                  << textDataAgentPair(this->oKnownGlobal->updatingPairFromReceivedMsg, pair, false) << ";"  << std::endl;
         //std::cout << endl << "finish pair update "<< endl;

     }

     std::cout << endl << "end updateAgentPairsFromMsg "<< wsm->getSourceNode().nodeId << endl;

}
     /*
     //transmitter node and
     if (wsm->getTransmissorNode().nodeId != myData->getId() && wsm->getTransmissorNode().nodeId != wsm->getSourceNode().nodeId
             && wsm->getTransmissorNode().nodeId != -1 )
     {
         t = updateAgentGroup(wsm->getTransmissorNode(), pMsgReceivingTime);
         pair = agentPairList->updatePairListFromMsg(wsm->getNumMsg(),t,
                 myData, pMsgReceivingTime, wsm->getTransmissorNode().msgTimeStamp,
                 this->oKnownGlobal->oRadiusEstimatorAgentPair, true,
                   0, 0.00, this->oKnownGlobal->loadPeriodApp,
                   this->oIcarModule->oMsgManager->getMsgRecvPower_dBm(wsm), this->oIcarModule->oMsgManager->getMsgRecvSnr(wsm));


         pair = agentPairList->updatePairListFromMsg(wsm->getNumMsg(),s,
                 t, pMsgReceivingTime, wsm->getSourceNode().msgTimeStamp,
                 this->oKnownGlobal->oRadiusEstimatorAgentPair, wsm->getSourceNode().neighber,
                   0, 0.00, this->oKnownGlobal->loadPeriodApp,
                   this->oIcarModule->oMsgManager->getMsgRecvPower_dBm(wsm), this->oIcarModule->oMsgManager->getMsgRecvSnr(wsm));
     }



     if (wsm->getNextNode().nodeId != myData->getId() && wsm->getNextNode().nodeId != -1)
     {
         n = updateAgentGroup(wsm->getNextNode(), pMsgReceivingTime);

         if (wsm->getTransmissorNode().nodeId != wsm->getSourceNode().nodeId )
         {
             pair = agentPairList->updatePairListFromMsg(wsm->getNumMsg(),t,
                              n, pMsgReceivingTime, wsm->getTransmissorNode().msgTimeStamp,
                              this->oKnownGlobal->oRadiusEstimatorAgentPair, true,
                                0, 0.00, this->oKnownGlobal->loadPeriodApp,
                                this->oIcarModule->oMsgManager->getMsgRecvPower_dBm(wsm), this->oIcarModule->oMsgManager->getMsgRecvSnr(wsm));
         }else {
             pair = agentPairList->updatePairListFromMsg(wsm->getNumMsg(),s,
                               n, pMsgReceivingTime, wsm->getSourceNode().msgTimeStamp,
                               this->oKnownGlobal->oRadiusEstimatorAgentPair, wsm->getSourceNode().neighber,
                                 0, 0.00, this->oKnownGlobal->loadPeriodApp,
                                 this->oIcarModule->oMsgManager->getMsgRecvPower_dBm(wsm), this->oIcarModule->oMsgManager->getMsgRecvSnr(wsm));
         }
     }

     if (wsm->getDestinyNode().nodeId != myData->getId() && wsm->getDestinyNode().nodeId != -1){
         d = updateAgentGroup(wsm->getDestinyNode(), pMsgReceivingTime);
      }
    }


    /* iCarAgentsRoute.push_back(s);

     // Verify if the message is only a broadcast -- the first node is the source node
     std::cout << endl << "begin : Verify if the message is only a broadcast -- the first node is the source node" << std::endl;
     std::cout << endl << wsm->getDisplayString() << std::endl;
     if (sizeRouteNodes==1)
     {
         AgentPair * pair = agentPairList->updatePairListFromMsg(wsm->getNumMsg(),s,
                 myData, pMsgReceivingTime, wsm->getRouteNode(0).msgTimeStamp,
                 this->oKnownGlobal->oRadiusEstimatorAgentPair, 1,
                   0, 0.00, this->oKnownGlobal->loadPeriodApp,
                   this->oIcarModule->oMsgManager->getMsgRecvPower_dBm(wsm), this->oIcarModule->oMsgManager->getMsgRecvSnr(wsm));

         std::cout << endl << "NOT end : Verify if the message is only a broadcast -- the first node is the source node" << std::endl;

         this->dataAgentPair
                  << textDataAgentPair(this->oKnownGlobal->updatingPairFromReceivedMsg, pair, false) << ";"  << std::endl;

         std::cout << endl << "end : Verify if the message is only a broadcast -- the first node is the source node" << std::endl;

     }


     //int cont =
     for (int i = 0; i <= (sizeRouteNodes-2); i++)
     {
         int j=i+1;

         if (j<=sizeRouteNodes-1){
             icrSource = wsm->getRouteNode(i);
             icrDestiny = wsm->getRouteNode(j);
             VTofNext = icrSource.validityTimeToNext;

             if (icrDestiny.nodeId != myData->getId())
                d = updateAgentGroup(icrDestiny, pMsgReceivingTime);
             else d = myData;

             iCarAgentsRoute.push_back(d);

             AgentPair * pair = agentPairList->updatePairListFromMsg(wsm->getNumMsg(),iCarAgentsRoute.at(i),
                     iCarAgentsRoute.at(j), pMsgReceivingTime, icrSource.msgTimeStamp,
                     this->oKnownGlobal->oRadiusEstimatorAgentPair, icrSource.neighber,
                       0, icrSource.validityTimeToNext, this->oKnownGlobal->loadPeriodApp,
                       this->oIcarModule->oMsgManager->getMsgRecvPower_dBm(wsm), this->oIcarModule->oMsgManager->getMsgRecvSnr(wsm));

             this->dataAgentPair
                      << textDataAgentPair(this->oKnownGlobal->updatingPairFromReceivedMsg, pair, false) << ";"  << std::endl;

             pairsRoute.push_back(pair);

           if (j==sizeRouteNodes-1 && sizeRouteNodes >2)
             {
                 AgentPair * pair = agentPairList->updatePairListFromMsg(wsm->getNumMsg(),iCarAgentsRoute.at(i),
                         myData, pMsgReceivingTime, icrSource.msgTimeStamp,
                         this->oKnownGlobal->oRadiusEstimatorAgentPair, 1,
                           0, 0.00, this->oKnownGlobal->loadPeriodApp,
                           this->oIcarModule->oMsgManager->getMsgRecvPower_dBm(wsm), this->oIcarModule->oMsgManager->getMsgRecvSnr(wsm));

                 this->dataAgentPair
                          << textDataAgentPair(this->oKnownGlobal->updatingPairFromReceivedMsg, pair, false) << ";"  << std::endl;

             }

         }
     }

     for(unsigned int i = 0; i < (sizeRouteNodes-1); i++){
         icrSource = wsm->getRouteNode(i);
         VTofNext = icrSource.validityTimeToNext;

         vector<AgentPair *> pairsRouteNow;
         for (unsigned int j = i+2; j <= (sizeRouteNodes-1); j++)
         {

             icrDestiny = wsm->getRouteNode(j);

             //////////
             pairsRouteNow.assign(pairsRoute.begin()+i, (pairsRoute.begin()+j-1));
             ICarRoute * pairRoute = new ICarRoute(wsm, pMsgReceivingTime, VTofNext, pairsRouteNow);
             //ICarRoute * pairRoute = new ICarRoute();
             /////////

             AgentPair * pair = agentPairList->updatePairListFromMsg(wsm->getNumMsg(),
                     iCarAgentsRoute.at(i), iCarAgentsRoute.at(j), pMsgReceivingTime,
                     icrSource.msgTimeStamp,  this->oKnownGlobal->oRadiusEstimatorAgentPair,
                     0,0, VTofNext, this->oKnownGlobal->loadPeriodApp,
                     this->oIcarModule->oMsgManager->getMsgRecvPower_dBm(wsm), this->oIcarModule->oMsgManager->getMsgRecvSnr(wsm));

             this->dataAgentPair
                      << textDataAgentPair(this->oKnownGlobal->updatingPairFromReceivedMsg, pair, false) << ";"  << std::endl;

             pair->pairRoutes.push_back(pairRoute);

             if (j==sizeRouteNodes-1)
               {
                   AgentPair * pair = agentPairList->updatePairListFromMsg(wsm->getNumMsg(),iCarAgentsRoute.at(i),
                           myData, pMsgReceivingTime, icrSource.msgTimeStamp,
                           this->oKnownGlobal->oRadiusEstimatorAgentPair, 0,
                             0, VTofNext, this->oKnownGlobal->loadPeriodApp,
                             this->oIcarModule->oMsgManager->getMsgRecvPower_dBm(wsm), this->oIcarModule->oMsgManager->getMsgRecvSnr(wsm));

                   this->dataAgentPair
                            << textDataAgentPair(this->oKnownGlobal->updatingPairFromReceivedMsg, pair, false) << ";"  << std::endl;

                   pair->pairRoutes.push_back(pairRoute);
               }

             if (VTofNext > icrDestiny.validityTimeToNext && icrDestiny.validityTimeToNext >0)
                 VTofNext = icrDestiny.validityTimeToNext;
         }
     }
}*/

void IcarContext::changeLocalMobility(){
    if (!this->getMyData()->getLocalMobility()->getTraci()->isTerminated())
    {
        //update the data mobility of local agent
        this->getMyData()->getLocalMobility()->updateLocalMobilityPos();

        //update the data mobility of involved agent pairs
        this->updateAgentPairs(this->myData,this->myData->getMobilityInfo()->getActualMove()->getStartTime(), 5);
    }
}

void IcarContext::updateAgentPairs(Agent * agent, simtime_t timeStampData,int event){
    AgentPair *c=NULL;
    //double oldValidity=0;

    unsigned int index = 0;

        while (this->getAgentPairList()->agentPairs.size()> index)
        {
            c = dynamic_cast<AgentPair*>(this->getAgentPairList()->agentPairs[index]);

            if (c->getAgentD()->getId() == agent->getId() || c->getAgentS()->getId()== agent->getId())
            {
                //oldValidity =c->getQoCChannel()->getTimeliness()->getValidityNow();

                // if the channel is not fault
                if(c->getCommnunicationState()!=CommState::faulty)
                        //&& c->getChannelMobility()->getMovementCurrentTime() <= timeStampData)
                {
                    c->updateAgentPair();
                    this->dataAgentPair
                         << textDataAgentPair(event, c, false)<< ";" << std::endl;// << this->dataMsg  << std::endl;

                }
            }
            ++index;
        }
    }


std::string IcarContext::textDataAgentPair(int event, AgentPair * c, bool header=false){
    std::ostringstream ost, eventRel;

    //std::cout << endl << "begin : text Data AgentPair" << std::endl;

        ost << "";
        eventRel << event;
            if (header){
                ost << "simulation"
                        ";event"
                        ";timeStamp"
                        ";qtVeic"
                        ";periodApp"
                        ";PeriodMonitor"
                        ";measureAgentSX"
                        ";measureAgentSy"
                        ";measureSpeedS"
                        ";measureAgentDX"
                        ";measureAgentDy"
                        ";measurespeedD"
                        ";measureDistance" <<
                        ";calculatedDistance;distanceDifference;idLocal"<< c->infoTrace(true);
                //std::cout << endl << "begin : head text Data AgentPair" << std::endl;
            }else{
               // std::cout << endl << "begin : text Data AgentPair" << std::endl;
             Move *mobAgentS = this->oKnownGlobal->getTraciMobility(c->getAgentS()->getId());
             Move *mobAgentD = this->oKnownGlobal->getTraciMobility(c->getAgentD()->getId());
             double measuredDistance = this->oKnownGlobal->calcTraciDistanceMobility(c->getAgentS()->getId(),c->getAgentD()->getId());

             if (c->getCalcRadius() < measuredDistance && event==this->oKnownGlobal->updatingPairFromReceivedMsg)
             {
                 eventRel.clear();
                 eventRel << this->oKnownGlobal->OutOfRadiusUpdatingReceivedMsg;

             }
             else {
                 if (c->getCalcRadius() < measuredDistance
                         &&  c->lastEvent!=this->oKnownGlobal->OutOfRadiusTracingChangedMobility)
                 {

                     eventRel.clear();
                     c->lastEvent = this->oKnownGlobal->OutOfRadiusTracingChangedMobility;
                     eventRel << this->oKnownGlobal->OutOfRadiusTracingChangedMobility;

                 }/*else{
                     if (this->oKnownGlobal->printUpdateChangedMobility)
                     {
                         eventRel << this->oKnownGlobal->updateTraceChangedMobility;
                     }else     eventRel << event;
                 }*/
             }
             ost     << this->oKnownGlobal->observationNameFile
                     << ";" << eventRel.str()
                     << ";" << simTime()
                     << ";" << this->oKnownGlobal->vehicleAmout
                     << ";" << this->oKnownGlobal->loadPeriodApp
                     << ";" << this->oIcarModule->loadPeriodMonitor
                     << ";" << mobAgentS->getStartPos().x
                     << ";" << mobAgentS->getStartPos().y
                     << ";" << mobAgentS->getSpeed()
                     << ";" << mobAgentD->getStartPos().x
                     << ";" << mobAgentD->getStartPos().y
                     << ";" << mobAgentD->getSpeed()
                     << ";" << measuredDistance
                     << ";" << c->getAgentPairMobility()->getDistancelr()
                     << ";" << measuredDistance - c->getAgentPairMobility()->getDistancelr()
                     << ";" << this->myData->getId()
                     << c->infoTrace(header);
            }

     return ost.str();
}


/*
 * @brief update the list of agents and the group data (group data in construction yet)
 */
RemoteAgent* IcarContext::updateAgentGroup(ICRNode oIcrNode, simtime_t pMsgReceivingTime){

    RemoteAgent* a = NULL;

    if (oIcrNode.nodeId!=-1)
    {
        if (myData->getId()!= oIcrNode.nodeId ){
            a = this->agentGroup->getRemoteAgent(oIcrNode.nodeId);

            if (a == NULL){
                a = new RemoteAgent(pMsgReceivingTime, oIcrNode, 0);

                this->agentGroup->knownRemoteAgents.push_back(a);

            }else
            {
                a->updateRemoteAgent(pMsgReceivingTime, oIcrNode, 0);
            }
        }
    }

    return a;
}

RemoteAgentGroup* IcarContext::getAgentGroup() {
    return agentGroup;
}

void IcarContext::setAgentGroup(RemoteAgentGroup* agentGroup) {
    this->agentGroup = agentGroup;
}

AgentPairList* IcarContext::getAgentPairList() {
    return agentPairList;
}

void IcarContext::setAgentPairList(AgentPairList* agentPairList) {
    this->agentPairList = agentPairList;
}

LocalAgent* IcarContext::getMyData() {
    return myData;
}

void IcarContext::setMyData(LocalAgent* myData) {
    this->myData = myData;
}

Icarqoc* IcarContext::getIcarModule() {
    return oIcarModule;
}

void IcarContext::setIcarModule(Icarqoc* icarModule) {
    oIcarModule = icarModule;
}

KnownGlobal* IcarContext::getKnownGlobal(){
    return oKnownGlobal;
}

void IcarContext::setKnownGlobal( KnownGlobal* knownGlobal) {
    oKnownGlobal = knownGlobal;
}

IcarRouting* IcarContext::getRouting() {
    return routing;
}

void IcarContext::setRouting(IcarRouting* routing) {
    this->routing = routing;
}

GeneralCommunicationService IcarContext::getService() {
    return service;
}

void IcarContext::setService(GeneralCommunicationService service) {
    this->service = service;
}

void IcarContext::updateContextfromMsg(ICRMessage * wsm, simtime_t pMsgReceivingTime){
    updateAgentPairsFromMsg(wsm, pMsgReceivingTime);
}

}
