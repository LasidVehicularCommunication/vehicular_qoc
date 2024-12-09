//
// Generated file, do not edit! Created by nedtool 5.6 from veins/modules/application/icarnew/messages/ICRMessage.msg.
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
#include "ICRMessage_m.h"

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

Register_Class(ICRMessage)

ICRMessage::ICRMessage(const char *name) : ::veins::BaseFrame1609_4(name)
{
}

ICRMessage::ICRMessage(const ICRMessage& other) : ::veins::BaseFrame1609_4(other)
{
    copy(other);
}

ICRMessage::~ICRMessage()
{
}

ICRMessage& ICRMessage::operator=(const ICRMessage& other)
{
    if (this == &other) return *this;
    ::veins::BaseFrame1609_4::operator=(other);
    copy(other);
    return *this;
}

void ICRMessage::copy(const ICRMessage& other)
{
    this->numMsg = other.numMsg;
    this->msgType = other.msgType;
    this->msgLifeTime = other.msgLifeTime;
    this->validityDataTimeStamp = other.validityDataTimeStamp;
    this->confidence = other.confidence;
    this->hopNumber = other.hopNumber;
    this->msgTimeStamp = other.msgTimeStamp;
    this->sourceNode = other.sourceNode;
    this->transmissorNode = other.transmissorNode;
    this->nextNode = other.nextNode;
    this->destinyNode = other.destinyNode;
}

void ICRMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::veins::BaseFrame1609_4::parsimPack(b);
    doParsimPacking(b,this->numMsg);
    doParsimPacking(b,this->msgType);
    doParsimPacking(b,this->msgLifeTime);
    doParsimPacking(b,this->validityDataTimeStamp);
    doParsimPacking(b,this->confidence);
    doParsimPacking(b,this->hopNumber);
    doParsimPacking(b,this->msgTimeStamp);
    doParsimPacking(b,this->sourceNode);
    doParsimPacking(b,this->transmissorNode);
    doParsimPacking(b,this->nextNode);
    doParsimPacking(b,this->destinyNode);
}

void ICRMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::veins::BaseFrame1609_4::parsimUnpack(b);
    doParsimUnpacking(b,this->numMsg);
    doParsimUnpacking(b,this->msgType);
    doParsimUnpacking(b,this->msgLifeTime);
    doParsimUnpacking(b,this->validityDataTimeStamp);
    doParsimUnpacking(b,this->confidence);
    doParsimUnpacking(b,this->hopNumber);
    doParsimUnpacking(b,this->msgTimeStamp);
    doParsimUnpacking(b,this->sourceNode);
    doParsimUnpacking(b,this->transmissorNode);
    doParsimUnpacking(b,this->nextNode);
    doParsimUnpacking(b,this->destinyNode);
}

unsigned long ICRMessage::getNumMsg() const
{
    return this->numMsg;
}

void ICRMessage::setNumMsg(unsigned long numMsg)
{
    this->numMsg = numMsg;
}

int ICRMessage::getMsgType() const
{
    return this->msgType;
}

void ICRMessage::setMsgType(int msgType)
{
    this->msgType = msgType;
}

omnetpp::simtime_t ICRMessage::getMsgLifeTime() const
{
    return this->msgLifeTime;
}

void ICRMessage::setMsgLifeTime(omnetpp::simtime_t msgLifeTime)
{
    this->msgLifeTime = msgLifeTime;
}

omnetpp::simtime_t ICRMessage::getValidityDataTimeStamp() const
{
    return this->validityDataTimeStamp;
}

void ICRMessage::setValidityDataTimeStamp(omnetpp::simtime_t validityDataTimeStamp)
{
    this->validityDataTimeStamp = validityDataTimeStamp;
}

double ICRMessage::getConfidence() const
{
    return this->confidence;
}

void ICRMessage::setConfidence(double confidence)
{
    this->confidence = confidence;
}

unsigned int ICRMessage::getHopNumber() const
{
    return this->hopNumber;
}

void ICRMessage::setHopNumber(unsigned int hopNumber)
{
    this->hopNumber = hopNumber;
}

omnetpp::simtime_t ICRMessage::getMsgTimeStamp() const
{
    return this->msgTimeStamp;
}

void ICRMessage::setMsgTimeStamp(omnetpp::simtime_t msgTimeStamp)
{
    this->msgTimeStamp = msgTimeStamp;
}

const ICRNode& ICRMessage::getSourceNode() const
{
    return this->sourceNode;
}

void ICRMessage::setSourceNode(const ICRNode& sourceNode)
{
    this->sourceNode = sourceNode;
}

const ICRNode& ICRMessage::getTransmissorNode() const
{
    return this->transmissorNode;
}

void ICRMessage::setTransmissorNode(const ICRNode& transmissorNode)
{
    this->transmissorNode = transmissorNode;
}

const ICRNode& ICRMessage::getNextNode() const
{
    return this->nextNode;
}

void ICRMessage::setNextNode(const ICRNode& nextNode)
{
    this->nextNode = nextNode;
}

const ICRNode& ICRMessage::getDestinyNode() const
{
    return this->destinyNode;
}

void ICRMessage::setDestinyNode(const ICRNode& destinyNode)
{
    this->destinyNode = destinyNode;
}

class ICRMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_numMsg,
        FIELD_msgType,
        FIELD_msgLifeTime,
        FIELD_validityDataTimeStamp,
        FIELD_confidence,
        FIELD_hopNumber,
        FIELD_msgTimeStamp,
        FIELD_sourceNode,
        FIELD_transmissorNode,
        FIELD_nextNode,
        FIELD_destinyNode,
    };
  public:
    ICRMessageDescriptor();
    virtual ~ICRMessageDescriptor();

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

Register_ClassDescriptor(ICRMessageDescriptor)

ICRMessageDescriptor::ICRMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(veins::ICRMessage)), "veins::BaseFrame1609_4")
{
    propertynames = nullptr;
}

ICRMessageDescriptor::~ICRMessageDescriptor()
{
    delete[] propertynames;
}

bool ICRMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ICRMessage *>(obj)!=nullptr;
}

const char **ICRMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ICRMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ICRMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 11+basedesc->getFieldCount() : 11;
}

unsigned int ICRMessageDescriptor::getFieldTypeFlags(int field) const
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
        0,    // FIELD_msgLifeTime
        0,    // FIELD_validityDataTimeStamp
        FD_ISEDITABLE,    // FIELD_confidence
        FD_ISEDITABLE,    // FIELD_hopNumber
        0,    // FIELD_msgTimeStamp
        FD_ISCOMPOUND,    // FIELD_sourceNode
        FD_ISCOMPOUND,    // FIELD_transmissorNode
        FD_ISCOMPOUND,    // FIELD_nextNode
        FD_ISCOMPOUND,    // FIELD_destinyNode
    };
    return (field >= 0 && field < 11) ? fieldTypeFlags[field] : 0;
}

const char *ICRMessageDescriptor::getFieldName(int field) const
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
        "msgLifeTime",
        "validityDataTimeStamp",
        "confidence",
        "hopNumber",
        "msgTimeStamp",
        "sourceNode",
        "transmissorNode",
        "nextNode",
        "destinyNode",
    };
    return (field >= 0 && field < 11) ? fieldNames[field] : nullptr;
}

int ICRMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "numMsg") == 0) return base+0;
    if (fieldName[0] == 'm' && strcmp(fieldName, "msgType") == 0) return base+1;
    if (fieldName[0] == 'm' && strcmp(fieldName, "msgLifeTime") == 0) return base+2;
    if (fieldName[0] == 'v' && strcmp(fieldName, "validityDataTimeStamp") == 0) return base+3;
    if (fieldName[0] == 'c' && strcmp(fieldName, "confidence") == 0) return base+4;
    if (fieldName[0] == 'h' && strcmp(fieldName, "hopNumber") == 0) return base+5;
    if (fieldName[0] == 'm' && strcmp(fieldName, "msgTimeStamp") == 0) return base+6;
    if (fieldName[0] == 's' && strcmp(fieldName, "sourceNode") == 0) return base+7;
    if (fieldName[0] == 't' && strcmp(fieldName, "transmissorNode") == 0) return base+8;
    if (fieldName[0] == 'n' && strcmp(fieldName, "nextNode") == 0) return base+9;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destinyNode") == 0) return base+10;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ICRMessageDescriptor::getFieldTypeString(int field) const
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
        "omnetpp::simtime_t",    // FIELD_msgLifeTime
        "omnetpp::simtime_t",    // FIELD_validityDataTimeStamp
        "double",    // FIELD_confidence
        "unsigned int",    // FIELD_hopNumber
        "omnetpp::simtime_t",    // FIELD_msgTimeStamp
        "veins::ICRNode",    // FIELD_sourceNode
        "veins::ICRNode",    // FIELD_transmissorNode
        "veins::ICRNode",    // FIELD_nextNode
        "veins::ICRNode",    // FIELD_destinyNode
    };
    return (field >= 0 && field < 11) ? fieldTypeStrings[field] : nullptr;
}

const char **ICRMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *ICRMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int ICRMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ICRMessage *pp = (ICRMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ICRMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ICRMessage *pp = (ICRMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ICRMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ICRMessage *pp = (ICRMessage *)object; (void)pp;
    switch (field) {
        case FIELD_numMsg: return ulong2string(pp->getNumMsg());
        case FIELD_msgType: return long2string(pp->getMsgType());
        case FIELD_msgLifeTime: return simtime2string(pp->getMsgLifeTime());
        case FIELD_validityDataTimeStamp: return simtime2string(pp->getValidityDataTimeStamp());
        case FIELD_confidence: return double2string(pp->getConfidence());
        case FIELD_hopNumber: return ulong2string(pp->getHopNumber());
        case FIELD_msgTimeStamp: return simtime2string(pp->getMsgTimeStamp());
        case FIELD_sourceNode: {std::stringstream out; out << pp->getSourceNode(); return out.str();}
        case FIELD_transmissorNode: {std::stringstream out; out << pp->getTransmissorNode(); return out.str();}
        case FIELD_nextNode: {std::stringstream out; out << pp->getNextNode(); return out.str();}
        case FIELD_destinyNode: {std::stringstream out; out << pp->getDestinyNode(); return out.str();}
        default: return "";
    }
}

bool ICRMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ICRMessage *pp = (ICRMessage *)object; (void)pp;
    switch (field) {
        case FIELD_numMsg: pp->setNumMsg(string2ulong(value)); return true;
        case FIELD_msgType: pp->setMsgType(string2long(value)); return true;
        case FIELD_confidence: pp->setConfidence(string2double(value)); return true;
        case FIELD_hopNumber: pp->setHopNumber(string2ulong(value)); return true;
        default: return false;
    }
}

const char *ICRMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_sourceNode: return omnetpp::opp_typename(typeid(ICRNode));
        case FIELD_transmissorNode: return omnetpp::opp_typename(typeid(ICRNode));
        case FIELD_nextNode: return omnetpp::opp_typename(typeid(ICRNode));
        case FIELD_destinyNode: return omnetpp::opp_typename(typeid(ICRNode));
        default: return nullptr;
    };
}

void *ICRMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ICRMessage *pp = (ICRMessage *)object; (void)pp;
    switch (field) {
        case FIELD_sourceNode: return toVoidPtr(&pp->getSourceNode()); break;
        case FIELD_transmissorNode: return toVoidPtr(&pp->getTransmissorNode()); break;
        case FIELD_nextNode: return toVoidPtr(&pp->getNextNode()); break;
        case FIELD_destinyNode: return toVoidPtr(&pp->getDestinyNode()); break;
        default: return nullptr;
    }
}

} // namespace veins

