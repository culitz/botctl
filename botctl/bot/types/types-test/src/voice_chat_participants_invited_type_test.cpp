#include <gtest/gtest.h>
#include <vector>
#include <voice_chat_participants_invited.h>
#include <user.h>

namespace voice_chat_participants_invited_type_test {

using namespace bot::types;

TEST(voice_chat_participants_invited_test, serialization) {
    std::vector<User> users = {
        User("user1", true),
        User("user2", false)
    };
    VoiceChatParticipantsInvited object0(users);
    std::string json = object0.toString();
    VoiceChatParticipantsInvited object1(json);

    for(size_t i = 0; i < users.size(); i++) {
        bool is_same_name = object0.users[i].first_name == object1.users[i].first_name;
        bool is_same_flag = object0.users[i].is_bot == object1.users[i].is_bot;
        ASSERT_TRUE(is_same_name);
        ASSERT_TRUE(is_same_flag);
    }
}

}
