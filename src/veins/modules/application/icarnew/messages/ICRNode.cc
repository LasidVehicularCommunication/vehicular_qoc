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

#include <veins/modules/application/icarnew/messages/ICRNode.h>

namespace veins{

ICRNode::ICRNode() {
    // TODO Auto-generated constructor stub

}

ICRNode::~ICRNode() {
    // TODO Auto-generated destructor stub
}

void ICRNode::prepareICRNode(Agent* a) {

    this->maxSpeed = a->getMobilityInfo()->getMaxSpeed();
    this->angle = a->getMobilityInfo()->getAngle();
    this->aceleration = a->getMobilityInfo()->getAcceleration();
    this->posTimeStamp = a->getMobilityInfo()->getActualMove()->getStartTime();
    this->speed = a->getMobilityInfo()->getActualMove()->getSpeed();
    this->posX = a->getMobilityInfo()->getActualMove()->getStartPos().x;
    this->posY = a->getMobilityInfo()->getActualMove()->getStartPos().y;
    this->posZ = a->getMobilityInfo()->getActualMove()->getStartPos().z;
    this->msgTimeStamp = simTime();
    this->nodeId = a->getId();

}



/*
void ICRNode::preparetwo(float a) {

maxSpeed = a;

}
*/
}
