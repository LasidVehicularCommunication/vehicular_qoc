//
// Generated file, do not edit! Created by nedtool 5.6 from veins/modules/application/icarnew/messages/ICMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include "ICMessage_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace {
template <class T> inline
typename std::enable_if<std::is_polymorphic<T>::value && std::is_base_of<omnetpp::cObject,T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)(static_cast<const omnetpp::cObject *>(t));
}

template <class T> inline
typename std::enable_if<std::is_polymorphic<T>::value && !std::is_base_of<omnetpp::cObject,T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)dynamic_cast<const void *>(t);
}

template <class T> inline
typename std::enable_if<!std::is_polymorphic<T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)static_cast<const void *>(t);
}

}

namespace veins {

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule to generate operator<< for shared_ptr<T>
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const std::shared_ptr<T>& t) { return out << t.get(); }

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');

    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(ICMessage)

ICMessage::ICMessage(const char *name, short kind) : ::veins::BaseFrame1609_4(name, kind)
{
}

ICMessage::ICMessage(const ICMessage& other) : ::veins::BaseFrame1609_4(other)
{
    copy(other);
}

ICMessage::~ICMessage()
{
}

ICMessage& ICMessage::operator=(const ICMessage& other)
{
    if (this == &other) return *this;
    ::veins::BaseFrame1609_4::operator=(other);
    copy(other);
    return *this;
}

void ICMessage::copy(const ICMessage& other)
{
    this->numMsg = other.numMsg;
    this->msgType = other.msgType;
    this->sourceId = other.sourceId;
    this->destinationId = other.destinationId;
    this->antecessorId = other.antecessorId;
    this->nextId = other.nextId;
    this->sourceX = other.sourceX;
    this->sourceY = other.sourceY;
    this->sourceZ = other.sourceZ;
    this->antecessorX = other.antecessorX;
    this->antecessorY = other.antecessorY;
    this->antecessorZ = other.antecessorZ;
    this->nextX = other.nextX;
    this->nextY = other.nextY;
    this->nextZ = other.nextZ;
    this->destinationX = other.destinationX;
    this->destinationY = other.destinationY;
    this->destinationZ = other.destinationZ;
    this->sourceMaxSpeed = other.sourceMaxSpeed;
    this->antecessorMaxSpeed = other.antecessorMaxSpeed;
    this->nextMaxSpeed = other.nextMaxSpeed;
    this->destinationMaxSpeed = other.destinationMaxSpeed;
    this->sourceAngle = other.sourceAngle;
    this->antecessorAngle = other.antecessorAngle;
    this->nextAngle = other.nextAngle;
    this->destinationAngle = other.destinationAngle;
    this->sourceAceleration = other.sourceAceleration;
    this->antecessorAceleration = other.antecessorAceleration;
    this->nextAceleration = other.nextAceleration;
    this->destinationAceleration = other.destinationAceleration;
    this->sourceSpeed = other.sourceSpeed;
    this->antecessorSpeed = other.antecessorSpeed;
    this->nextSpeed = other.nextSpeed;
    this->destinationSpeed = other.destinationSpeed;
    this->anteNextValidityTimeStamp = other.anteNextValidityTimeStamp;
    this->sourceMsgTimeStamp = other.sourceMsgTimeStamp;
    this->antecessorMsgTimeStamp = other.antecessorMsgTimeStamp;
    this->msgLifeTime = other.msgLifeTime;
    this->AntecessoPosTimeStamp = other.AntecessoPosTimeStamp;
    this->SourcePosTimeStamp = other.SourcePosTimeStamp;
    this->nextPosTimeStamp = other.nextPosTimeStamp;
    this->destinationPosTimeStamp = other.destinationPosTimeStamp;
    this->validityDataTimeStamp = other.validityDataTimeStamp;
    this->hopNumber = other.hopNumber;
}

void ICMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::veins::BaseFrame1609_4::parsimPack(b);
    doParsimPacking(b,this->numMsg);
    doParsimPacking(b,this->msgType);
    doParsimPacking(b,this->sourceId);
    doParsimPacking(b,this->destinationId);
    doParsimPacking(b,this->antecessorId);
    doParsimPacking(b,this->nextId);
    doParsimPacking(b,this->sourceX);
    doParsimPacking(b,this->sourceY);
    doParsimPacking(b,this->sourceZ);
    doParsimPacking(b,this->antecessorX);
    doParsimPacking(b,this->antecessorY);
    doParsimPacking(b,this->antecessorZ);
    doParsimPacking(b,this->nextX);
    doParsimPacking(b,this->nextY);
    doParsimPacking(b,this->nextZ);
    doParsimPacking(b,this->destinationX);
    doParsimPacking(b,this->destinationY);
    doParsimPacking(b,this->destinationZ);
    doParsimPacking(b,this->sourceMaxSpeed);
    doParsimPacking(b,this->antecessorMaxSpeed);
    doParsimPacking(b,this->nextMaxSpeed);
    doParsimPacking(b,this->destinationMaxSpeed);
    doParsimPacking(b,this->sourceAngle);
    doParsimPacking(b,this->antecessorAngle);
    doParsimPacking(b,this->nextAngle);
    doParsimPacking(b,this->destinationAngle);
    doParsimPacking(b,this->sourceAceleration);
    doParsimPacking(b,this->antecessorAceleration);
    doParsimPacking(b,this->nextAceleration);
    doParsimPacking(b,this->destinationAceleration);
    doParsimPacking(b,this->sourceSpeed);
    doParsimPacking(b,this->antecessorSpeed);
    doParsimPacking(b,this->nextSpeed);
    doParsimPacking(b,this->destinationSpeed);
    doParsimPacking(b,this->anteNextValidityTimeStamp);
    doParsimPacking(b,this->sourceMsgTimeStamp);
    doParsimPacking(b,this->antecessorMsgTimeStamp);
    doParsimPacking(b,this->msgLifeTime);
    doParsimPacking(b,this->AntecessoPosTimeStamp);
    doParsimPacking(b,this->SourcePosTimeStamp);
    doParsimPacking(b,this->nextPosTimeStamp);
    doParsimPacking(b,this->destinationPosTimeStamp);
    doParsimPacking(b,this->validityDataTimeStamp);
    doParsimPacking(b,this->hopNumber);
}

void ICMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::veins::BaseFrame1609_4::parsimUnpack(b);
    doParsimUnpacking(b,this->numMsg);
    doParsimUnpacking(b,this->msgType);
    doParsimUnpacking(b,this->sourceId);
    doParsimUnpacking(b,this->destinationId);
    doParsimUnpacking(b,this->antecessorId);
    doParsimUnpacking(b,this->nextId);
    doParsimUnpacking(b,this->sourceX);
    doParsimUnpacking(b,this->sourceY);
    doParsimUnpacking(b,this->sourceZ);
    doParsimUnpacking(b,this->antecessorX);
    doParsimUnpacking(b,this->antecessorY);
    doParsimUnpacking(b,this->antecessorZ);
    doParsimUnpacking(b,this->nextX);
    doParsimUnpacking(b,this->nextY);
    doParsimUnpacking(b,this->nextZ);
    doParsimUnpacking(b,this->destinationX);
    doParsimUnpacking(b,this->destinationY);
    doParsimUnpacking(b,this->destinationZ);
    doParsimUnpacking(b,this->sourceMaxSpeed);
    doParsimUnpacking(b,this->antecessorMaxSpeed);
    doParsimUnpacking(b,this->nextMaxSpeed);
    doParsimUnpacking(b,this->destinationMaxSpeed);
    doParsimUnpacking(b,this->sourceAngle);
    doParsimUnpacking(b,this->antecessorAngle);
    doParsimUnpacking(b,this->nextAngle);
    doParsimUnpacking(b,this->destinationAngle);
    doParsimUnpacking(b,this->sourceAceleration);
    doParsimUnpacking(b,this->antecessorAceleration);
    doParsimUnpacking(b,this->nextAceleration);
    doParsimUnpacking(b,this->destinationAceleration);
    doParsimUnpacking(b,this->sourceSpeed);
    doParsimUnpacking(b,this->antecessorSpeed);
    doParsimUnpacking(b,this->nextSpeed);
    doParsimUnpacking(b,this->destinationSpeed);
    doParsimUnpacking(b,this->anteNextValidityTimeStamp);
    doParsimUnpacking(b,this->sourceMsgTimeStamp);
    doParsimUnpacking(b,this->antecessorMsgTimeStamp);
    doParsimUnpacking(b,this->msgLifeTime);
    doParsimUnpacking(b,this->AntecessoPosTimeStamp);
    doParsimUnpacking(b,this->SourcePosTimeStamp);
    doParsimUnpacking(b,this->nextPosTimeStamp);
    doParsimUnpacking(b,this->destinationPosTimeStamp);
    doParsimUnpacking(b,this->validityDataTimeStamp);
    doParsimUnpacking(b,this->hopNumber);
}

unsigned long ICMessage::getNumMsg() const
{
    return this->numMsg;
}

void ICMessage::setNumMsg(unsigned long numMsg)
{
    this->numMsg = numMsg;
}

int ICMessage::getMsgType() const
{
    return this->msgType;
}

void ICMessage::setMsgType(int msgType)
{
    this->msgType = msgType;
}

long ICMessage::getSourceId() const
{
    return this->sourceId;
}

void ICMessage::setSourceId(long sourceId)
{
    this->sourceId = sourceId;
}

long ICMessage::getDestinationId() const
{
    return this->destinationId;
}

void ICMessage::setDestinationId(long destinationId)
{
    this->destinationId = destinationId;
}

long ICMessage::getAntecessorId() const
{
    return this->antecessorId;
}

void ICMessage::setAntecessorId(long antecessorId)
{
    this->antecessorId = antecessorId;
}

long ICMessage::getNextId() const
{
    return this->nextId;
}

void ICMessage::setNextId(long nextId)
{
    this->nextId = nextId;
}

float ICMessage::getSourceX() const
{
    return this->sourceX;
}

void ICMessage::setSourceX(float sourceX)
{
    this->sourceX = sourceX;
}

float ICMessage::getSourceY() const
{
    return this->sourceY;
}

void ICMessage::setSourceY(float sourceY)
{
    this->sourceY = sourceY;
}

float ICMessage::getSourceZ() const
{
    return this->sourceZ;
}

void ICMessage::setSourceZ(float sourceZ)
{
    this->sourceZ = sourceZ;
}

float ICMessage::getAntecessorX() const
{
    return this->antecessorX;
}

void ICMessage::setAntecessorX(float antecessorX)
{
    this->antecessorX = antecessorX;
}

float ICMessage::getAntecessorY() const
{
    return this->antecessorY;
}

void ICMessage::setAntecessorY(float antecessorY)
{
    this->antecessorY = antecessorY;
}

float ICMessage::getAntecessorZ() const
{
    return this->antecessorZ;
}

void ICMessage::setAntecessorZ(float antecessorZ)
{
    this->antecessorZ = antecessorZ;
}

float ICMessage::getNextX() const
{
    return this->nextX;
}

void ICMessage::setNextX(float nextX)
{
    this->nextX = nextX;
}

float ICMessage::getNextY() const
{
    return this->nextY;
}

void ICMessage::setNextY(float nextY)
{
    this->nextY = nextY;
}

float ICMessage::getNextZ() const
{
    return this->nextZ;
}

void ICMessage::setNextZ(float nextZ)
{
    this->nextZ = nextZ;
}

float ICMessage::getDestinationX() const
{
    return this->destinationX;
}

void ICMessage::setDestinationX(float destinationX)
{
    this->destinationX = destinationX;
}

float ICMessage::getDestinationY() const
{
    return this->destinationY;
}

void ICMessage::setDestinationY(float destinationY)
{
    this->destinationY = destinationY;
}

float ICMessage::getDestinationZ() const
{
    return this->destinationZ;
}

void ICMessage::setDestinationZ(float destinationZ)
{
    this->destinationZ = destinationZ;
}

float ICMessage::getSourceMaxSpeed() const
{
    return this->sourceMaxSpeed;
}

void ICMessage::setSourceMaxSpeed(float sourceMaxSpeed)
{
    this->sourceMaxSpeed = sourceMaxSpeed;
}

float ICMessage::getAntecessorMaxSpeed() const
{
    return this->antecessorMaxSpeed;
}

void ICMessage::setAntecessorMaxSpeed(float antecessorMaxSpeed)
{
    this->antecessorMaxSpeed = antecessorMaxSpeed;
}

float ICMessage::getNextMaxSpeed() const
{
    return this->nextMaxSpeed;
}

void ICMessage::setNextMaxSpeed(float nextMaxSpeed)
{
    this->nextMaxSpeed = nextMaxSpeed;
}

float ICMessage::getDestinationMaxSpeed() const
{
    return this->destinationMaxSpeed;
}

void ICMessage::setDestinationMaxSpeed(float destinationMaxSpeed)
{
    this->destinationMaxSpeed = destinationMaxSpeed;
}

float ICMessage::getSourceAngle() const
{
    return this->sourceAngle;
}

void ICMessage::setSourceAngle(float sourceAngle)
{
    this->sourceAngle = sourceAngle;
}

float ICMessage::getAntecessorAngle() const
{
    return this->antecessorAngle;
}

void ICMessage::setAntecessorAngle(float antecessorAngle)
{
    this->antecessorAngle = antecessorAngle;
}

float ICMessage::getNextAngle() const
{
    return this->nextAngle;
}

void ICMessage::setNextAngle(float nextAngle)
{
    this->nextAngle = nextAngle;
}

float ICMessage::getDestinationAngle() const
{
    return this->destinationAngle;
}

void ICMessage::setDestinationAngle(float destinationAngle)
{
    this->destinationAngle = destinationAngle;
}

float ICMessage::getSourceAceleration() const
{
    return this->sourceAceleration;
}

void ICMessage::setSourceAceleration(float sourceAceleration)
{
    this->sourceAceleration = sourceAceleration;
}

float ICMessage::getAntecessorAceleration() const
{
    return this->antecessorAceleration;
}

void ICMessage::setAntecessorAceleration(float antecessorAceleration)
{
    this->antecessorAceleration = antecessorAceleration;
}

float ICMessage::getNextAceleration() const
{
    return this->nextAceleration;
}

void ICMessage::setNextAceleration(float nextAceleration)
{
    this->nextAceleration = nextAceleration;
}

float ICMessage::getDestinationAceleration() const
{
    return this->destinationAceleration;
}

void ICMessage::setDestinationAceleration(float destinationAceleration)
{
    this->destinationAceleration = destinationAceleration;
}

float ICMessage::getSourceSpeed() const
{
    return this->sourceSpeed;
}

void ICMessage::setSourceSpeed(float sourceSpeed)
{
    this->sourceSpeed = sourceSpeed;
}

float ICMessage::getAntecessorSpeed() const
{
    return this->antecessorSpeed;
}

void ICMessage::setAntecessorSpeed(float antecessorSpeed)
{
    this->antecessorSpeed = antecessorSpeed;
}

float ICMessage::getNextSpeed() const
{
    return this->nextSpeed;
}

void ICMessage::setNextSpeed(float nextSpeed)
{
    this->nextSpeed = nextSpeed;
}

float ICMessage::getDestinationSpeed() const
{
    return this->destinationSpeed;
}

void ICMessage::setDestinationSpeed(float destinationSpeed)
{
    this->destinationSpeed = destinationSpeed;
}

omnetpp::simtime_t ICMessage::getAnteNextValidityTimeStamp() const
{
    return this->anteNextValidityTimeStamp;
}

void ICMessage::setAnteNextValidityTimeStamp(omnetpp::simtime_t anteNextValidityTimeStamp)
{
    this->anteNextValidityTimeStamp = anteNextValidityTimeStamp;
}

omnetpp::simtime_t ICMessage::getSourceMsgTimeStamp() const
{
    return this->sourceMsgTimeStamp;
}

void ICMessage::setSourceMsgTimeStamp(omnetpp::simtime_t sourceMsgTimeStamp)
{
    this->sourceMsgTimeStamp = sourceMsgTimeStamp;
}

omnetpp::simtime_t ICMessage::getAntecessorMsgTimeStamp() const
{
    return this->antecessorMsgTimeStamp;
}

void ICMessage::setAntecessorMsgTimeStamp(omnetpp::simtime_t antecessorMsgTimeStamp)
{
    this->antecessorMsgTimeStamp = antecessorMsgTimeStamp;
}

omnetpp::simtime_t ICMessage::getMsgLifeTime() const
{
    return this->msgLifeTime;
}

void ICMessage::setMsgLifeTime(omnetpp::simtime_t msgLifeTime)
{
    this->msgLifeTime = msgLifeTime;
}

omnetpp::simtime_t ICMessage::getAntecessoPosTimeStamp() const
{
    return this->AntecessoPosTimeStamp;
}

void ICMessage::setAntecessoPosTimeStamp(omnetpp::simtime_t AntecessoPosTimeStamp)
{
    this->AntecessoPosTimeStamp = AntecessoPosTimeStamp;
}

omnetpp::simtime_t ICMessage::getSourcePosTimeStamp() const
{
    return this->SourcePosTimeStamp;
}

void ICMessage::setSourcePosTimeStamp(omnetpp::simtime_t SourcePosTimeStamp)
{
    this->SourcePosTimeStamp = SourcePosTimeStamp;
}

omnetpp::simtime_t ICMessage::getNextPosTimeStamp() const
{
    return this->nextPosTimeStamp;
}

void ICMessage::setNextPosTimeStamp(omnetpp::simtime_t nextPosTimeStamp)
{
    this->nextPosTimeStamp = nextPosTimeStamp;
}

omnetpp::simtime_t ICMessage::getDestinationPosTimeStamp() const
{
    return this->destinationPosTimeStamp;
}

void ICMessage::setDestinationPosTimeStamp(omnetpp::simtime_t destinationPosTimeStamp)
{
    this->destinationPosTimeStamp = destinationPosTimeStamp;
}

omnetpp::simtime_t ICMessage::getValidityDataTimeStamp() const
{
    return this->validityDataTimeStamp;
}

void ICMessage::setValidityDataTimeStamp(omnetpp::simtime_t validityDataTimeStamp)
{
    this->validityDataTimeStamp = validityDataTimeStamp;
}

unsigned int ICMessage::getHopNumber() const
{
    return this->hopNumber;
}

void ICMessage::setHopNumber(unsigned int hopNumber)
{
    this->hopNumber = hopNumber;
}

class ICMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_numMsg,
        FIELD_msgType,
        FIELD_sourceId,
        FIELD_destinationId,
        FIELD_antecessorId,
        FIELD_nextId,
        FIELD_sourceX,
        FIELD_sourceY,
        FIELD_sourceZ,
        FIELD_antecessorX,
        FIELD_antecessorY,
        FIELD_antecessorZ,
        FIELD_nextX,
        FIELD_nextY,
        FIELD_nextZ,
        FIELD_destinationX,
        FIELD_destinationY,
        FIELD_destinationZ,
        FIELD_sourceMaxSpeed,
        FIELD_antecessorMaxSpeed,
        FIELD_nextMaxSpeed,
        FIELD_destinationMaxSpeed,
        FIELD_sourceAngle,
        FIELD_antecessorAngle,
        FIELD_nextAngle,
        FIELD_destinationAngle,
        FIELD_sourceAceleration,
        FIELD_antecessorAceleration,
        FIELD_nextAceleration,
        FIELD_destinationAceleration,
        FIELD_sourceSpeed,
        FIELD_antecessorSpeed,
        FIELD_nextSpeed,
        FIELD_destinationSpeed,
        FIELD_anteNextValidityTimeStamp,
        FIELD_sourceMsgTimeStamp,
        FIELD_antecessorMsgTimeStamp,
        FIELD_msgLifeTime,
        FIELD_AntecessoPosTimeStamp,
        FIELD_SourcePosTimeStamp,
        FIELD_nextPosTimeStamp,
        FIELD_destinationPosTimeStamp,
        FIELD_validityDataTimeStamp,
        FIELD_hopNumber,
    };
  public:
    ICMessageDescriptor();
    virtual ~ICMessageDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(ICMessageDescriptor)

ICMessageDescriptor::ICMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(veins::ICMessage)), "veins::BaseFrame1609_4")
{
    propertynames = nullptr;
}

ICMessageDescriptor::~ICMessageDescriptor()
{
    delete[] propertynames;
}

bool ICMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ICMessage *>(obj)!=nullptr;
}

const char **ICMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ICMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ICMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 44+basedesc->getFieldCount() : 44;
}

unsigned int ICMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_numMsg
        FD_ISEDITABLE,    // FIELD_msgType
        FD_ISEDITABLE,    // FIELD_sourceId
        FD_ISEDITABLE,    // FIELD_destinationId
        FD_ISEDITABLE,    // FIELD_antecessorId
        FD_ISEDITABLE,    // FIELD_nextId
        FD_ISEDITABLE,    // FIELD_sourceX
        FD_ISEDITABLE,    // FIELD_sourceY
        FD_ISEDITABLE,    // FIELD_sourceZ
        FD_ISEDITABLE,    // FIELD_antecessorX
        FD_ISEDITABLE,    // FIELD_antecessorY
        FD_ISEDITABLE,    // FIELD_antecessorZ
        FD_ISEDITABLE,    // FIELD_nextX
        FD_ISEDITABLE,    // FIELD_nextY
        FD_ISEDITABLE,    // FIELD_nextZ
        FD_ISEDITABLE,    // FIELD_destinationX
        FD_ISEDITABLE,    // FIELD_destinationY
        FD_ISEDITABLE,    // FIELD_destinationZ
        FD_ISEDITABLE,    // FIELD_sourceMaxSpeed
        FD_ISEDITABLE,    // FIELD_antecessorMaxSpeed
        FD_ISEDITABLE,    // FIELD_nextMaxSpeed
        FD_ISEDITABLE,    // FIELD_destinationMaxSpeed
        FD_ISEDITABLE,    // FIELD_sourceAngle
        FD_ISEDITABLE,    // FIELD_antecessorAngle
        FD_ISEDITABLE,    // FIELD_nextAngle
        FD_ISEDITABLE,    // FIELD_destinationAngle
        FD_ISEDITABLE,    // FIELD_sourceAceleration
        FD_ISEDITABLE,    // FIELD_antecessorAceleration
        FD_ISEDITABLE,    // FIELD_nextAceleration
        FD_ISEDITABLE,    // FIELD_destinationAceleration
        FD_ISEDITABLE,    // FIELD_sourceSpeed
        FD_ISEDITABLE,    // FIELD_antecessorSpeed
        FD_ISEDITABLE,    // FIELD_nextSpeed
        FD_ISEDITABLE,    // FIELD_destinationSpeed
        0,    // FIELD_anteNextValidityTimeStamp
        0,    // FIELD_sourceMsgTimeStamp
        0,    // FIELD_antecessorMsgTimeStamp
        0,    // FIELD_msgLifeTime
        0,    // FIELD_AntecessoPosTimeStamp
        0,    // FIELD_SourcePosTimeStamp
        0,    // FIELD_nextPosTimeStamp
        0,    // FIELD_destinationPosTimeStamp
        0,    // FIELD_validityDataTimeStamp
        FD_ISEDITABLE,    // FIELD_hopNumber
    };
    return (field >= 0 && field < 44) ? fieldTypeFlags[field] : 0;
}

const char *ICMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "numMsg",
        "msgType",
        "sourceId",
        "destinationId",
        "antecessorId",
        "nextId",
        "sourceX",
        "sourceY",
        "sourceZ",
        "antecessorX",
        "antecessorY",
        "antecessorZ",
        "nextX",
        "nextY",
        "nextZ",
        "destinationX",
        "destinationY",
        "destinationZ",
        "sourceMaxSpeed",
        "antecessorMaxSpeed",
        "nextMaxSpeed",
        "destinationMaxSpeed",
        "sourceAngle",
        "antecessorAngle",
        "nextAngle",
        "destinationAngle",
        "sourceAceleration",
        "antecessorAceleration",
        "nextAceleration",
        "destinationAceleration",
        "sourceSpeed",
        "antecessorSpeed",
        "nextSpeed",
        "destinationSpeed",
        "anteNextValidityTimeStamp",
        "sourceMsgTimeStamp",
        "antecessorMsgTimeStamp",
        "msgLifeTime",
        "AntecessoPosTimeStamp",
        "SourcePosTimeStamp",
        "nextPosTimeStamp",
        "destinationPosTimeStamp",
        "validityDataTimeStamp",
        "hopNumber",
    };
    return (field >= 0 && field < 44) ? fieldNames[field] : nullptr;
}

int ICMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "numMsg") == 0) return base+0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "msgType") == 0) return base+1;
    if (fieldName[0] == 's' && strcmp(fieldName, "sourceId") == 0) return base+2;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destinationId") == 0) return base+3;
    if (fieldName[0] == 'a' && strcmp(fieldName, "antecessorId") == 0) return base+4;
    if (fieldName[0] == 'n' && strcmp(fieldName, "nextId") == 0) return base+5;
    if (fieldName[0] == 's' && strcmp(fieldName, "sourceX") == 0) return base+6;
    if (fieldName[0] == 's' && strcmp(fieldName, "sourceY") == 0) return base+7;
    if (fieldName[0] == 's' && strcmp(fieldName, "sourceZ") == 0) return base+8;
    if (fieldName[0] == 'a' && strcmp(fieldName, "antecessorX") == 0) return base+9;
    if (fieldName[0] == 'a' && strcmp(fieldName, "antecessorY") == 0) return base+10;
    if (fieldName[0] == 'a' && strcmp(fieldName, "antecessorZ") == 0) return base+11;
    if (fieldName[0] == 'n' && strcmp(fieldName, "nextX") == 0) return base+12;
    if (fieldName[0] == 'n' && strcmp(fieldName, "nextY") == 0) return base+13;
    if (fieldName[0] == 'n' && strcmp(fieldName, "nextZ") == 0) return base+14;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destinationX") == 0) return base+15;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destinationY") == 0) return base+16;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destinationZ") == 0) return base+17;
    if (fieldName[0] == 's' && strcmp(fieldName, "sourceMaxSpeed") == 0) return base+18;
    if (fieldName[0] == 'a' && strcmp(fieldName, "antecessorMaxSpeed") == 0) return base+19;
    if (fieldName[0] == 'n' && strcmp(fieldName, "nextMaxSpeed") == 0) return base+20;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destinationMaxSpeed") == 0) return base+21;
    if (fieldName[0] == 's' && strcmp(fieldName, "sourceAngle") == 0) return base+22;
    if (fieldName[0] == 'a' && strcmp(fieldName, "antecessorAngle") == 0) return base+23;
    if (fieldName[0] == 'n' && strcmp(fieldName, "nextAngle") == 0) return base+24;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destinationAngle") == 0) return base+25;
    if (fieldName[0] == 's' && strcmp(fieldName, "sourceAceleration") == 0) return base+26;
    if (fieldName[0] == 'a' && strcmp(fieldName, "antecessorAceleration") == 0) return base+27;
    if (fieldName[0] == 'n' && strcmp(fieldName, "nextAceleration") == 0) return base+28;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destinationAceleration") == 0) return base+29;
    if (fieldName[0] == 's' && strcmp(fieldName, "sourceSpeed") == 0) return base+30;
    if (fieldName[0] == 'a' && strcmp(fieldName, "antecessorSpeed") == 0) return base+31;
    if (fieldName[0] == 'n' && strcmp(fieldName, "nextSpeed") == 0) return base+32;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destinationSpeed") == 0) return base+33;
    if (fieldName[0] == 'a' && strcmp(fieldName, "anteNextValidityTimeStamp") == 0) return base+34;
    if (fieldName[0] == 's' && strcmp(fieldName, "sourceMsgTimeStamp") == 0) return base+35;
    if (fieldName[0] == 'a' && strcmp(fieldName, "antecessorMsgTimeStamp") == 0) return base+36;
    if (fieldName[0] == 'm' && strcmp(fieldName, "msgLifeTime") == 0) return base+37;
    if (fieldName[0] == 'A' && strcmp(fieldName, "AntecessoPosTimeStamp") == 0) return base+38;
    if (fieldName[0] == 'S' && strcmp(fieldName, "SourcePosTimeStamp") == 0) return base+39;
    if (fieldName[0] == 'n' && strcmp(fieldName, "nextPosTimeStamp") == 0) return base+40;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destinationPosTimeStamp") == 0) return base+41;
    if (fieldName[0] == 'v' && strcmp(fieldName, "validityDataTimeStamp") == 0) return base+42;
    if (fieldName[0] == 'h' && strcmp(fieldName, "hopNumber") == 0) return base+43;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ICMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned long",    // FIELD_numMsg
        "int",    // FIELD_msgType
        "long",    // FIELD_sourceId
        "long",    // FIELD_destinationId
        "long",    // FIELD_antecessorId
        "long",    // FIELD_nextId
        "float",    // FIELD_sourceX
        "float",    // FIELD_sourceY
        "float",    // FIELD_sourceZ
        "float",    // FIELD_antecessorX
        "float",    // FIELD_antecessorY
        "float",    // FIELD_antecessorZ
        "float",    // FIELD_nextX
        "float",    // FIELD_nextY
        "float",    // FIELD_nextZ
        "float",    // FIELD_destinationX
        "float",    // FIELD_destinationY
        "float",    // FIELD_destinationZ
        "float",    // FIELD_sourceMaxSpeed
        "float",    // FIELD_antecessorMaxSpeed
        "float",    // FIELD_nextMaxSpeed
        "float",    // FIELD_destinationMaxSpeed
        "float",    // FIELD_sourceAngle
        "float",    // FIELD_antecessorAngle
        "float",    // FIELD_nextAngle
        "float",    // FIELD_destinationAngle
        "float",    // FIELD_sourceAceleration
        "float",    // FIELD_antecessorAceleration
        "float",    // FIELD_nextAceleration
        "float",    // FIELD_destinationAceleration
        "float",    // FIELD_sourceSpeed
        "float",    // FIELD_antecessorSpeed
        "float",    // FIELD_nextSpeed
        "float",    // FIELD_destinationSpeed
        "omnetpp::simtime_t",    // FIELD_anteNextValidityTimeStamp
        "omnetpp::simtime_t",    // FIELD_sourceMsgTimeStamp
        "omnetpp::simtime_t",    // FIELD_antecessorMsgTimeStamp
        "omnetpp::simtime_t",    // FIELD_msgLifeTime
        "omnetpp::simtime_t",    // FIELD_AntecessoPosTimeStamp
        "omnetpp::simtime_t",    // FIELD_SourcePosTimeStamp
        "omnetpp::simtime_t",    // FIELD_nextPosTimeStamp
        "omnetpp::simtime_t",    // FIELD_destinationPosTimeStamp
        "omnetpp::simtime_t",    // FIELD_validityDataTimeStamp
        "unsigned int",    // FIELD_hopNumber
    };
    return (field >= 0 && field < 44) ? fieldTypeStrings[field] : nullptr;
}

const char **ICMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *ICMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int ICMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ICMessage *pp = (ICMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ICMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ICMessage *pp = (ICMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ICMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ICMessage *pp = (ICMessage *)object; (void)pp;
    switch (field) {
        case FIELD_numMsg: return ulong2string(pp->getNumMsg());
        case FIELD_msgType: return long2string(pp->getMsgType());
        case FIELD_sourceId: return long2string(pp->getSourceId());
        case FIELD_destinationId: return long2string(pp->getDestinationId());
        case FIELD_antecessorId: return long2string(pp->getAntecessorId());
        case FIELD_nextId: return long2string(pp->getNextId());
        case FIELD_sourceX: return double2string(pp->getSourceX());
        case FIELD_sourceY: return double2string(pp->getSourceY());
        case FIELD_sourceZ: return double2string(pp->getSourceZ());
        case FIELD_antecessorX: return double2string(pp->getAntecessorX());
        case FIELD_antecessorY: return double2string(pp->getAntecessorY());
        case FIELD_antecessorZ: return double2string(pp->getAntecessorZ());
        case FIELD_nextX: return double2string(pp->getNextX());
        case FIELD_nextY: return double2string(pp->getNextY());
        case FIELD_nextZ: return double2string(pp->getNextZ());
        case FIELD_destinationX: return double2string(pp->getDestinationX());
        case FIELD_destinationY: return double2string(pp->getDestinationY());
        case FIELD_destinationZ: return double2string(pp->getDestinationZ());
        case FIELD_sourceMaxSpeed: return double2string(pp->getSourceMaxSpeed());
        case FIELD_antecessorMaxSpeed: return double2string(pp->getAntecessorMaxSpeed());
        case FIELD_nextMaxSpeed: return double2string(pp->getNextMaxSpeed());
        case FIELD_destinationMaxSpeed: return double2string(pp->getDestinationMaxSpeed());
        case FIELD_sourceAngle: return double2string(pp->getSourceAngle());
        case FIELD_antecessorAngle: return double2string(pp->getAntecessorAngle());
        case FIELD_nextAngle: return double2string(pp->getNextAngle());
        case FIELD_destinationAngle: return double2string(pp->getDestinationAngle());
        case FIELD_sourceAceleration: return double2string(pp->getSourceAceleration());
        case FIELD_antecessorAceleration: return double2string(pp->getAntecessorAceleration());
        case FIELD_nextAceleration: return double2string(pp->getNextAceleration());
        case FIELD_destinationAceleration: return double2string(pp->getDestinationAceleration());
        case FIELD_sourceSpeed: return double2string(pp->getSourceSpeed());
        case FIELD_antecessorSpeed: return double2string(pp->getAntecessorSpeed());
        case FIELD_nextSpeed: return double2string(pp->getNextSpeed());
        case FIELD_destinationSpeed: return double2string(pp->getDestinationSpeed());
        case FIELD_anteNextValidityTimeStamp: return simtime2string(pp->getAnteNextValidityTimeStamp());
        case FIELD_sourceMsgTimeStamp: return simtime2string(pp->getSourceMsgTimeStamp());
        case FIELD_antecessorMsgTimeStamp: return simtime2string(pp->getAntecessorMsgTimeStamp());
        case FIELD_msgLifeTime: return simtime2string(pp->getMsgLifeTime());
        case FIELD_AntecessoPosTimeStamp: return simtime2string(pp->getAntecessoPosTimeStamp());
        case FIELD_SourcePosTimeStamp: return simtime2string(pp->getSourcePosTimeStamp());
        case FIELD_nextPosTimeStamp: return simtime2string(pp->getNextPosTimeStamp());
        case FIELD_destinationPosTimeStamp: return simtime2string(pp->getDestinationPosTimeStamp());
        case FIELD_validityDataTimeStamp: return simtime2string(pp->getValidityDataTimeStamp());
        case FIELD_hopNumber: return ulong2string(pp->getHopNumber());
        default: return "";
    }
}

bool ICMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ICMessage *pp = (ICMessage *)object; (void)pp;
    switch (field) {
        case FIELD_numMsg: pp->setNumMsg(string2ulong(value)); return true;
        case FIELD_msgType: pp->setMsgType(string2long(value)); return true;
        case FIELD_sourceId: pp->setSourceId(string2long(value)); return true;
        case FIELD_destinationId: pp->setDestinationId(string2long(value)); return true;
        case FIELD_antecessorId: pp->setAntecessorId(string2long(value)); return true;
        case FIELD_nextId: pp->setNextId(string2long(value)); return true;
        case FIELD_sourceX: pp->setSourceX(string2double(value)); return true;
        case FIELD_sourceY: pp->setSourceY(string2double(value)); return true;
        case FIELD_sourceZ: pp->setSourceZ(string2double(value)); return true;
        case FIELD_antecessorX: pp->setAntecessorX(string2double(value)); return true;
        case FIELD_antecessorY: pp->setAntecessorY(string2double(value)); return true;
        case FIELD_antecessorZ: pp->setAntecessorZ(string2double(value)); return true;
        case FIELD_nextX: pp->setNextX(string2double(value)); return true;
        case FIELD_nextY: pp->setNextY(string2double(value)); return true;
        case FIELD_nextZ: pp->setNextZ(string2double(value)); return true;
        case FIELD_destinationX: pp->setDestinationX(string2double(value)); return true;
        case FIELD_destinationY: pp->setDestinationY(string2double(value)); return true;
        case FIELD_destinationZ: pp->setDestinationZ(string2double(value)); return true;
        case FIELD_sourceMaxSpeed: pp->setSourceMaxSpeed(string2double(value)); return true;
        case FIELD_antecessorMaxSpeed: pp->setAntecessorMaxSpeed(string2double(value)); return true;
        case FIELD_nextMaxSpeed: pp->setNextMaxSpeed(string2double(value)); return true;
        case FIELD_destinationMaxSpeed: pp->setDestinationMaxSpeed(string2double(value)); return true;
        case FIELD_sourceAngle: pp->setSourceAngle(string2double(value)); return true;
        case FIELD_antecessorAngle: pp->setAntecessorAngle(string2double(value)); return true;
        case FIELD_nextAngle: pp->setNextAngle(string2double(value)); return true;
        case FIELD_destinationAngle: pp->setDestinationAngle(string2double(value)); return true;
        case FIELD_sourceAceleration: pp->setSourceAceleration(string2double(value)); return true;
        case FIELD_antecessorAceleration: pp->setAntecessorAceleration(string2double(value)); return true;
        case FIELD_nextAceleration: pp->setNextAceleration(string2double(value)); return true;
        case FIELD_destinationAceleration: pp->setDestinationAceleration(string2double(value)); return true;
        case FIELD_sourceSpeed: pp->setSourceSpeed(string2double(value)); return true;
        case FIELD_antecessorSpeed: pp->setAntecessorSpeed(string2double(value)); return true;
        case FIELD_nextSpeed: pp->setNextSpeed(string2double(value)); return true;
        case FIELD_destinationSpeed: pp->setDestinationSpeed(string2double(value)); return true;
        case FIELD_hopNumber: pp->setHopNumber(string2ulong(value)); return true;
        default: return false;
    }
}

const char *ICMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *ICMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ICMessage *pp = (ICMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace veins

