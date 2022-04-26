#include "chat_member.h"

namespace bot::types {

ChatMember::ChatMember() : BaseObject() {

}

ChatMember::ChatMember(std::string& json) : BaseObject() {
    fromString(json);
}

ChatMember::ChatMember(Value const& document) : BaseObject() {
    fromNestedObject(document);
}

ChatMember::ChatMember(User user, std::string status) : 
    BaseObject(),
    user(user),
    status(status) {

}

ChatMember::~ChatMember() {}

void ChatMember::fillDocument(Writer& writer) const {
    writer.Key(fields::USER);
    user.asNestedObject(writer);
    writer.Key(fields::STATUS);
    writer.String(status.c_str());
}

void ChatMember::fillObject(Value const& document) {
    user.fromNestedObject(document[fields::USER]);
    status = document[fields::STATUS].GetString();
}

}