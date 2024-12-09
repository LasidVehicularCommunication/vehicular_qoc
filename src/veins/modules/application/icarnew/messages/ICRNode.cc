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

//void ICRNode::prepareICRNode(const Agent& a) {

    /*maxSpeed = a->getMobilityInfo()->getMaxSpeed();
    angle = a->getMobilityInfo()->getAngle();
    aceleration = a->getMobilityInfo()->getAcceleration();
    posTimeStamp = a->getMobilityInfo()->getActualMove()->getStartTime();
    speed = a->getMobilityInfo()->getActualMove()->getSpeed();
    posX = a->getMobilityInfo()->getActualMove()->getStartPos().x;
    posY = a->getMobilityInfo()->getActualMove()->getStartPos().y;
    posZ = a->getMobilityInfo()->getActualMove()->getStartPos().z;
    msgTimeStamp = simTime();
    nodeId = a->getId();*/
//}


void ICRNode::copyICRNode(const ICRNode& node){
    maxSpeed = node.maxSpeed;
    angle = node.angle;
    aceleration = node.aceleration;
    posTimeStamp = node.posTimeStamp;
    speed = node.speed;
    posX = node.posX;
    posY = node.posY;
    posZ = node.posZ;
    msgTimeStamp = node.msgTimeStamp;
    nodeId = node.nodeId;
}

void ICRNode::initializeICRNode(){
    nodeId = -1;
    maxSpeed = 0.00;
    angle =  0.00;
    aceleration =  0.00;
    posTimeStamp =  0.00;
    speed =  0.00;
    posX =  0.00;
    posY =  0.00;
    posZ =  0.00;
    msgTimeStamp =  0.00;
}

/*
void ICRNode::preparetwo(float a) {

maxSpeed = a;

}
*/
}
