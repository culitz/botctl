#include <gtest/gtest.h>
#include "chat_permissions.h"


namespace chat_permissions_test {


using namespace bot::types;
using namespace std;


optional<bool> can_send_messages = true;
optional<bool> can_send_media_messages = true;
optional<bool> can_send_polls = true;
optional<bool> can_send_other_messages = true;
optional<bool> can_add_web_page_previews = true;
optional<bool> can_change_info = true;
optional<bool> can_invite_users = true;
optional<bool> can_pin_messages = true;

ChatPermissions perm0(
    can_send_messages,
    can_send_media_messages,
    can_send_polls,
    can_send_other_messages,
    can_add_web_page_previews,
    can_change_info,
    can_invite_users,
    can_pin_messages
);

TEST(chat_permissions_test, constructor_params) {
    ASSERT_EQ(perm0.can_send_messages, can_send_messages);
    ASSERT_EQ(perm0.can_send_media_messages, can_send_media_messages);
    ASSERT_EQ(perm0.can_send_polls, can_send_polls);
    ASSERT_EQ(perm0.can_send_other_messages, can_send_other_messages);
    ASSERT_EQ(perm0.can_add_web_page_previews, can_add_web_page_previews);
    ASSERT_EQ(perm0.can_change_info, can_change_info);
    ASSERT_EQ(perm0.can_invite_users, can_invite_users);
    ASSERT_EQ(perm0.can_pin_messages, can_pin_messages);
}


TEST(chat_permissions_test, serialize) {
    string json = perm0.toString();
    ChatPermissions perm1(json);
    ASSERT_EQ(perm1.can_send_messages, can_send_messages);
    ASSERT_EQ(perm1.can_send_media_messages, can_send_media_messages);
    ASSERT_EQ(perm1.can_send_polls, can_send_polls);
    ASSERT_EQ(perm1.can_send_other_messages, can_send_other_messages);
    ASSERT_EQ(perm1.can_add_web_page_previews, can_add_web_page_previews);
    ASSERT_EQ(perm1.can_change_info, can_change_info);
    ASSERT_EQ(perm1.can_invite_users, can_invite_users);
    ASSERT_EQ(perm1.can_pin_messages, can_pin_messages);
}


}
