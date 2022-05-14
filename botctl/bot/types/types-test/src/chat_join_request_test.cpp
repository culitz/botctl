#include <gtest/gtest.h>
#include "user.h"
#include "chat_invite_link.h"
#include "chat_join_request.h"
#include <iostream>

namespace chat_join_request_test {


using namespace bot::types;

Chat            chat("type", "");
User            from("user", true);
ChatInviteLink  invite_link("link", from, true, true, true);
string          bio = "bio";
int             date = 123456;
ChatJoinRequest req0(chat, from, date, bio, invite_link);

TEST(chat_join_request_test, constructor_params) {
    ASSERT_EQ(req0.chat, chat);
    ASSERT_EQ(req0.from, from);
    ASSERT_EQ(req0.invite_link, invite_link);
    ASSERT_EQ(req0.bio, bio);
    ASSERT_EQ(req0.date, date);
}

TEST(chat_join_request_test, serialize) {
    string json = req0.toString();
    ChatJoinRequest req1;
    req1.fromString(json);
    ASSERT_EQ(req1.chat, chat);
    ASSERT_EQ(req1.from, from);
    ASSERT_EQ(req1.invite_link, invite_link);
    ASSERT_EQ(req1.bio, bio);
    ASSERT_EQ(req1.date, date);
}

}
