#include "chat_join_request.h"

namespace bot::types {

ChatJoinRequest::ChatJoinRequest() : BaseObject() {

}

ChatJoinRequest::ChatJoinRequest(string& json) : BaseObject() {
    fromString(json);
}

ChatJoinRequest::ChatJoinRequest(Value const& document) : BaseObject() {
    fillObject(document);
}

ChatJoinRequest::ChatJoinRequest(
    Chat chat,
    User from,
    int date,
    std::optional<string> bio,
    std::optional<ChatInviteLink> invite_link
) : BaseObject(),
    chat(chat),
    from(from),
    date(date),
    bio(bio),
    invite_link(invite_link) {

}

void ChatJoinRequest::fillDocument(Writer& writer) const {
    writer.Key(fields::CHAT);
    chat.asNestedObject(writer);

    writer.Key(fields::FROM);
    from.asNestedObject(writer);

    writer.Key(fields::DATE);
    writer.Int(date);

    if(bio) {
        writer.Key(fields::BIO);
        writer.String(bio->c_str());
    }

    if(invite_link) {
        writer.Key(fields::INVITE_LINK);
        invite_link->asNestedObject(writer);
    }
}

void ChatJoinRequest::fillObject(Value const& document) {
    chat.fromNestedObject(document[fields::CHAT]);
    from.fromNestedObject(document[fields::FROM]);
    date = document[fields::DATE].GetInt();
    bio = getOptString(document, fields::BIO);
    if(document.HasMember(fields::INVITE_LINK))
        invite_link.emplace(ChatInviteLink(document[fields::INVITE_LINK]));
}

}
