#include "chat_member_banned.h"

namespace bot::types {

ChatMemberBanned::ChatMemberBanned() : ChatMember() {}

ChatMemberBanned::ChatMemberBanned(std::string& json) : ChatMember(json) {
    fromString(json);
}

ChatMemberBanned::ChatMemberBanned(Value const& document) : ChatMember(document) {
    fromNestedObject(document);
}

ChatMemberBanned::ChatMemberBanned(
    User user, 
    std::string status, 
    int until_date
) : ChatMember(user, status), until_date(until_date) {}

void ChatMemberBanned::fillDocument(Writer& writer) const {
    ChatMember::fillDocument(writer);
    writer.Key(fields::UNTIL_DATE);
    writer.Int(until_date);
}

void ChatMemberBanned::fillObject(Value const& document) {
    until_date = document[fields::UNTIL_DATE].GetInt();
}

}
