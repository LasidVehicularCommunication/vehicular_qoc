//
// TODO generated message class
//

import veins.modules.messages.BaseFrame1609_4;
import veins.modules.application.icarnew.messages.ICRNode;


//cplusplus{{
//#include "ICRNode.h"
//#include "veins/modules/application/icarnew/messages/ICRNode.h"
//}}

namespace veins;

class ICRMessage extends BaseFrame1609_4 {
   unsigned long numMsg; // number of message
   int msgType; // message type 
   simtime_t msgLifeTime; // message life time - 16 bits
   simtime_t validityDataTimeStamp; // validity timeout of the menor neighborhood condition of the route nodes
   double confidence;
   unsigned int hopNumber;
   simtime_t msgTimeStamp = 0; // timestamp da mensagem

   ICRNode routeNode[];

}
