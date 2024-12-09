//
// Generated file, do not edit! Created by nedtool 5.6 from veins/modules/application/icarnew/messages/ICMessage.msg.
//

#ifndef __VEINS_ICMESSAGE_M_H
#define __VEINS_ICMESSAGE_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0506
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif

// dll export symbol
#ifndef VEINS_API
#  if defined(VEINS_EXPORT)
#    define VEINS_API  OPP_DLLEXPORT
#  elif defined(VEINS_IMPORT)
#    define VEINS_API  OPP_DLLIMPORT
#  else
#    define VEINS_API
#  endif
#endif


namespace veins {

class ICMessage;
} // namespace veins

#include "veins/modules/messages/BaseFrame1609_4_m.h" // import veins.modules.messages.BaseFrame1609_4

#include "veins/base/utils/Coord_m.h" // import veins.base.utils.Coord

#include "veins/base/utils/SimpleAddress_m.h" // import veins.base.utils.SimpleAddress


namespace veins {

/**
 * Class generated from <tt>veins/modules/application/icarnew/messages/ICMessage.msg:26</tt> by nedtool.
 * <pre>
 * packet ICMessage extends BaseFrame1609_4
 * {
 *     unsigned long numMsg; // number of message
 *     int msgType; // message type 
 *     long sourceId;  // source id node - 32bits 
 *     long destinationId; // destination id node - 32 bits 
 *     long antecessorId; // anetecessor id node - - 32 bits 
 *     long nextId; // next id node - 32 bits 
 * 
 *     float sourceX = 0;  //source x - 32 bits
 *     float sourceY = 0; // source y - 32 bits
 *     float sourceZ = 0; // source z - 32 bits
 * 
 *     float antecessorX = 0;  // Antecessor x - 32 bits
 *     float antecessorY = 0; // Antecessor y - 32 bits
 *     float antecessorZ = 0; // Antecessor z  - 32 bits
 * 
 *     float nextX = 0;  // next x - 32 bits
 *     float nextY = 0; // next y - 32 bits
 *     float nextZ = 0; // next z  - 32 bits
 * 
 *     float destinationX = 0;  // destination x - 32 bits
 *     float destinationY = 0; // destination y - 32 bits
 *     float destinationZ = 0; // destination z  - 32 bits
 * 
 *     float sourceMaxSpeed = 0;  // velocidade do agente de origem - 32 bits
 *     float antecessorMaxSpeed = 0;  // velocidade do agente de antecessor - 32 bits
 *     float nextMaxSpeed = 0;  // velocidade do prximo agente de encaminhamento que ira consumir a mensagem - 32 bits
 *     float destinationMaxSpeed = 0;  // velocidade mxima do agente destino que ira consumir a mensagem - 32 bits
 * 
 *     float sourceAngle = 0;  // angulo do agente de origem -  32 bits
 *     float antecessorAngle = 0;  // angulo do agente de antecessor - 32 bits
 *     float nextAngle = 0;  // angulo do proximo agente de encaminhamento - 32 bits
 *     float destinationAngle = 0;  // angulo do agente destino que ira consumir a mensagem - 32 bits
 * 
 *     float sourceAceleration = 0;  // aceleracao do agente de origem -  32 bits
 *     float antecessorAceleration = 0;  // aceleracao do agente de antecessor - 32 bits
 *     float nextAceleration = 0;  // aceleracao do proximo agente de encaminhamento - 32 bits
 *     float destinationAceleration = 0;  // aceleracao do agente destino que ira consumir a mensagem - 32 bits
 * 
 *     float sourceSpeed = 0;  // velocidade do agente de origem -  32 bits
 *     float antecessorSpeed = 0;  // velocidade do agente de antecessor - 32 bits
 *     float nextSpeed = 0;  // velocidade do proximo agente de encaminhamento - 32 bits
 *     float destinationSpeed = 0;  // velocidade do agente destino que ira consumir a mensagem - 32 bits
 * 
 *     simtime_t anteNextValidityTimeStamp = 0; // alcance do sinal de comunicacao do agente de origem  - 32 bits
 * 
 *     simtime_t sourceMsgTimeStamp = 0; // timestamp da mensagem
 *     simtime_t antecessorMsgTimeStamp = 0; // timestamp da mensagem
 * 
 *     simtime_t msgLifeTime; // message life time - 16 bits
 * 
 *     simtime_t AntecessoPosTimeStamp = 0; // timestamp da da coleta da posicao do agente antecessor 
 *     simtime_t SourcePosTimeStamp = 0; // timestamp da da coleta da posicao do agente de origem 
 *     simtime_t nextPosTimeStamp = 0; // timestamp da da coleta da posicao do proximo agente de encaminhamento
 *     simtime_t destinationPosTimeStamp = 0; // timestamp da da coleta da posicao do proximo agente de encaminhamento
 * 
 *     simtime_t validityDataTimeStamp; // validity timeout of the menor neighborhood condition of the route nodes
 *     unsigned int hopNumber = 0; // hops counting of route in that moment 
 * 
 * }
 * </pre>
 */
class VEINS_API ICMessage : public ::veins::BaseFrame1609_4
{
  protected:
    unsigned long numMsg = 0;
    int msgType = 0;
    long sourceId = 0;
    long destinationId = 0;
    long antecessorId = 0;
    long nextId = 0;
    float sourceX = 0;
    float sourceY = 0;
    float sourceZ = 0;
    float antecessorX = 0;
    float antecessorY = 0;
    float antecessorZ = 0;
    float nextX = 0;
    float nextY = 0;
    float nextZ = 0;
    float destinationX = 0;
    float destinationY = 0;
    float destinationZ = 0;
    float sourceMaxSpeed = 0;
    float antecessorMaxSpeed = 0;
    float nextMaxSpeed = 0;
    float destinationMaxSpeed = 0;
    float sourceAngle = 0;
    float antecessorAngle = 0;
    float nextAngle = 0;
    float destinationAngle = 0;
    float sourceAceleration = 0;
    float antecessorAceleration = 0;
    float nextAceleration = 0;
    float destinationAceleration = 0;
    float sourceSpeed = 0;
    float antecessorSpeed = 0;
    float nextSpeed = 0;
    float destinationSpeed = 0;
    omnetpp::simtime_t anteNextValidityTimeStamp = 0;
    omnetpp::simtime_t sourceMsgTimeStamp = 0;
    omnetpp::simtime_t antecessorMsgTimeStamp = 0;
    omnetpp::simtime_t msgLifeTime = SIMTIME_ZERO;
    omnetpp::simtime_t AntecessoPosTimeStamp = 0;
    omnetpp::simtime_t SourcePosTimeStamp = 0;
    omnetpp::simtime_t nextPosTimeStamp = 0;
    omnetpp::simtime_t destinationPosTimeStamp = 0;
    omnetpp::simtime_t validityDataTimeStamp = SIMTIME_ZERO;
    unsigned int hopNumber = 0;

  private:
    void copy(const ICMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const ICMessage&);

  public:
    ICMessage(const char *name=nullptr, short kind=0);
    ICMessage(const ICMessage& other);
    virtual ~ICMessage();
    ICMessage& operator=(const ICMessage& other);
    virtual ICMessage *dup() const override {return new ICMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual unsigned long getNumMsg() const;
    virtual void setNumMsg(unsigned long numMsg);
    virtual int getMsgType() const;
    virtual void setMsgType(int msgType);
    virtual long getSourceId() const;
    virtual void setSourceId(long sourceId);
    virtual long getDestinationId() const;
    virtual void setDestinationId(long destinationId);
    virtual long getAntecessorId() const;
    virtual void setAntecessorId(long antecessorId);
    virtual long getNextId() const;
    virtual void setNextId(long nextId);
    virtual float getSourceX() const;
    virtual void setSourceX(float sourceX);
    virtual float getSourceY() const;
    virtual void setSourceY(float sourceY);
    virtual float getSourceZ() const;
    virtual void setSourceZ(float sourceZ);
    virtual float getAntecessorX() const;
    virtual void setAntecessorX(float antecessorX);
    virtual float getAntecessorY() const;
    virtual void setAntecessorY(float antecessorY);
    virtual float getAntecessorZ() const;
    virtual void setAntecessorZ(float antecessorZ);
    virtual float getNextX() const;
    virtual void setNextX(float nextX);
    virtual float getNextY() const;
    virtual void setNextY(float nextY);
    virtual float getNextZ() const;
    virtual void setNextZ(float nextZ);
    virtual float getDestinationX() const;
    virtual void setDestinationX(float destinationX);
    virtual float getDestinationY() const;
    virtual void setDestinationY(float destinationY);
    virtual float getDestinationZ() const;
    virtual void setDestinationZ(float destinationZ);
    virtual float getSourceMaxSpeed() const;
    virtual void setSourceMaxSpeed(float sourceMaxSpeed);
    virtual float getAntecessorMaxSpeed() const;
    virtual void setAntecessorMaxSpeed(float antecessorMaxSpeed);
    virtual float getNextMaxSpeed() const;
    virtual void setNextMaxSpeed(float nextMaxSpeed);
    virtual float getDestinationMaxSpeed() const;
    virtual void setDestinationMaxSpeed(float destinationMaxSpeed);
    virtual float getSourceAngle() const;
    virtual void setSourceAngle(float sourceAngle);
    virtual float getAntecessorAngle() const;
    virtual void setAntecessorAngle(float antecessorAngle);
    virtual float getNextAngle() const;
    virtual void setNextAngle(float nextAngle);
    virtual float getDestinationAngle() const;
    virtual void setDestinationAngle(float destinationAngle);
    virtual float getSourceAceleration() const;
    virtual void setSourceAceleration(float sourceAceleration);
    virtual float getAntecessorAceleration() const;
    virtual void setAntecessorAceleration(float antecessorAceleration);
    virtual float getNextAceleration() const;
    virtual void setNextAceleration(float nextAceleration);
    virtual float getDestinationAceleration() const;
    virtual void setDestinationAceleration(float destinationAceleration);
    virtual float getSourceSpeed() const;
    virtual void setSourceSpeed(float sourceSpeed);
    virtual float getAntecessorSpeed() const;
    virtual void setAntecessorSpeed(float antecessorSpeed);
    virtual float getNextSpeed() const;
    virtual void setNextSpeed(float nextSpeed);
    virtual float getDestinationSpeed() const;
    virtual void setDestinationSpeed(float destinationSpeed);
    virtual omnetpp::simtime_t getAnteNextValidityTimeStamp() const;
    virtual void setAnteNextValidityTimeStamp(omnetpp::simtime_t anteNextValidityTimeStamp);
    virtual omnetpp::simtime_t getSourceMsgTimeStamp() const;
    virtual void setSourceMsgTimeStamp(omnetpp::simtime_t sourceMsgTimeStamp);
    virtual omnetpp::simtime_t getAntecessorMsgTimeStamp() const;
    virtual void setAntecessorMsgTimeStamp(omnetpp::simtime_t antecessorMsgTimeStamp);
    virtual omnetpp::simtime_t getMsgLifeTime() const;
    virtual void setMsgLifeTime(omnetpp::simtime_t msgLifeTime);
    virtual omnetpp::simtime_t getAntecessoPosTimeStamp() const;
    virtual void setAntecessoPosTimeStamp(omnetpp::simtime_t AntecessoPosTimeStamp);
    virtual omnetpp::simtime_t getSourcePosTimeStamp() const;
    virtual void setSourcePosTimeStamp(omnetpp::simtime_t SourcePosTimeStamp);
    virtual omnetpp::simtime_t getNextPosTimeStamp() const;
    virtual void setNextPosTimeStamp(omnetpp::simtime_t nextPosTimeStamp);
    virtual omnetpp::simtime_t getDestinationPosTimeStamp() const;
    virtual void setDestinationPosTimeStamp(omnetpp::simtime_t destinationPosTimeStamp);
    virtual omnetpp::simtime_t getValidityDataTimeStamp() const;
    virtual void setValidityDataTimeStamp(omnetpp::simtime_t validityDataTimeStamp);
    virtual unsigned int getHopNumber() const;
    virtual void setHopNumber(unsigned int hopNumber);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const ICMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, ICMessage& obj) {obj.parsimUnpack(b);}

} // namespace veins

#endif // ifndef __VEINS_ICMESSAGE_M_H

