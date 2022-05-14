#include <gtest/gtest.h>
#include <message_entity.h>
#include <user.h>
#include <base_object.h>
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>

namespace test_message_entity
{

using MessageEntity = bot::types::MessageEntity;
using User = bot::types::User;
using string = std::string;
using optstring = std::optional<string>;
using BaseObject = bot::types::BaseObject;
using StringBuffer = rapidjson::StringBuffer;

string TYPE = "type";
int OFFSET = 500;
int LENGTH = 300;
string URL = "url";
string USER = "user";
string LANGUAGE = "language";

string dataSet()
{
    StringBuffer buffer;
    rapidjson::Writer<StringBuffer> writer(buffer);
    writer.StartObject();

    writer.Key(MessageEntity::TYPE.c_str());
    writer.String(TYPE.c_str());

    writer.Key(MessageEntity::OFFSET.c_str());
    writer.Int(OFFSET);

    writer.Key(MessageEntity::LENGTH.c_str());
    writer.Int(LENGTH);

    writer.Key(MessageEntity::URL.c_str());
    writer.String(URL.c_str());

    writer.Key(USER.c_str());
    User user;
    user.id = 123;
    user.first_name = "first_name";
    user.last_name = "last_name";
    user.asNestedObject(writer);

    writer.Key(MessageEntity::LANGUAGE.c_str());
    writer.String(LANGUAGE.c_str());
    writer.EndObject();
    return buffer.GetString();
}

TEST(type_message_entity, initialize_from_string)
{
    string json = dataSet();
    MessageEntity msg(json);
    ASSERT_EQ(msg.type, TYPE);
    ASSERT_EQ(msg.offset, OFFSET);
    ASSERT_EQ(msg.length, LENGTH);
    ASSERT_EQ(msg.url, URL);
    ASSERT_EQ(msg.language, LANGUAGE);
}


}
