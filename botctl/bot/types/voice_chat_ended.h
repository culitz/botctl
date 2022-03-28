#pragma once
#include "base_object.h"
#include "fields.h"


namespace bot::types {

class VoiceChatEnded : public BaseObject {
public:
    int duration;
    VoiceChatEnded();
    VoiceChatEnded(string&);
    VoiceChatEnded(const Value&);
    VoiceChatEnded(int);
    virtual ~VoiceChatEnded();
protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Value const& document);
};

}