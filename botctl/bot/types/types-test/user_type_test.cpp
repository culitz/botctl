#include <gtest/gtest.h>
#include "../user.h"
#include "../base_object.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"


namespace test_user_type {


using User = bot::types::User;
using string = std::string;
using optstring = std::optional<string>;
using BaseObject = bot::types::BaseObject;

const int TEST_ID = 11;
const bool TEST_IS_BOT = true;
const char* TEST_USERNAME = "user username";
const char* TEST_FIRST_NAME = "user first name";
const char* TEST_LAST_NAME = "user last name";
const char* TEST_LANG_CODE = "ru";
const bool TEST_CAN_JOIN_GROUPS = true;
const bool TEST_CAN_READ_ALL_GROUP_MESSAGES = true;
const bool TEST_SUPPORT_INLINE_QUERIES = true;

string dataSet()
{
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);

    writer.StartObject();

    writer.Key(User::ID_NAME.c_str());
    writer.Int(TEST_ID);

    writer.Key(User::IS_BOT.c_str());
    writer.Bool(TEST_ID);

    writer.Key(User::USERNAME.c_str());
    writer.String(TEST_USERNAME);

    writer.Key(User::FIRST_NAME.c_str());
    writer.String(TEST_FIRST_NAME);

    writer.Key(User::LAST_NAME.c_str());
    writer.String(TEST_LAST_NAME);

    writer.Key(User::LANGUAGE_CODE.c_str());
    writer.String(TEST_LANG_CODE);

    writer.Key(User::CAN_JOIN_GROUPS.c_str());
    writer.Bool(TEST_CAN_JOIN_GROUPS);

    writer.Key(User::CAN_READ_ALL_GROUP_MESSAGES.c_str());
    writer.Bool(TEST_CAN_READ_ALL_GROUP_MESSAGES);

    writer.Key(User::SUPPORT_INLINE_QUERIES.c_str());
    writer.Bool(TEST_SUPPORT_INLINE_QUERIES);

    writer.EndObject();
    return buffer.GetString();
}

TEST(type_user, initialize_from_string)
{
    string json = dataSet();
    User user(json);
    ASSERT_EQ(user.id, TEST_ID);
    ASSERT_EQ(user.is_bot, TEST_IS_BOT);
    ASSERT_EQ(user.username, TEST_USERNAME);
    ASSERT_EQ(user.first_name, TEST_FIRST_NAME);
    ASSERT_EQ(user.last_name, TEST_LAST_NAME);
    ASSERT_EQ(user.language_code, TEST_LANG_CODE);
    ASSERT_EQ(user.can_join_groups, TEST_CAN_JOIN_GROUPS);
    ASSERT_EQ(user.can_read_all_group_messages, TEST_CAN_READ_ALL_GROUP_MESSAGES);
    ASSERT_EQ(user.supports_inline_queries, TEST_SUPPORT_INLINE_QUERIES);
}

}
