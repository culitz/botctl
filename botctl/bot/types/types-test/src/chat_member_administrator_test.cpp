#include <gtest/gtest.h>
#include "chat_member_administrator.h"

namespace chat_member_administrator_test {

using namespace std;
using namespace bot::types;

User                        user("user", true); 
std::string                 status = "status";
bool                        can_be_edited = true;
bool                        is_anonymous = true;
bool                        can_manage_chat = true;
bool                        can_delete_messages = true;
bool                        can_manage_video_chats = true;
bool                        can_restrict_members = true;
bool                        can_promote_members = true;
bool                        can_change_info = true;
bool                        can_invite_users = true;
std::optional<bool>         can_post_messages = true;
std::optional<bool>         can_edit_messages = true;
std::optional<bool>         can_pin_messages = true;
std::optional<std::string>  custom_title = "custom_title";

ChatMemberAdministrator admin0(
    user,
    status,
    can_be_edited,
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
    can_pin_messages,
    custom_title
);

TEST(chat_member_administrator_test, constructor_params) {
    ASSERT_EQ(admin0.user, user);
    ASSERT_EQ(admin0.status, status);
    ASSERT_EQ(admin0.can_be_edited, can_be_edited);
    ASSERT_EQ(admin0.is_anonymous, is_anonymous);
    ASSERT_EQ(admin0.can_manage_chat, can_manage_chat);
    ASSERT_EQ(admin0.can_delete_messages, can_delete_messages);
    ASSERT_EQ(admin0.can_manage_video_chats, can_manage_video_chats);
    ASSERT_EQ(admin0.can_restrict_members, can_restrict_members);
    ASSERT_EQ(admin0.can_promote_members, can_promote_members);
    ASSERT_EQ(admin0.can_change_info, can_change_info);
    ASSERT_EQ(admin0.can_invite_users, can_invite_users);
    ASSERT_EQ(admin0.can_post_messages, can_post_messages);
    ASSERT_EQ(admin0.can_edit_messages, can_edit_messages);
    ASSERT_EQ(admin0.can_pin_messages, can_pin_messages);
    ASSERT_EQ(admin0.custom_title, custom_title);   
}

TEST(chat_member_administrator_test, serialize) {
    string json = admin0.toString();
    ChatMemberAdministrator admin1(json);
    ASSERT_EQ(admin1.user, user);
    ASSERT_EQ(admin1.status, status);
    ASSERT_EQ(admin1.can_be_edited, can_be_edited);
    ASSERT_EQ(admin1.is_anonymous, is_anonymous);
    ASSERT_EQ(admin1.can_manage_chat, can_manage_chat);
    ASSERT_EQ(admin1.can_delete_messages, can_delete_messages);
    ASSERT_EQ(admin1.can_manage_video_chats, can_manage_video_chats);
    ASSERT_EQ(admin1.can_restrict_members, can_restrict_members);
    ASSERT_EQ(admin1.can_promote_members, can_promote_members);
    ASSERT_EQ(admin1.can_change_info, can_change_info);
    ASSERT_EQ(admin1.can_invite_users, can_invite_users);
    ASSERT_EQ(admin1.can_post_messages, can_post_messages);
    ASSERT_EQ(admin1.can_edit_messages, can_edit_messages);
    ASSERT_EQ(admin1.can_pin_messages, can_pin_messages);
    ASSERT_EQ(admin1.custom_title, custom_title);   
}

}
