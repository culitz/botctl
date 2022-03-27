#include <gtest/gtest.h>
#include "../voice_chat_scheduled.h"

namespace voice_chat_scheduled_types_test {

using namespace bot::types;

TEST(voice_chat_scheduled_test, serialization) {
    VoiceChatScheduled s0(100);
    std::string json = s0.toString();
    VoiceChatScheduled s1(json);

    ASSERT_EQ(s0.start_date, s1.start_date);
}

}