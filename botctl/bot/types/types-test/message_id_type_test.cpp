#include <gtest/gtest.h>
#include "../message_id.h"
#include "../base_object.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>

namespace test_message_id
{

using MessageId = bot::types::MessageId;
using string = std::string;
using optstring = std::optional<string>;
using BaseObject = bot::types::BaseObject;
using StringBuffer = rapidjson::StringBuffer;


int TEST_MESSAGE = 100;

string dataSet()
{
    StringBuffer buffer;
    rapidjson::Writer<StringBuffer> writer(buffer);
    writer.StartObject();

    writer.Key(MessageId::MESSAGE_ID.c_str());
    writer.Int(TEST_MESSAGE);
    writer.EndObject();

    return buffer.GetString();
}


TEST(type_message_id, initialize_from_string)
{
    string json = dataSet();
    MessageId msg(json);
    ASSERT_EQ(msg.message_id, TEST_MESSAGE) << json;
}

}
