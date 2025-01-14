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

#ifndef SRC_VEINS_MODULES_APPLICATION_ICARNEW_SIMFILESHEADER_H_
#define SRC_VEINS_MODULES_APPLICATION_ICARNEW_SIMFILESHEADER_H_

#include <omnetpp.h>
#include <fstream>
#include <sstream>

using namespace std;

class SimFilesHeader {

public:
    std::string headerAgentPair(){
        std::ostringstream ost;
        ost << "";
        ost << ";agOID"
                << ";agDID"
                <<";neighbor"
                  ";pairState"
                  ";delayMSG"
                ";currentReceviedMSGNumber"
                ";LastReceviedMSGNumber"
                //";lostMessage"
                <<";CurrTSMsgSending"
                << ";receivedMessageAmount"
                << ";currSTRecMSG"
                << ";lastSTRecMSG"
                << ";travelTimeMSG"
                << ";receivedPowerDbm"
                << ";snr"
                << ";radiusCalc;drlRadius"
                << ";outOfRadiusRange"
                << ";drl;drlAngleRad;drlX;drlY;rSpeed_rl;rSpeedrlAngle;rSpeedXrl;rSpeedYrl" //AgentPairMobility
                << ";timeStampAgentPair;" //TimelinessAgentPair
                               "alfa;"
                               "alfaGrau;"
                               "Srl;srlmais;srlmenos;SrlMin;priorVTinT;VTinT;priorVT;VT;"
                               "priorVTmin;VTmin;priorVTminT;VTminT;"
                               "AnteriorAgePair;ageAgentPair;"
                               "priorcoConfianca;coConfianca;"
                               "priortimeliness;timeliness;alpha;quadranteDrl;quadranteVrl;quadranteS;quadranteD"

                <<";AgentId_S" << ";agentName" //<< agent.h
                << ";ageCurrentPos"  << ";maxSpeed"   //this->getMobilityInfo()->infoTrace(header, idagent) ;
                  << ";currUpdatePosTime"
                  << ";acceleration"
                  << ";angleRad"
                  << ";currentPosx"
                  << ";currentPosy"
                  << ";currentPosz"
                  << ";speed"
                  << ";lastUpdatePosTime"
                  << ";lastPosx"
                  << ";lastPosy"
                  << ";lastPosz"
                  << ";lastSpeed"
                  <<";AgentId_D" << ";agentName" //<< agent.h
                << ";ageCurrentPos"  << ";maxSpeed"   //this->getMobilityInfo()->infoTrace(header, idagent) ;
                  << ";currUpdatePosTime"
                  << ";acceleration"
                  << ";angleRad"
                  << ";currentPosx"
                  << ";currentPosy"
                  << ";currentPosz"
                  << ";speed"
                  << ";lastUpdatePosTime"
                  << ";lastPosx"
                  << ";lastPosy"
                  << ";lastPosz"
                  << ";lastSpeed";
          return ost.str();
      }

    std::string headerAgentPairComplete(){
        std::ostringstream ost;
        ost << "";
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
                ";calculatedDistance;distanceDifference;idLocal" //<< c->infoTrace(true);
                 << headerAgentPair();

        return ost.str();
     }

    std::string headerLocalAgent(){
        std::ostringstream ost;
         ost << "";

         ost << ";AgentId" << ";agentName"
                 << ";ageCurrentPos"  << ";maxSpeed"   //this->getMobilityInfo()->infoTrace(header, idagent) ;
                     << ";currUpdatePosTime"
                     << ";acceleration"
                     << ";angleRad"
                     << ";currentPosx"
                     << ";currentPosy"
                     << ";currentPosz"
                     << ";speed"
                     << ";lastUpdatePosTime"
                     << ";lastPosx"
                     << ";lastPosy"
                     << ";lastPosz"
                     << ";lastSpeed"
                     <<";Local recievedMsgTemporario;Local rateRecievedMSGPperiod;Local totalReceivedMsg;totalForwardedMsg;totalTransmittedMsg";
        return ost.str();
    }

    std::string headerMessages(){

        std::ostringstream ost;
        ost    << ";event"
               << ";eventTime"
               << ";localNodeID"
               << ";messageNumber"
               << ";MsgType"
               << ";MSGTime"
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

          return ost.str();
          }
};

#endif /* SRC_VEINS_MODULES_APPLICATION_ICARNEW_SIMFILESHEADER_H_ */
