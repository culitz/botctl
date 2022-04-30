#include <gtest/gtest.h>
#include "../chat_member_left.h"

namespace chat_member_left_test {

using namespace std;
using namespace bot::types;

User user("test", true);
string status = "left";
ChatMemberLeft member0(user, status);

TEST(chat_member_left_test, constructor_params) {
    ASSERT_EQ(member0.user, user);
    ASSERT_EQ(member0.status, status);
}

TEST(chat_member_left_test, serialize) {
    string json = member0.toString();
    ChatMemberLeft member1(json);
    ASSERT_EQ(member1.user, user);
    ASSERT_EQ(member1.status, status);
}

}