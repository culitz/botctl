#pragma once
#include "chat_member.h"

namespace bot::types {

class ChatMemberLeft : public ChatMember {
public:
    ChatMemberLeft();
    ChatMemberLeft(std::string& json);
    ChatMemberLeft(Value const& document);
    ChatMemberLeft(User user, std::string status);
    virtual ~ChatMemberLeft() {}
};

}