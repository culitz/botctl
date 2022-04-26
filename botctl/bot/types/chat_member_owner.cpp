#include "chat_member_owner.h"


namespace bot::types {

ChatMemberOwner::ChatMemberOwner() : ChatMember() {

}

ChatMemberOwner::ChatMemberOwner(std::string& json) : ChatMember() {
    ChatMember::fromString(json);
    fromString(json);
}

ChatMemberOwner::ChatMemberOwner(Value const& value) : ChatMember() {
    ChatMember::fromNestedObject(value);
    fromNestedObject(value);
}

ChatMemberOwner::ChatMemberOwner(
    User        user, 
    std::string status,
    bool        is_anonymous,
    std::string custom_title
) : ChatMember(user, status),
    is_anonymous(is_anonymous),
    custom_title(custom_title) {

}

void ChatMemberOwner::fillDocument(Writer& writer) const {
    ChatMember::fillDocument(writer);
    writer.Key(fields::IS_ANONYMOUS);
    writer.Bool(is_anonymous);
    writer.Key(fields::CUSTOM_TITLE);
    writer.String(custom_title.c_str());
}

void ChatMemberOwner::fillObject(Value const& document) {
    ChatMember::fillObject(document);
    is_anonymous = document[fields::IS_ANONYMOUS].GetBool();
    custom_title = document[fields::CUSTOM_TITLE].GetString();
}


}