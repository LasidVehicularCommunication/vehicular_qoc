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

#include <veins/modules/application/icarnew/KnownGlobal.h>

namespace veins{


Define_Module(KnownGlobal);

void KnownGlobal::initialize()
{
    // TODO - Generated method body

}

void KnownGlobal::initialize(int stage) {
    if (stage == 0) {

       //Initializing members and pointers of your application goes here
       EV << "Initializing " << "Known Global " << std::endl;

       // when begin to send messages in the simulation
       this->startSimulation = par("startSimulation").doubleValue();

       // when end the sending messages during the simulation
       this->finishSimulation = par("endSimulation").doubleValue();

       // period de medicao do desempeno da comunicacao do agente CommPerformance
       this->perforMesurementPeriod = par("perforMesurementPeriod").doubleValue();

       // periodo de monitoramento -- beacon msg
       this->monitorPeriod= par("monitorPeriod").doubleValue();

       this->mobilityPeriod = par("mobilityPeriod").doubleValue();

       if (monitorPeriod!=0)
           this->maxMsgAmountVehicle = (finishSimulation - startSimulation)/ monitorPeriod;
       else this->maxMsgAmountVehicle = (finishSimulation - startSimulation)/0.5;
            //TEMPORARIO => ATENCAO DEVE VARIAR DE ACORDO AO INTERVALO RANDOMICO PARA DISTRIBUICAO DE PERIODO
            //              MEDIDO AO MENOR PERÍODO DO INTERVALO ALEATORIOS NO ENVIO DA MENSAGEM...

       //std::cout << endl<< "maxMsgAmountVehicle= " << maxMsgAmountVehicle;
       // vehicle amount

       //rate of lost message
       this->lostMessageRate=par("lostMessageRate").doubleValue();

       this->vehicleAmout = par("vehicleAmount");

       this->simulationDataheaderLine = par("simulationDataheaderLine").boolValue();

       this->setRadius = par("radiusSet").doubleValue();

       // gravar a atualizacao do contexto quando a mobilidade eh alterada em cada veiculo
       this->printUpdateChangedMobility = par("traceChangedMobility").boolValue();

        // period to send application messages
       this->loadPeriodApp = par("loadPeriodApp").doubleValue();

       this->oGeneralCommunicationService.appPeriodLoadMsg =   this->loadPeriodApp;

       //  code of application type
       this->oGeneralCommunicationService.appTypeId = par("appTypeId").intValue();

       // tolerated delay of application
       this->oGeneralCommunicationService.deliveryDelay = par("deliveryDelay").doubleValue();

       // application message time in the network
       this->oGeneralCommunicationService.timeToLive =  par("timeToLive").doubleValue();


       this->knownVehicles.clear();

       // the estimator of channel radius
       this->oRadiusEstimatorAgentPair = new RadiusEstimatorAgentPair(this->setRadius);


       oISFilles = new SimulationFiles(this->vehicleAmout, this->lostMessageRate, this->loadPeriodApp,
                this->mobilityPeriod, this->monitorPeriod,this->setRadius);

       //// Files data simulation
       oISFilles ->observationNameFile = par("observation").stdstringValue();

       oISFilles->oFilesDirectory = par("filesDirectory").stdstringValue();

       // creating trace files
       this->oISFilles->createGlobalTraces(-1);


    }
}

/*
 *
 */
double KnownGlobal::calcTraciDistanceMobility(int64_t vehicle1id, int64_t vehicle2id )
{

    double calDistance=0;

    LocalAgent * agent1= this->knownVehicles.at(vehicle1id);
    LocalAgent * agent2= this->knownVehicles.at(vehicle2id);

    /* if (agent1!=NULL &&  agent2!=NULL)
        if (agent1->getLocalMobility()->getMove()!=NULL && agent2->getLocalMobility()->getMove()!=NULL)
        {
            calDistance = agent1->getMobilityInfo()->calcEuclideanDistancelr(
                    agent1->getLocalMobility()->getMove()->getStartPos(),
                    agent2->getLocalMobility()->getMove()->getStartPos());
        }
*/
   if (agent1!=NULL &&  agent2!=NULL)
       if (agent1->getLocalMobility()->getTraci()->getMove()!=NULL && agent2->getLocalMobility()->getTraci()->getMove()!=NULL)
              {
                  calDistance = agent1->getMobilityInfo()->calcEuclideanDistancelr(
                          agent1->getLocalMobility()->getTraci()->getMove()->getStartPos(),
                          agent2->getLocalMobility()->getTraci()->getMove()->getStartPos());
              }


    return calDistance;
}

Move * KnownGlobal::getTraciMobility(int64_t vehicle1id)
{

    Move * agentTraciPosition=NULL;

    LocalAgent * agent1= this->knownVehicles.at(vehicle1id);

    if (agent1!=NULL)
        if (agent1->getLocalMobility()->getTraci()->getMove()!=NULL)
        {
            agentTraciPosition = agent1->getLocalMobility()->getTraci()->getMove();
        }

    return agentTraciPosition;
}


LocalMobility * KnownGlobal::getTraci(int64_t vehicle1id)
{

    LocalMobility * agentTraciPosition=NULL;

    LocalAgent * agent1= this->knownVehicles.at(vehicle1id);

    if (agent1!=NULL)
        if (agent1->getLocalMobility()->getTraci()->getMove()!=NULL)
        {
            agentTraciPosition = agent1->getLocalMobility();
        }

    return agentTraciPosition;
}

int KnownGlobal::getIntNamefromIdAgent(int agentId)
{
    bool find;
    LocalAgent * la;
    unsigned int i=0;
    while (i < this->knownVehicles.size() && !find )
    {
       la= knownVehicles.at(i);

       if (la!=NULL){
           if (la->getId()==agentId)
               find = true;
       }else i++;
    }

    if (find) return i;
    else return -1;
}

std::string KnownGlobal::getStringNamefromIdAgent(int agentId)
{
    bool find;
    LocalAgent * la;
    unsigned int i=0;
    while (i < this->knownVehicles.size() && !find )
    {
       la= knownVehicles.at(i);

       if (la!=NULL){
           if (la->getId()==agentId) find = true;
       } else i++;
    }

    if (find) return la->getAgentName();
    else return "";
}


void KnownGlobal::finish()
{
    // TODO - Generated method body
    //this->createGlobalTraces(-1);
}

void KnownGlobal::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
}

void KnownGlobal::closeFiles(){
}
}

