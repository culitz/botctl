#include "chat_member_updated.h"

namespace bot::types {

ChatMemberUpdated::ChatMemberUpdated() : BaseObject() {}

ChatMemberUpdated::ChatMemberUpdated(std::string& json) : BaseObject() {
    fromString(json);
}

ChatMemberUpdated::ChatMemberUpdated(Value const& document) : BaseObject() {
    fromNestedObject(document);
}

ChatMemberUpdated::ChatMemberUpdated(
    Chat chat,
    User from,
    int date,
    ChatMember old_chat_member,
    ChatMember new_chat_member,
    std::optional<ChatInviteLink> invite_link
) : BaseObject(),
    chat(chat),
    from(from),
    date(date),
    old_chat_member(old_chat_member),
    new_chat_member(new_chat_member),
    invite_link(invite_link)
{

}

void ChatMemberUpdated::fillDocument(Writer& writer) const {
    writer.Key(fields::CHAT);
    chat.asNestedObject(writer);

    writer.Key(fields::FROM);
    from.asNestedObject(writer);

    writer.Key(fields::DATE);
    writer.Int(date);

    writer.Key(fields::OLD_CHAT_MEMBER);
    old_chat_member.asNestedObject(writer);

    writer.Key(fields::NEW_CHAT_MEMBER);
    new_chat_member.asNestedObject(writer);

    if(invite_link) {
        writer.Key(fields::INVITE_LINK);
        invite_link->asNestedObject(writer);
    }
}

void ChatMemberUpdated::fillObject(Value const& document) {
    chat.fromNestedObject(document[fields::CHAT]);
    from.fromNestedObject(document[fields::FROM]);
    date = document[fields::DATE].GetInt();
    old_chat_member.fromNestedObject(document[fields::OLD_CHAT_MEMBER]); 
    new_chat_member.fromNestedObject(document[fields::NEW_CHAT_MEMBER]);
    
    if(document.HasMember(fields::INVITE_LINK)) 
        invite_link.emplace(ChatInviteLink(document[fields::INVITE_LINK]));
}

}
