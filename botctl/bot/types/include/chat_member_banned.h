#pragma once
#include "chat_member.h"

namespace bot::types {

class ChatMemberBanned : public ChatMember {
public:
    int until_date;

    ChatMemberBanned();
    ChatMemberBanned(std::string& json);
    ChatMemberBanned(Value const& document);
    ChatMemberBanned(User user, std::string status, int until_date);
    virtual ~ChatMemberBanned() {}

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Value const& document);
};

}