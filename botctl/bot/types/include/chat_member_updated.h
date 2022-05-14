#include "base_object.h"
#include "user.h"
#include "chat.h"
#include "chat_member.h"
#include "chat_invite_link.h"
#include "fields.h"


namespace bot::types {

class ChatMemberUpdated : public BaseObject {
public:
    Chat                            chat;
    User                            from;
    int                             date;
    ChatMember                      old_chat_member;
    ChatMember                      new_chat_member;
    std::optional<ChatInviteLink>   invite_link;

    ChatMemberUpdated();
    ChatMemberUpdated(std::string& json);
    ChatMemberUpdated(Value const& document);
    ChatMemberUpdated(
        Chat chat,
        User from,
        int date,
        ChatMember old_chat_member,
        ChatMember new_chat_member,
        std::optional<ChatInviteLink> invite_link = {}
    );
    virtual ~ChatMemberUpdated() {}

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Value const& document);
};

}