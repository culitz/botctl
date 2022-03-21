#include <gtest/gtest.h>
#include "../message.h"
#include "../base_object.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

namespace message_type_test
{

using Message = bot::types::Message;
using string = std::string;
using optstring = std::optional<string>;
using BaseObject = bot::types::BaseObject;
using StringBuffer = rapidjson::StringBuffer;

int TEST_MESSAGE = 100;
int TEST_DATE = 100;
int TEST_FORWARD_FROM_MESSAGE_ID = 100;
string TEST_FORWARD_SIGNATURE = "FORWARD_SIGNATURE";
string TEST_FORWARD_SENDER_NAME = "TEST_FORWARD_SENDER_NAME";
int TEST_FORWARD_DATE = 100;
bool TEST_IS_AUTOMATIC_FORWARD = true;
int TEST_EDIT_DATE = 100;
bool TEST_HAS_PROTECTED_CONTENT = true;
string TEST_MEDIA_GROUP_ID = "MEDIA_GROUP_ID";
string TEST_AUTHOR_SIGNATURE = "AUTHOR_SIGNATURE";
string TEST_TEXT = "TEXT";
string TEST_CAPTION = "CAPTION";
bool TEST_DELETE_CHAT_PHOTO = true;
bool TEST_GROUP_CHAT_CREATED = true;
bool TEST_SUPERGROUP_CHAT_CREATED = true;
bool TEST_CHANNEL_CHAT_CREATED = true;
int TEST_MIGRATE_FROM_CHAT_ID = 100;
string TEST_CONNECTED_WEBSITE = "CONNECTED_WEBSITE";


string dataSet()
{
    StringBuffer buffer;
    rapidjson::Writer<StringBuffer> writer(buffer);
    writer.StartObject();
    writer.Key(Message::MESSAGE_ID.c_str());
    writer.Int(TEST_MESSAGE);

    writer.Key(Message::DATE.c_str());
    writer.Int(TEST_DATE);

    writer.Key(Message::FORWARD_FROM_MESSAGE_ID.c_str());
    writer.Int(TEST_FORWARD_FROM_MESSAGE_ID);

    writer.Key(Message::FORWARD_SIGNATURE.c_str());
    writer.String(TEST_FORWARD_SIGNATURE.c_str());

    writer.Key(Message::FORWARD_SENDER_NAME.c_str());
    writer.String(TEST_FORWARD_SENDER_NAME.c_str());

    writer.Key(Message::FORWARD_DATE.c_str());
    writer.Int(TEST_FORWARD_DATE);

    writer.Key(Message::IS_AUTOMATIC_FORWARD.c_str());
    writer.Bool(TEST_IS_AUTOMATIC_FORWARD);

    writer.Key(Message::EDIT_DATE.c_str());
    writer.Int(TEST_EDIT_DATE);

    writer.Key(Message::HAS_PROTECTED_CONTENT.c_str());
    writer.Bool(TEST_HAS_PROTECTED_CONTENT);

    writer.Key(Message::MEDIA_GROUP_ID.c_str());
    writer.String(TEST_MEDIA_GROUP_ID.c_str());

    writer.Key(Message::AUTHOR_SIGNATURE.c_str());
    writer.String(TEST_AUTHOR_SIGNATURE.c_str());

    writer.Key(Message::TEXT.c_str());
    writer.String(TEST_TEXT.c_str());

    writer.Key(Message::CAPTION.c_str());
    writer.String(TEST_CAPTION.c_str());

    writer.Key(Message::DELETE_CHAT_PHOTO.c_str());
    writer.Bool(TEST_DELETE_CHAT_PHOTO);

    writer.Key(Message::GROUP_CHAT_CREATED.c_str());
    writer.Bool(TEST_GROUP_CHAT_CREATED);

    writer.Key(Message::SUPERGROUP_CHAT_CREATED.c_str());
    writer.Bool(TEST_SUPERGROUP_CHAT_CREATED);

    writer.Key(Message::CHANNEL_CHAT_CREATED.c_str());
    writer.Bool(TEST_CHANNEL_CHAT_CREATED);

    writer.Key(Message::MIGRATE_FROM_CHAT_ID.c_str());
    writer.Int(TEST_MIGRATE_FROM_CHAT_ID);

    writer.Key(Message::CONNECTED_WEBSITE.c_str());
    writer.String(TEST_CONNECTED_WEBSITE.c_str());
    writer.EndObject();
    return buffer.GetString();
}


TEST(type_message, initialize_from_string)
{
    string json = dataSet();
    Message msg(json);
    ASSERT_EQ(msg.message_id, TEST_MESSAGE);
    ASSERT_EQ(*msg.date, TEST_DATE);
    ASSERT_EQ(*msg.forward_from_message_id, TEST_FORWARD_FROM_MESSAGE_ID);
    ASSERT_EQ(*msg.forward_signature, TEST_FORWARD_SIGNATURE);
    ASSERT_EQ(*msg.forward_sender_name, TEST_FORWARD_SENDER_NAME);
    ASSERT_EQ(*msg.forward_date, TEST_FORWARD_DATE);
    ASSERT_EQ(*msg.is_automatic_forward, TEST_IS_AUTOMATIC_FORWARD);
    ASSERT_EQ(*msg.edit_date, TEST_EDIT_DATE);
    ASSERT_EQ(*msg.has_protected_content, TEST_HAS_PROTECTED_CONTENT);
    ASSERT_EQ(*msg.media_group_id, TEST_MEDIA_GROUP_ID);
    ASSERT_EQ(*msg.author_signature, TEST_AUTHOR_SIGNATURE);
    ASSERT_EQ(*msg.text, TEST_TEXT);
    ASSERT_EQ(*msg.caption, TEST_CAPTION);
    ASSERT_EQ(*msg.delete_chat_photo, TEST_DELETE_CHAT_PHOTO);
    ASSERT_EQ(*msg.group_chat_created, TEST_GROUP_CHAT_CREATED);
    ASSERT_EQ(*msg.supergroup_chat_created, TEST_SUPERGROUP_CHAT_CREATED);
    ASSERT_EQ(*msg.channel_chat_created, TEST_CHANNEL_CHAT_CREATED);
    ASSERT_EQ(*msg.migrate_to_chat_id, TEST_MIGRATE_FROM_CHAT_ID);
    ASSERT_EQ(*msg.connected_website, TEST_CONNECTED_WEBSITE);
}

}
