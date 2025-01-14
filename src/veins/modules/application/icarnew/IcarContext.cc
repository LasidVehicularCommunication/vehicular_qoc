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
       // this->dataAgentPair
       //          << textDataAgentPair(-1, inic, true) << ";"  << std::endl;
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

         double measuredDistance = this->oKnownGlobal->calcTraciDistanceMobility(pair->getAgentS()->getId(),pair->getAgentD()->getId());
         pair->measureRadius = pair->radiusEstimator->getSignalRange(pair->txReceived_dBm, measuredDistance);

         this->dataAgentPair
                  << textDataAgentPair(this->oKnownGlobal->updatingPairFromReceivedMsg, pair, false) << ";"  << std::endl;
         //std::cout << endl << "finish pair update "<< endl;

     }

     //std::cout << endl << "end updateAgentPairsFromMsg "<< wsm->getSourceNode().nodeId << endl;

}


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
    int auxevent;

    //std::cout << endl << "begin : text Data AgentPair" << std::endl;

        ost << "";
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
                        ";measureDistance"
                        ";measureRadius"<<
                        ";calculatedDistance;distanceDifference;idLocal"<< c->infoTrace(true);
                //std::cout << endl << "begin : head text Data AgentPair" << std::endl;
            }else
            {
                auxevent = event;
                // std::cout << endl << "begin : text Data AgentPair" << std::endl;
                 Move *mobAgentS = this->oKnownGlobal->getTraciMobility(c->getAgentS()->getId());
                 Move *mobAgentD = this->oKnownGlobal->getTraciMobility(c->getAgentD()->getId());
                 double measuredDistance = this->oKnownGlobal->calcTraciDistanceMobility(c->getAgentS()->getId(),c->getAgentD()->getId());
                 double Sx;
                 double Dx;
                 double Sy;
                 double Dy;
                 double Dspeed;
                 double Sspeed;
                 double mesuredRadius = 0;

                 if (mobAgentS==NULL || mobAgentD==NULL )
                 {
                      Sx = 0;
                      Dx = 0;
                      Sy = 0;
                      Dy = 0;
                      Sspeed=0;
                      Dspeed=0;
                 }else{
                     Sx = mobAgentS->getStartPos().x;
                     Dx = mobAgentD->getStartPos().x;
                     Sy = mobAgentS->getStartPos().y;
                     Dy = mobAgentD->getStartPos().y;
                     Sspeed= this->oKnownGlobal->getTraci(c->getAgentS()->getId())->getTraci()->getSpeed();
                     Dspeed= this->oKnownGlobal->getTraci(c->getAgentD()->getId())->getTraci()->getSpeed();
                 }

                 if (event == 1) mesuredRadius = c->radiusEstimator->getSignalRange(c->txReceived_dBm, measuredDistance);

                 if (c->getCalcRadius() < measuredDistance && event==this->oKnownGlobal->updatingPairFromReceivedMsg)
                 {
                     //eventRel.clear();
                     //eventRel << this->oKnownGlobal->OutOfRadiusUpdatingReceivedMsg;
                     auxevent =  this->oKnownGlobal->OutOfRadiusUpdatingReceivedMsg;
                 }
                 else {
                     if (c->getCalcRadius() < measuredDistance
                             &&  c->lastEvent!=this->oKnownGlobal->OutOfRadiusTracingChangedMobility)
                             //&&  event!=this->oKnownGlobal->OutOfRadiusTracingChangedMobility)
                     {

                         //eventRel.clear();
                         c->lastEvent = this->oKnownGlobal->OutOfRadiusTracingChangedMobility;
                         //eventRel << this->oKnownGlobal->OutOfRadiusTracingChangedMobility;
                         auxevent =   this->oKnownGlobal->OutOfRadiusTracingChangedMobility;


                     }/*else{
                         if (this->oKnownGlobal->printUpdateChangedMobility)
                         {
                             eventRel << this->oKnownGlobal->updateTraceChangedMobility;
                         }else     eventRel << event;
                     }*/
                 }
                 ost     << this->oKnownGlobal->oISFilles->observationNameFile
                         //<< ";" << eventRel.str()
                         << ";" << auxevent
                         << ";" << simTime()
                         << ";" << this->oKnownGlobal->vehicleAmout
                         << ";" << this->oKnownGlobal->loadPeriodApp
                         << ";" << this->oIcarModule->loadPeriodMonitor
                         << ";" << Sx
                         << ";" << Sy
                         //<< ";" << mobAgentS->getSpeed()
                         << ";" << Sspeed //this->oKnownGlobal->getTraci(c->getAgentS()->getId())->getTraci()->getSpeed()
                         << ";" << Dx
                         << ";" << Dy
                         //<< ";" << mobAgentD->getSpeed()
                         << ";" << Dspeed //this->oKnownGlobal->getTraci(c->getAgentD()->getId())->getTraci()->getSpeed()
                         << ";" << measuredDistance
                         << ";" << c->measureRadius
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
    this->myData->getLocalCommInfo()->getLocalAgentCommPerformance()->addCorrectMsgRecievedMsg();
    updateAgentPairsFromMsg(wsm, pMsgReceivingTime);
}

}
