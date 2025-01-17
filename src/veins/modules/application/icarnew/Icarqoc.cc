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

#include "Icarqoc.h"

namespace veins{

Define_Module(Icarqoc);

//Initializing members and pointers of your application goes here
void Icarqoc::initialize(int stage) {
BaseApplLayer::initialize(stage);

   if (stage == 0) {

       //Initializing members and pointers of your application goes here
        EV << "Initializing " << par("appName").stringValue() << std::endl;
       this->seqMsg=0;
       this->lostMsgAmount=0;
       this->tempNode=-1;


       if (FindModule<KnownGlobal*>::findGlobalModule())
       {
           oKnownGlobal = FindModule<KnownGlobal*>::findGlobalModule();

           double maxSpeed;
           if   (oKnownGlobal->knownVehicles.size() % 2 == 0)
                maxSpeed = par("maxSpeedRoute1").doubleValue();
           else maxSpeed = par("maxSpeedRoute0").doubleValue();

           integratedScenario = par("integratedScenario").boolValue();

           //LocalMobility * locality = new LocalMobility(TraCIMobilityAccess().get(getParentModule()), maxSpeed);
           locality = NULL;
           mobility = NULL;
           if (FindModule<TraCIMobility*>::findSubModule(getParentModule())) {
               mobility = TraCIMobilityAccess().get(getParentModule());
               locality = new LocalMobility(mobility, maxSpeed);
               traciComm = mobility->getCommandInterface();
               traciVehicle = mobility->getVehicleCommandInterface();
           }
           //get configuration from physic layer module
           BasePhyLayer * x = FindModule<BasePhyLayer*>::findGlobalModule();
           oKnownGlobal->oRadiusEstimatorAgentPair->sensitivityPower_dbm = x->getAncestorPar("minPowerLevel").doubleValue();

   //    } else exit(-1);
   //}else
        //if (stage == 1){
            int64_t idVeicularAgent = oKnownGlobal->knownVehicles.size();
            //agent name = vehicle creation order
            std::stringstream aName;
            aName << idVeicularAgent;
            this->myData = new LocalAgent(idVeicularAgent, locality, aName.str());

            //cout<<endl << "ID SUMO " << locality->getTraci()->getFullName() << "INDEX SUMO " << locality->getTraci()->getExternal_id();
            //declared radius in meters
            this->myData->setSetRadius(oKnownGlobal->setRadius);

            this->oIcarContext = new IcarContext(this->myData, this->oKnownGlobal, this);
            oMsgManager = new MessageManager(this);


            oKnownGlobal->knownVehicles.push_back(this->oIcarContext->getMyData());

            /*if (oKnownGlobal->knownVehicles.size()==1)
                {
                this->dataMsgTeste << "";
                dataNetwork<<"";
                this->oKnownGlobal->fileLocalAgents << this->myData->infoTrace(true, std::to_string(this->myData->getId())) << endl;
                this->dataMsgTeste  << this->oMsgManager->getMsgHeaderInfoTrace( NULL, "receiving", true, 0, 4, this->myData->getId()) << std::endl;
                oIcarContext->dataCommPerformance << "simulation;timeStamp; localId; " << this->myData->getLocalCommInfo()->getLocalAgentCommPerformance()->infoTrace(true, "") << std::endl;
                AgentPair * tempAgentPair = new AgentPair();
                this->oKnownGlobal->fileChannels << oIcarContext->textDataAgentPair(-1, tempAgentPair, true) << ";"  << std::endl;
                this->oKnownGlobal->fileChannelsMinslr  << ";idLocal" << tempAgentPair->infoTrace(true) << ";" << endl;
                dataNetwork << oMsgManager->getMsgHeaderInfoTrace( NULL,"", true, 0, 0, -1) << std::endl;

                }*/

              //schedule first to measure collect mobility
              if (oKnownGlobal->mobilityPeriod != 0){
                  cMessage *msgCollectMobility = new cMessage("collectMobility", COLLECT_MOBILITY);
                  scheduleLoad(oKnownGlobal->startSimulation, COLLECT_MOBILITY, "firstLoad", msgCollectMobility);
              }else{
                  findHost()->subscribe(BaseMobility::mobilityStateChangedSignal, this);
              }

              // period of communication performance measurement
              perforMesurementPeriod = oKnownGlobal->perforMesurementPeriod;

               //schedule first to measure communication performance
              //cMessage *msgPer = new cMessage("commperform", MEASURE_COMM_PERFORMANCE);
              //scheduleLoad(oKnownGlobal->startSimulation, MEASURE_COMM_PERFORMANCE, "firstLoad", msgPer);

              //schedule first load monitor message
              this->monitorMsg = new cMessage("firstLoad", SEND_MONITOR_EVT);
              this->loadPeriodMonitor = oKnownGlobal->monitorPeriod;
              scheduleAt((simTime().dbl()+oKnownGlobal->startSimulation+loadPeriodMonitor + idVeicularAgent*0.0001), monitorMsg);
              //scheduleLoad(, SEND_MONITOR_EVT, "firstLoad", this->monitorMsg);

              // vehicle amount
              vehicleAmout = oKnownGlobal->vehicleAmout;

              // general type of application
              this->vfs = oKnownGlobal->oGeneralCommunicationService;

              // period to send application messages
              loadPeriodApp = oKnownGlobal->oGeneralCommunicationService.appPeriodLoadMsg;

              //schedule first load application messages
              if (loadPeriodApp>0){
                  cMessage *msg = new cMessage("firstLoad", SEND_ICM_EVT);
                  scheduleAt((simTime().dbl()+oKnownGlobal->startSimulation+loadPeriodApp), msg);
              }

          }else exit(-1);
        }//end(stage == 0)
}



void Icarqoc::handleSelfMsg(cMessage* msg) {
    //BaseWaveApplLayer::handleSelfMsg(msg);
    //this method is for self messages (mostly timers)
    //it is important to call the BaseWaveApplLayer function for BSM and WSM transmission
    //SEND_ICM_EVT, // general event of IC Message
    //SEND/-*--_ICAR_PROTOCOL, //Data dissemination
    //SEND_FORMATION_VEHIC, // vehicular formation
    //SEND_IMAGES_STREAMS // images streams
    //MEASURE_COMM_PERFORMANCE // event to measure the environment communication performance
    //AGENTPAIR_MONITOR_MESSAGE = For each known CHANNEL when need to update communication state (communicatin, non-communicating, fault etc.)


    // verify the simulation time.
    if (simTime().dbl() <= this->oKnownGlobal->finishSimulation)
    {
        switch (msg->getKind())
        {
            case MEASURE_COMM_PERFORMANCE:
            {
                // calc performance measurement
                //if (msg->getName()=="firstLoad") this->oVision->calcCommPerformVision(true);
                //else this->oVision->calcCommPerformVision(false);

                //schedule new performance measurement
                //this->scheduleLoad(this->perforMesurementPeriod, MEASURE_COMM_PERFORMANCE, "commperform", msg);
            }break;

            case AGENTPAIR_MONITOR_MESSAGE:
            {
                AgentPair * c = (AgentPair *)(msg->getContextPointer());
                int64_t s = c->getAgentS()->getId();
                int64_t d = c->getAgentD()->getId();
                //oVision->updateCommunicationState(s,d);
            }break;

            case COLLECT_MOBILITY:
            {
                //std::cout << endl << "begin schedule new  mobility collect "<< endl;

                //schedule new  mobility collect
                if (oKnownGlobal->mobilityPeriod == -1){
                    double  tempx = (double(rand()%100+1)/10)/2.5;
                    this->scheduleLoad(tempx, COLLECT_MOBILITY, "collectMobility", msg);
                    //std::cout << endl << "range Mobility= "<< tempx << endl;
                }

                if (oKnownGlobal->mobilityPeriod >0)
                    this->scheduleLoad(this->oKnownGlobal->mobilityPeriod, COLLECT_MOBILITY, "collectMobility", msg);

                this->changeLocalMobility();

                //std::cout << endl << "end schedule new  mobility collect "<< endl;

            }break;

            case SEND_MONITOR_EVT:
            {
                //std::cout << endl << "begin send monitor message "<< endl;

                //send monitor message
                loadMonitor(msg);

                //std::cout << endl << "end send monitor message "<< endl;

            }break;

            case SEND_ICM_EVT:
            {
                //std::cout << endl << "begin send load Application message "<< endl;
                loadApp(msg);
                this->scheduleLoad(this->loadPeriodApp, SEND_ICM_EVT, "appMessage", msg);
                //std::cout << endl << "end send load Application message "<< endl;

            }break;


           default:
            {
                if (msg)
                    EV << "APP: Error: Got Self Message of unknown kind! Name: " << msg->getName() << endl;
            }break;

        }//end switchcase
    }//endif
}

void Icarqoc::handleLowerMsg(cMessage* msg)
{

    //std::cout << endl << "begin receive network message "<< endl;
    BaseFrame1609_4* icm = dynamic_cast<BaseFrame1609_4 *>(msg);
        ASSERT(icm);

    ICRMessage * wsm=dynamic_cast<ICRMessage*>(icm);
    ASSERT(wsm);

    if (wsm != NULL)
    {
        //std::cout << endl << "begin update Context from message "<< wsm->detailedInfo() << endl;
        this->oIcarContext->updateContextfromMsg(wsm, simTime());
        //Nao e o local adequado
        //if (verifyRuleRadiusSet(wsm)) this->oIcarContext->updateContextfromMsg(wsm, simTime());

        this->oKnownGlobal->oISFilles->dataMsgReceived  << this->oMsgManager->getMsgHeaderInfoTrace( wsm, "receiving", false, wsm->getTimestamp(), 4, this->myData->getId()) << std::endl;

        cancelAndDelete(wsm);
    } else {
        std::cout << " msg e null" << std::endl;
    }

    //std::cout << endl << "end receive network message "<< endl;

}


void Icarqoc::changeLocalMobility(){
        this->oIcarContext->changeLocalMobility();
}

/*****************************************************************************************************************************************************
 * APPLICATION LOAD IN NETWORK
 ****************************************************************************************************************************************************/

void Icarqoc::loadApp(cMessage *msg)
{
    //int64_t destinyNode;

    //ForwardingNode * foward = new ForwardingNode();

    oMsgManager->sendIcarMessageService(-1, -1, -1, vfs.timeToLive, msg->getKind());

    this->scheduleLoad(this->loadPeriodMonitor, SEND_MONITOR_EVT, "monitorMessage", this->monitorMsg);
}


void Icarqoc::loadMonitor(cMessage *msg)
{
    //int64_t destinyNode=-1;
    if (msg->getKind()==SEND_MONITOR_EVT)
    {
        //ForwardingNode * foward = new ForwardingNode();

        oMsgManager->sendIcarMessageService(-1, -1, -1, vfs.timeToLive, msg->getKind());

        if (this->oKnownGlobal->monitorPeriod == 0)
        {
            this->loadPeriodMonitor = (1.5 * (double(rand()%100)+1)/100) + 0.5;
        }

        this->scheduleLoad(this->loadPeriodMonitor, SEND_MONITOR_EVT, "monitorMessage", this->monitorMsg);
    }
}

void Icarqoc::scheduleLoad(double appPeriod, int AppTypeId, string name, cMessage *m1)
{
    if (m1->isScheduled())
        cancelEvent(m1);

    m1->setName(name.c_str());
    m1->setKind(AppTypeId);

    simtime_t s = ((simtime_t) (simTime().dbl() + appPeriod));

    scheduleAt(s, m1);
}

void Icarqoc::scheduleLoadMobility()
{
    if (this->msgCollectMobility->isScheduled())
        cancelEvent(msgCollectMobility);

    msgCollectMobility->setName("collectMobility");
    msgCollectMobility->setKind(COLLECT_MOBILITY);

    simtime_t s = ((simtime_t) (simTime().dbl() + this->oKnownGlobal->mobilityPeriod));

    scheduleAt(s, msgCollectMobility);
}

/*
 * Calculating delay to send application load message
 */
double Icarqoc::calcDelaySendLoadApp()
{
    return ((double(rand()%10)+1)/100);
}

/*
 * when the radius of a node has a value on configuration (for example radiusSet=250m)
 */
bool Icarqoc::verifyRuleRadiusSet( ICRMessage  *wsm){
    // when the radius of a node has a value on configuration (for example radiusSet=250m)
    double measuredDistance =0;
    measuredDistance = this->oIcarContext->oKnownGlobal->calcTraciDistanceMobility(wsm->getTransmissorNode().nodeId, this->oIcarContext->myData->getId());

    if (measuredDistance <= this->oIcarContext->myData->getSetRadius() && this->oIcarContext->myData->getSetRadius()>0)
        return true;
    else
    {
        if (this->oIcarContext->myData->getSetRadius()<=0) return true;
        else return false;
    }

}

void Icarqoc::sendDown(cMessage* msg)
{
    BaseApplLayer::sendDown(msg);
}

/*
 *  @brief send application message
 *  @param forwarding node
 *  @param  destiny node
 *  @param  message time (time to leave)
 *  @param  message type (see enum in baseapp)
 *  @param  last node forwarding node
 *  @param  number of monitoring message)
 */
void Icarqoc::receiveSignal(cComponent* source, simsignal_t signalID, cObject* obj, cObject* details)
{
    Enter_Method_Silent();
    if (signalID == BaseMobility::mobilityStateChangedSignal) {
        if (oKnownGlobal->mobilityPeriod == 0) this->changeLocalMobility();
    }

}



void Icarqoc::sendForwardMessage(ICMessage* pWsm)
{


}


void Icarqoc::finish() {
    cancelAndDelete(monitorMsg);

    fstream pairCommVeic = this->oKnownGlobal->oISFilles->createVehicleTraces(myData->getId(), "AgentPair.csv");
    pairCommVeic << this->oKnownGlobal->oISFilles->oSimFilesHeader.headerAgentPairComplete()<< endl << oIcarContext->dataAgentPair.str();

    //oVision->dataCommPerformance.clear();
    oIcarContext->dataCommPerformance << oKnownGlobal->oISFilles->observationNameFile << ";" << simTime()<<";" << this->myData->getId()<< ";"<< this->myData->getLocalCommInfo()->getLocalAgentCommPerformance()->infoTrace(false, "") << std::endl;
    //oVision->dataMinslr << oVision->getAgentPairList()->infoTraceAgentPairList();
    this->oKnownGlobal->oISFilles->fileChannelsMinslr << ";" << myData->getId() <<  oIcarContext->getAgentPairList()->infoTraceAgentPairList();
    this->oKnownGlobal->knownVehicles.at(myData->getId())=NULL;
    this->oKnownGlobal->oISFilles->fileMessages << dataNetwork.str();
    this->oKnownGlobal->oISFilles->fileChannels << oIcarContext->dataAgentPair.str();
    this->oKnownGlobal->oISFilles->fileRemoteAgents << oIcarContext->dataRemoteAgent.str();
    this->oKnownGlobal->oISFilles->fileLocalAgents << this->myData->infoTrace(false, std::to_string(this->myData->getId())) << endl;
    this->oKnownGlobal->oISFilles->fileCommPerformance << oIcarContext->dataCommPerformance.str();
    this->oKnownGlobal->oISFilles->fileReceivedMessages << this->oKnownGlobal->oISFilles->dataMsgReceived.str();
}


LocalAgent* Icarqoc::getMyData(){
    return myData;
}

void Icarqoc::setMyData(LocalAgent* myData) {
    this->myData = myData;
}

void Icarqoc::addLostMsgAmount() {
    ++lostMsgAmount;
}

long Icarqoc::getLostMsgAmount() {
    return this->lostMsgAmount;
}

}




//initialize trace

// dataMsgTeste << ";amoutVehicle;loadPeriodApp;"
//                   << msgInfoTraceTransmitting(NULL, "", "", true, 0) << std::endl;

// if (oKnownGlobal->simulationDataheaderLine)
//      dataNetwork << ";vehicleAmout;loadPeriodApp;" <<  msgInfoTraceTransmitting(NULL, "", "", true, 0)<< std::endl;
//else dataNetwork << "";

// get handle to phy layer
// BaseMacLayer * macx= dynamic_cast<BaseMacLayer*>  (FindModule<Mac1609_4*>::findSubModule(getParentModule()));
// ASSERT(macx);
//DeciderResult80211 *macRes = dynamic_cast<DeciderResult80211 *>(PhyToMacControlInfo::getDeciderResult(m));
// ASSERT(macRes);
// if ((mac = FindModule<BaseMacLayer*>::findSubModule(getParentModule())) == nullptr) {
//     throw cRuntimeError("Could not find a PHY module.");
// }


//cout << endl << "myMac " << macx->getMACAddress() << endl;
