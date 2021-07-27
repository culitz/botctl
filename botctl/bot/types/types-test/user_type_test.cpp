#include <gtest/gtest.h>
#include <boost/property_tree/ptree.hpp>
#include "../user.h"
#include "../base_object.h"

using User = bot::types::User;
using ptree = boost::property_tree::ptree;
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

std::shared_ptr<ptree> getDataset()
{
    auto pt = std::shared_ptr<ptree>( new ptree );
    pt->add<int>(BaseObject::ID_NAME, TEST_ID);
    pt->add<bool>(User::IS_BOT, TEST_IS_BOT);
    pt->add<string>(User::USERNAME, TEST_USERNAME);
    pt->add<string>(User::FIRST_NAME, TEST_FIRST_NAME);
    pt->add<string>(User::LAST_NAME, TEST_LAST_NAME);
    pt->add<string>(User::LANGUAGE_CODE, TEST_LANG_CODE);
    pt->add<bool>(User::CAN_JOIN_GROUPS, TEST_CAN_JOIN_GROUPS);
    pt->add<bool>(User::CAN_READ_ALL_GROUP_MESSAGES, TEST_CAN_READ_ALL_GROUP_MESSAGES);
    pt->add<bool>(User::SUPPORT_INLINE_QUERIES, TEST_SUPPORT_INLINE_QUERIES);
    return pt;
}

std::shared_ptr<User> createObject()
{
    auto data = getDataset();
    return std::shared_ptr<User>( new User(*data) );
}

TEST(type_user, initialize)
{
    ASSERT_NE(createObject(), nullptr);
}

TEST(type_user, get_id)
{
    ASSERT_EQ(createObject()->getId(), TEST_ID);
}

TEST(type, get_username)
{
    string username = createObject()->getUserName().value();
    ASSERT_EQ(username, TEST_USERNAME) << username << " != " << TEST_USERNAME ;
}

TEST(type_user, get_first_name)
{
    ASSERT_EQ(createObject()->getFirstName(), TEST_FIRST_NAME);
}

TEST(type_user, get_last_name)
{
    ASSERT_EQ(createObject()->getLastName().value(),
              TEST_LAST_NAME);
}

TEST(type_user, get_lang_code)
{
    ASSERT_EQ(createObject()->getLanguageCode().value(),
              TEST_LANG_CODE);
}

TEST(type_user, can_join_groups)
{
    ASSERT_EQ(createObject()->canJoinGroups(),
              TEST_CAN_JOIN_GROUPS);
}

TEST(type_user, can_read_all_groups)
{
    ASSERT_EQ(createObject()->canReadAllGroupMessages(),
              TEST_CAN_READ_ALL_GROUP_MESSAGES);
}

TEST(type_user, upport_inline_queries)
{
    ASSERT_EQ(createObject()->supportInlineQueries(),
              TEST_SUPPORT_INLINE_QUERIES);
}
