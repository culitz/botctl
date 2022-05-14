#include <gtest/gtest.h>
#include "chat_member_banned.h"

namespace chat_member_banned_test {

using namespace std;
using namespace bot::types;

User user("test", true);
string status = "left";
int until_date = 12345;
ChatMemberBanned member0(user, status, until_date);

TEST(chat_member_banned_test, constructor_params) {
    ASSERT_EQ(member0.user, user);
    ASSERT_EQ(member0.status, status);
    ASSERT_EQ(member0.until_date, until_date);
}

TEST(chat_member_banned_test, serialize) {
    string json = member0.toString();
    ChatMemberBanned member1(json);
    ASSERT_EQ(member1.user, user);
    ASSERT_EQ(member1.status, status);
    ASSERT_EQ(member1.until_date, until_date);
}

}
