#include <gtest/gtest.h>
#include "../chat_administrator_rights.h"

namespace chat_administrator_rights_test {

using namespace std;
using namespace bot::types;


bool is_anonymous = true;
bool can_manage_chat = true;
bool can_delete_messages = true;
bool can_manage_video_chats = true;
bool can_restrict_members = true;
bool can_promote_members = true;
bool can_change_info = true;
bool can_invite_users = true;
optional<bool> can_post_messages = true;
optional<bool> can_edit_messages = true;
optional<bool> can_pin_messages =true;

ChatAdministratorRights rights0(
    is_anonymous,
    can_manage_chat,
    can_delete_messages,
    can_manage_video_chats,
    can_restrict_members,
    can_promote_members,
    can_change_info,
    can_invite_users,
    can_post_messages,
    can_edit_messages,
    can_pin_messages
);

TEST(chat_administrator_rights_test, params_constructor) {
    ASSERT_EQ(is_anonymous, rights0.is_anonymous);
    ASSERT_EQ(can_manage_chat, rights0.can_manage_chat);
    ASSERT_EQ(can_delete_messages, rights0.can_delete_messages);
    ASSERT_EQ(can_manage_video_chats, rights0.can_manage_video_chats);
    ASSERT_EQ(can_restrict_members, rights0.can_restrict_members);
    ASSERT_EQ(can_promote_members, rights0.can_promote_members);
    ASSERT_EQ(can_change_info, rights0.can_change_info);
    ASSERT_EQ(can_invite_users, rights0.can_invite_users);
    ASSERT_EQ(can_post_messages, rights0.can_post_messages);
    ASSERT_EQ(can_edit_messages, rights0.can_edit_messages);
    ASSERT_EQ(can_pin_messages, rights0.can_pin_messages);
}

TEST(chat_administrator_rights_test, serialize) {
    string json = rights0.toString();
    ChatAdministratorRights rights1(json);
    ASSERT_EQ(is_anonymous, rights1.is_anonymous);
    ASSERT_EQ(can_manage_chat, rights1.can_manage_chat);
    ASSERT_EQ(can_delete_messages, rights1.can_delete_messages);
    ASSERT_EQ(can_manage_video_chats, rights1.can_manage_video_chats);
    ASSERT_EQ(can_restrict_members, rights1.can_restrict_members);
    ASSERT_EQ(can_promote_members, rights1.can_promote_members);
    ASSERT_EQ(can_change_info, rights1.can_change_info);
    ASSERT_EQ(can_invite_users, rights1.can_invite_users);
    ASSERT_EQ(can_post_messages, rights1.can_post_messages);
    ASSERT_EQ(can_edit_messages, rights1.can_edit_messages);
    ASSERT_EQ(can_pin_messages, rights1.can_pin_messages);
}

}