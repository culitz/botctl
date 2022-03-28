#pragma once
#include <vector>
#include "base_object.h"
#include "fields.h"
#include "user.h"


namespace bot::types {

class VoiceChatParticipantsInvited : public BaseObject {
public:
    std::vector<User> users;
    VoiceChatParticipantsInvited();
    VoiceChatParticipantsInvited(string&);
    VoiceChatParticipantsInvited(const Value&);
    VoiceChatParticipantsInvited(std::vector<User>&);
    virtual ~VoiceChatParticipantsInvited();

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Value const& document);
};

}