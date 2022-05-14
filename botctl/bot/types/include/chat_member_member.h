#include "chat_member.h"

namespace bot::types {

class ChatMemberMember : public ChatMember {
public:
    ChatMemberMember();
    ChatMemberMember(std::string& json);
    ChatMemberMember(Value const& document);
    ChatMemberMember(User user, std::string status);

    virtual ~ChatMemberMember() {}
};

}