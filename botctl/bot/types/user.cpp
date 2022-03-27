#include "user.h"

namespace bot::types {


User::User() : BaseObject() {}

User::User(Value const& value) : BaseObject(value) {}

User::User(string& json) : BaseObject() {
    fromString(json);
}

User::User(const User &user) : BaseObject(user) {
    is_bot = user.is_bot;
    first_name = user.first_name;
} 

User::~User() {}

void User::fromNestedObject(const Value &value) {
    Parent::fromNestedObject(value);
    is_bot = value[IS_BOT.c_str()].GetBool();
    first_name = value[FIRST_NAME.c_str()].GetString();
    last_name = getOptString(value, LAST_NAME);
    username = getOptString(value, USERNAME);
    language_code = getOptString(value, LANGUAGE_CODE);
    can_join_groups = getOptBool(value, CAN_JOIN_GROUPS);
    can_read_all_group_messages = getOptBool(value, CAN_READ_ALL_GROUP_MESSAGES);
    supports_inline_queries = getOptBool(value, SUPPORT_INLINE_QUERIES);
}

void User::fillObject(rapidjson::Value const &document) {
    Parent::fillObject(document);
    is_bot = document[IS_BOT.c_str()].GetBool();
    first_name = document[FIRST_NAME.c_str()].GetString();
    last_name = getOptString(document, LAST_NAME);
    username = getOptString(document, USERNAME);
    language_code = getOptString(document, LANGUAGE_CODE);
    can_join_groups = getOptBool(document, CAN_JOIN_GROUPS);
    can_read_all_group_messages = getOptBool(document, CAN_READ_ALL_GROUP_MESSAGES);
    supports_inline_queries = getOptBool(document, SUPPORT_INLINE_QUERIES);
}

void User::fillDocument(Writer &writer) const {
    Parent::fillDocument(writer);
    writer.Key(IS_BOT.c_str());
    writer.Bool(is_bot);

    writer.Key(FIRST_NAME.c_str());
    writer.String(first_name.c_str());

    if(last_name){
        writer.Key(LAST_NAME.c_str());
        writer.String(last_name->c_str());
    }
    if(username) {
        writer.Key(USERNAME.c_str());
        writer.String(username->c_str());
    }
    if(language_code) {
        writer.Key(LANGUAGE_CODE.c_str());
        writer.String(language_code->c_str());
    }
    if(can_join_groups) {
        writer.Key(CAN_JOIN_GROUPS.c_str());
        writer.Bool(*can_join_groups);
    }

    if(supports_inline_queries){
        writer.Key(SUPPORT_INLINE_QUERIES.c_str());
        writer.Bool(*supports_inline_queries);
    }
}



}
