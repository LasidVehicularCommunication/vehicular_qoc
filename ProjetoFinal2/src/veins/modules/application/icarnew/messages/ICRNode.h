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

#ifndef SRC_VEINS_MODULES_APPLICATION_ICARNEW_MESSAGES_ICRNODE_H_
#define SRC_VEINS_MODULES_APPLICATION_ICARNEW_MESSAGES_ICRNODE_H_

//#include "veins/veins.h"
#include <omnetpp.h>
#include "../Agent.h"

namespace veins{
class Icarqoc;

class ICRNode {
public:
    int64_t  nodeId;  // source id node - 64bits
    double posX;  //source x - 64 bits
    double posY; // source y - 64 bits
    double posZ; // source z - 64 bits
    double maxSpeed;  // max speed node - 64 bits
    double angle;  // angulo do agente de origem -  64 bits
    double aceleration;  // aceleracao do agente de origem -  64 bits
    double speed;  // speed value -  64 bits
    bool neighber; // vizinho do proximo no
    double confidence;
    double validityTimeToNext; // alcance do sinal de comunicacao do agente de origem  - 64 bits
    double  posTimeStamp; // timestamp da da coleta da posicao do agente antecessor
    double  msgTimeStamp;
    ICRNode();
    virtual ~ICRNode();
    void copyICRNode(const ICRNode& node);
    void initializeICRNode();

    //void preparetwo(float a) ;

};
}
#endif /* SRC_VEINS_MODULES_APPLICATION_ICARNEW_MESSAGES_ICRNODE_H_ */
