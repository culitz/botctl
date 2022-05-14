#include <gtest/gtest.h>
#include <voice_chat_ended.h>

namespace voice_chat_ended_test {

using namespace bot::types;

TEST(voice_chat_scheduled_test, serialization) {
    VoiceChatEnded object0(100);
    std::string json = object0.toString();
    VoiceChatEnded object1(json);
    ASSERT_EQ(object0.duration, object1.duration);
}

}
