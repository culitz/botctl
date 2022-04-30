#include "chat_member_left.h"

namespace bot::types {

ChatMemberLeft::ChatMemberLeft() : ChatMember(){}
ChatMemberLeft::ChatMemberLeft(std::string& json): ChatMember(json) {}
ChatMemberLeft::ChatMemberLeft(Value const& document) : ChatMember(document) {}
ChatMemberLeft::ChatMemberLeft(User user, std::string status) :
    ChatMember(user, status) {}

}