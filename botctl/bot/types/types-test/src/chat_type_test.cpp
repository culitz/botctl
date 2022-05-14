#include <gtest/gtest.h>
#include "chat.h"
#include "base_object.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"


namespace test_chat_type {

using BaseObject = bot::types::BaseObject;
using Chat = bot::types::Chat;
using string = std::string;


string dataSet()
{
    rapidjson::StringBuffer buffer;
    rapidjson::Writer writer(buffer);

    writer.StartObject();

    writer.Key(Chat::ID_NAME.c_str());
    writer.Int(5);

    writer.Key(Chat::TYPE.c_str());
    writer.String("test_type");

    writer.Key(Chat::TITLE.c_str());
    writer.String("test_title");

    writer.Key(Chat::USERNAME.c_str());
    writer.String("test_username");

    writer.Key(Chat::FIRSTNAME.c_str());
    writer.String("test_firstname");

    writer.Key(Chat::LASTNAME.c_str());
    writer.String("test_lastname");

    writer.Key(Chat::DESCRIPTION.c_str());
    writer.String("test_description");

    writer.Key(Chat::INVITE_LINK.c_str());
    writer.String("test_invitelink");

    writer.Key(Chat::SLOW_MODE_DELAY.c_str());
    writer.Int(5);

    writer.Key(Chat::MESSAGE_AUTO_DELETE_TIME.c_str());
    writer.Int(5);

    writer.Key(Chat::STICKER_SET_NAME.c_str());
    writer.String("test_sticker_set_name");

    writer.Key(Chat::CAN_SET_STICKER_SET.c_str());
    writer.Bool(true);

    writer.Key(Chat::LINKED_CHAT_ID.c_str());
    writer.Int(5);

    writer.EndObject();

    return buffer.GetString();
}

TEST(type_chat, initialize_default_constructor)
{
    auto base_object0 = std::shared_ptr<Chat>( new Chat() );
    ASSERT_NE(base_object0, nullptr);
}

TEST(type_chat, initialize_from_string)
{
    string json = dataSet();
    Chat chat;
    chat.fromString(json);

    ASSERT_EQ(chat.id, 5);
    ASSERT_EQ(chat.type, "test_type");
    ASSERT_EQ(*chat.title, "test_title");
    ASSERT_EQ(*chat.username, "test_username");
    ASSERT_EQ(*chat.first_name, "test_firstname");
    ASSERT_EQ(*chat.last_name, "test_lastname");
    ASSERT_EQ(*chat.description, "test_description");
    ASSERT_EQ(*chat.invite_link, "test_invitelink");
    ASSERT_EQ(*chat.slow_mode_delay, 5) << chat.toString();
    ASSERT_EQ(*chat.message_auto_delete_time, 5);
    ASSERT_EQ(*chat.sticker_set_name, "test_sticker_set_name");
    ASSERT_EQ(*chat.can_set_sticker_set, true);
    ASSERT_EQ(*chat.linked_chat_id, 5);
}

}
