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

#include <veins/modules/application/icarnew/SimulationFiles.h>

namespace veins{

SimulationFiles::SimulationFiles() {
    // TODO Auto-generated constructor stub

}

SimulationFiles::~SimulationFiles() {
    // TODO Auto-generated destructor stub
}

SimulationFiles::SimulationFiles(int vehicleAmout, float lostMessageRate, float loadPeriodApp,
           float mobilityPeriod, float monitorPeriod,float setRadius){

    // TODO Auto-generated constructor stub
     this->vehicleAmout = vehicleAmout;
     this->lostMessageRate=lostMessageRate;
     this->loadPeriodApp = loadPeriodApp;
     this->mobilityPeriod =mobilityPeriod ;
     this->monitorPeriod = monitorPeriod;
     this->setRadius =setRadius;
}

stringstream SimulationFiles::getFilePreFix(int idVehicle){
    stringstream sufixo;

    //sufixo << par("filesDirectory").stdstringValue() << instantTimeSimulation.str()
    sufixo << this->oFilesDirectory <<  this->observationNameFile;

    if (idVehicle >=0) sufixo << "V" << idVehicle;
    sufixo  << "Amount" << this->vehicleAmout
            << "lostRate" << this->lostMessageRate
            << "AppLoad" << this->loadPeriodApp
            << "MobPeriod" << this->mobilityPeriod
            << "beaconLoad" << this->monitorPeriod
            << "radius" << this->setRadius;

    return sufixo;
}

//create vehicle trace files to analyze the simulation
fstream SimulationFiles::createVehicleTraces(int idVehicle, string lastNameFile)
{
    // trace message file
    std::stringstream nameFileMessage;
    std::stringstream aux;
    nameFileMessage.str("");

    aux = getFilePreFix(idVehicle);


    nameFileMessage << aux.str() << lastNameFile;
    fstream tracefile;
    tracefile.open(nameFileMessage.str(), fstream::in | fstream::out | fstream::app);

    return tracefile;
    //<< oIcarContext->textDataAgentPair(-1, new AgentPair(), true) << ";"  << std::endl << oIcarContext->dataAgentPair.str();
}

void SimulationFiles::createGlobalTraces(int idVehicle){
    // trace message file
    stringstream nameFileMessage;

    string aux=getFilePreFix(idVehicle).str();

    nameFileMessage << aux << "Messages.csv";
    this->fileMessages.open(nameFileMessage.str(), fstream::in | fstream::out | fstream::app);
    this->fileMessages << this->oSimFilesHeader.headerMessages() << endl;
    //std::cout << nameFileMessage.str() << endl;

    nameFileMessage.str("");
    nameFileMessage << aux << "AgentPair.csv";
    this->fileChannels.open(nameFileMessage.str(), fstream::in | fstream::out | fstream::app);
    this->fileChannels << this->oSimFilesHeader.headerAgentPairComplete() << endl;

    nameFileMessage.str("");
    nameFileMessage << aux << "LocalAgents.csv";
    this->fileLocalAgents.open (nameFileMessage.str(), fstream::in | fstream::out | fstream::app);
    this->fileLocalAgents << this->oSimFilesHeader.headerLocalAgent() << endl; //this->fileLocalAgents.open (nameFileMessage.str());

    nameFileMessage.str("");
    nameFileMessage  << aux << "RemoteAgents.csv";
    this->fileRemoteAgents.open (nameFileMessage.str(), fstream::in | fstream::out | fstream::app);

   nameFileMessage.str("");
   nameFileMessage  << aux << "CommPerformance.csv";
   this->fileCommPerformance.open(nameFileMessage.str(), fstream::in | fstream::out | fstream::app);

   //std::cout << nameFileMessage.str() << endl;

   nameFileMessage.str("");
   nameFileMessage  << aux << "AgentPairList.csv";
   this->fileChannelsMinslr.open(nameFileMessage.str(), fstream::in | fstream::out | fstream::app);
   this->fileChannelsMinslr << ";localAgent" << this->oSimFilesHeader.headerAgentPair() << endl;

   nameFileMessage.str("");
   nameFileMessage  << aux << "ReceivedMessages.csv";
   this->fileReceivedMessages.open(nameFileMessage.str(), fstream::in | fstream::out | fstream::app);
   this->fileReceivedMessages << this->oSimFilesHeader.headerMessages() << endl;
}
}
