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


#ifndef AGENT_H_
#define AGENT_H_
//#include "SimpleAddress.h"
//#include <Coord.h>
#include "MobilityInfo.h"
#include "CommPerformance.h"
#include "CommInfo.h"
#include "QoCInfo.h"
#include <omnetpp.h>

namespace veins {
/**
 * @class Agent
 * @brief Uma breve descrição da classe.
 *
 * Uma descrição mais detalhada da classe, explicando sua funcionalidade e propósito.
 */
class Agent {
private:
    int64_t id = -1; /**< @brief Armazena o valor da classe. */
    std::string agentName; /**< @brief Armazena o valor da classe. */

    double setRadius;


public:
    MobilityInfo* mobilityInfo;
    CommInfo* commInfo;
    QoCInfo* qocInfo;
    Agent(int64_t id, std::string name);

    /**
     * @brief Construtor padrão.
     *
     * Inicializa os membros da classe.
     */
    Agent();
    std::string info();
    std::string infoTrace(bool header, std::string idagent);
    /**
         * @brief Método para obter o valor atual.
         *
         * @return O valor armazenado.
         */
    int64_t getId();
    /**
         * @brief Método para definir um valor.
         *
         * @param value O valor a ser definido.
     */
    void setId(int64_t id);
    virtual ~Agent();

    virtual MobilityInfo* getMobilityInfo();
    virtual void setMobilityInfo(MobilityInfo * mobilityInfo);
    virtual double getSetRadius();
    virtual void setSetRadius(double setRadius);
    virtual std::string getAgentName();
    virtual void setAgentName(std::string agentName);
    CommInfo* getCommInfo();
    void setCommInfo(CommInfo* commInfo);
};

}
#endif /* AGENT_H_ */

   /*
    * const CommInfo* getCommInfo() const;
    void setCommInfo(CommInfo* commInfo);
    MobilityInfo* getMobilityInfo();
    void setMobilityInfo(MobilityInfo* movement);
    std::string info();

     void setNewAgent(int ag, Coord& co, simtime_t tSource, simtime_t tsLocal, double speed,  LAddress::L3Type agnetAdress,
            double distanceRadiusCommA, double distanceRadiusCommB, double vmr, double distanceab, double periodSensorMoving);LAddress::L3Type getNetworkAdress() const;
    void setNetworkAdress(LAddress::L3Type networkAdress);
    simtime_t getTimeSourceArrivedLocal() const;
    void setTimeSourceArrivedLocal(simtime_t timeSourceArrivedLocal);
    simtime_t getTimeSourceKnowed() const;
    void setTimeSourceKnowed(simtime_t timeSourceKnowed);
    MobilityInfo* getMobilityInfo();
    void setMobilityInfo(MobilityInfo* movement);
    void updateAgent(Coord& co, simtime_t tSource, simtime_t tsLocal, double speed,  LAddress::L3Type agnetAdress,
            double distanceRadiusCommA, double distanceRadiusCommB, double vmr, double distanceab, double periodSensorMoving);
    const CommInfo* getCommInfo() const;
    void setCommInfo(CommInfo* commInfo);
    void updateCommInfo(double tSource);
    std::string recordAgent();
    */
