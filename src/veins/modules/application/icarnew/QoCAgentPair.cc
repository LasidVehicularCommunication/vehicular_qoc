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

#include "QoCAgentPair.h"

namespace veins{


QoCAgentPair::QoCAgentPair(AgentPair * c, simtime_t dataValidity) {
    // TODO Auto-generated constructor stub
    std::cout << endl << "begin  QoCAgentPair "<< endl;

    this->timeliness = new TimelinessAgentPair(c, dataValidity);
    std::cout << endl << "end  QoCAgentPair "<< endl;


}

QoCAgentPair::~QoCAgentPair() {
    // TODO Auto-generated destructor stub
    delete (this);

}

TimelinessAgentPair * QoCAgentPair::getTimelinessAgentPair(){
    return ((TimelinessAgentPair *) this->timeliness);
}
}
