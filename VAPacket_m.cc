//
// Generated file, do not edit! Created by opp_msgc 4.4 from VAPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "VAPacket_m.h"

USING_NAMESPACE

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("VAType");
    if (!e) enums.getInstance()->add(e = new cEnum("VAType"));
    e->insert(RSU_BEACON, "RSU_BEACON");
    e->insert(RSU_BEACON_REPLY, "RSU_BEACON_REPLY");
    e->insert(RSU_BASESTATION_FORWARD, "RSU_BASESTATION_FORWARD");
    e->insert(APP_DATA, "APP_DATA");
);

Register_Class(VAPacket);

VAPacket::VAPacket(const char *name, int kind) : cPacket(name,kind)
{
    this->sourcePrefix_var = 0;
    this->sourceSuffix_var = 0;
    this->destPrefix_var = 0;
    this->destSuffix_var = 0;
    this->key_var = 0;
    this->type_var = 0;
}

VAPacket::VAPacket(const VAPacket& other) : cPacket(other)
{
    copy(other);
}

VAPacket::~VAPacket()
{
}

VAPacket& VAPacket::operator=(const VAPacket& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void VAPacket::copy(const VAPacket& other)
{
    this->sourcePrefix_var = other.sourcePrefix_var;
    this->sourceSuffix_var = other.sourceSuffix_var;
    this->destPrefix_var = other.destPrefix_var;
    this->destSuffix_var = other.destSuffix_var;
    this->key_var = other.key_var;
    this->type_var = other.type_var;
}

void VAPacket::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->sourcePrefix_var);
    doPacking(b,this->sourceSuffix_var);
    doPacking(b,this->destPrefix_var);
    doPacking(b,this->destSuffix_var);
    doPacking(b,this->key_var);
    doPacking(b,this->type_var);
}

void VAPacket::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->sourcePrefix_var);
    doUnpacking(b,this->sourceSuffix_var);
    doUnpacking(b,this->destPrefix_var);
    doUnpacking(b,this->destSuffix_var);
    doUnpacking(b,this->key_var);
    doUnpacking(b,this->type_var);
}

int VAPacket::getSourcePrefix() const
{
    return sourcePrefix_var;
}

void VAPacket::setSourcePrefix(int sourcePrefix)
{
    this->sourcePrefix_var = sourcePrefix;
}

int VAPacket::getSourceSuffix() const
{
    return sourceSuffix_var;
}

void VAPacket::setSourceSuffix(int sourceSuffix)
{
    this->sourceSuffix_var = sourceSuffix;
}

int VAPacket::getDestPrefix() const
{
    return destPrefix_var;
}

void VAPacket::setDestPrefix(int destPrefix)
{
    this->destPrefix_var = destPrefix;
}

int VAPacket::getDestSuffix() const
{
    return destSuffix_var;
}

void VAPacket::setDestSuffix(int destSuffix)
{
    this->destSuffix_var = destSuffix;
}

int VAPacket::getKey() const
{
    return key_var;
}

void VAPacket::setKey(int key)
{
    this->key_var = key;
}

int VAPacket::getType() const
{
    return type_var;
}

void VAPacket::setType(int type)
{
    this->type_var = type;
}

class VAPacketDescriptor : public cClassDescriptor
{
  public:
    VAPacketDescriptor();
    virtual ~VAPacketDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(VAPacketDescriptor);

VAPacketDescriptor::VAPacketDescriptor() : cClassDescriptor("VAPacket", "cPacket")
{
}

VAPacketDescriptor::~VAPacketDescriptor()
{
}

bool VAPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<VAPacket *>(obj)!=NULL;
}

const char *VAPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int VAPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int VAPacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *VAPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "sourcePrefix",
        "sourceSuffix",
        "destPrefix",
        "destSuffix",
        "key",
        "type",
    };
    return (field>=0 && field<6) ? fieldNames[field] : NULL;
}

int VAPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourcePrefix")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceSuffix")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "destPrefix")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "destSuffix")==0) return base+3;
    if (fieldName[0]=='k' && strcmp(fieldName, "key")==0) return base+4;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+5;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *VAPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : NULL;
}

const char *VAPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 5:
            if (!strcmp(propertyname,"enum")) return "VAType";
            return NULL;
        default: return NULL;
    }
}

int VAPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    VAPacket *pp = (VAPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string VAPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    VAPacket *pp = (VAPacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSourcePrefix());
        case 1: return long2string(pp->getSourceSuffix());
        case 2: return long2string(pp->getDestPrefix());
        case 3: return long2string(pp->getDestSuffix());
        case 4: return long2string(pp->getKey());
        case 5: return long2string(pp->getType());
        default: return "";
    }
}

bool VAPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    VAPacket *pp = (VAPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setSourcePrefix(string2long(value)); return true;
        case 1: pp->setSourceSuffix(string2long(value)); return true;
        case 2: pp->setDestPrefix(string2long(value)); return true;
        case 3: pp->setDestSuffix(string2long(value)); return true;
        case 4: pp->setKey(string2long(value)); return true;
        case 5: pp->setType(string2long(value)); return true;
        default: return false;
    }
}

const char *VAPacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<6) ? fieldStructNames[field] : NULL;
}

void *VAPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    VAPacket *pp = (VAPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


