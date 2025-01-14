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

#ifndef SRC_VEINS_MODULES_APPLICATION_ICARNEW_SIMULATIONFILES_H_
#define SRC_VEINS_MODULES_APPLICATION_ICARNEW_SIMULATIONFILES_H_
#include <omnetpp.h>
#include <fstream>
#include <sstream>
#include "SimFilesHeader.h"
using namespace std;

namespace veins{
class SimulationFiles {
public:
    SimulationFiles();


    virtual ~SimulationFiles();

    void createGlobalTraces(int idVehicle);

    std::fstream createVehicleTraces(int idVehicle, string lastNameFile);


    std::stringstream getFilePreFix(int idVehicle);

    SimulationFiles(int vehicleAmout, float lostMessageRate, float loadPeriodApp,
            float mobilityPeriod, float monitorPeriod,float setRadius);


public:

    std::fstream fileMessages;
    std::fstream fileChannels;
    std::fstream fileLocalAgents;
    std::fstream fileRemoteAgents;
    std::fstream fileReceivedMessages;
    std::fstream fileChannelsMinslr;
    std::fstream fileCommPerformance;
    ////// STATISTIC ///////////
   // buffer file trace Channel;
    std::stringstream QoCQoSdataAgentPair;

   // buffer file trace Channel;
    std::stringstream dataAgentPair;

    // buffer file trace Minslr;
    std::stringstream dataMinslr;

    // buffer file trace Remote Agent;
    std::stringstream dataRemoteAgent;

    // buffer file trace Remote Agent;
    std::stringstream dataLocalAgent;

    // buffer file trace Communication performance;
    std::stringstream dataCommPerformance;

    // buffer file trace received Message  ;
    std::stringstream dataMsgReceived;


    std::string observationNameFile;

    std::string oFilesDirectory;

    SimFilesHeader  oSimFilesHeader;

    int vehicleAmout;


    float lostMessageRate;


    float loadPeriodApp;


    float mobilityPeriod;


    float monitorPeriod;


    float setRadius;

};
}
#endif /* SRC_VEINS_MODULES_APPLICATION_ICARNEW_SIMULATIONFILES_H_ */
