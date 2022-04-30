#include "chat_member_member.h"

namespace bot::types {

ChatMemberMember::ChatMemberMember() : ChatMember() {}

ChatMemberMember::ChatMemberMember(std::string& json) : ChatMember(json) {}
ChatMemberMember::ChatMemberMember(Value const& document) : 
    ChatMember(document) {}

ChatMemberMember::ChatMemberMember(User user, std::string status) :
    ChatMember(user, status) {}

}