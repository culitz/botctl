#include <gtest/gtest.h>
#include "chat_member_restricted.h"

namespace chat_member_restricted_test {

using namespace std;
using namespace bot::types;

User        user("user", true);
std::string status = "status";
bool        is_member = true; 
bool        can_change_info = true;
bool        can_invite_users = true; 
bool        can_pin_messages = true; 
bool        can_send_messages = true;
bool        can_send_media_messages = true; 
bool        can_send_polls = true;	
bool        can_send_other_messages = true; 
bool        can_add_web_page_previews = true; 
int         until_date = 1234;

ChatMemberRestricted restricted0(
    user,
    status,
    is_member,
    can_change_info,
    can_invite_users,
    can_pin_messages,
    can_send_messages,
    can_send_media_messages,
    can_send_polls,
    can_send_other_messages,
    can_add_web_page_previews,
    until_date  
);

TEST(chat_member_restricted_test, constructor_params) {
    ASSERT_EQ(user, restricted0.user);
    ASSERT_EQ(status, restricted0.status);
    ASSERT_EQ(is_member, restricted0.is_member);
    ASSERT_EQ(can_change_info, restricted0.can_change_info);
    ASSERT_EQ(can_invite_users, restricted0.can_invite_users);
    ASSERT_EQ(can_pin_messages, restricted0.can_pin_messages);
    ASSERT_EQ(can_send_messages, restricted0.can_send_messages);
    ASSERT_EQ(can_send_media_messages, restricted0.can_send_media_messages);
    ASSERT_EQ(can_send_polls, restricted0.can_send_polls);
    ASSERT_EQ(can_send_other_messages, restricted0.can_send_other_messages);
    ASSERT_EQ(can_add_web_page_previews, restricted0.can_add_web_page_previews);
    ASSERT_EQ(until_date, restricted0.until_date);
}

TEST(chat_member_restricted_test, serialize) {
    string json = restricted0.toString();
    ChatMemberRestricted restricted1(json);
    ASSERT_EQ(user, restricted1.user);
    ASSERT_EQ(status, restricted1.status);
    ASSERT_EQ(is_member, restricted1.is_member);
    ASSERT_EQ(can_change_info, restricted1.can_change_info);
    ASSERT_EQ(can_invite_users, restricted1.can_invite_users);
    ASSERT_EQ(can_pin_messages, restricted1.can_pin_messages);
    ASSERT_EQ(can_send_messages, restricted1.can_send_messages);
    ASSERT_EQ(can_send_media_messages, restricted1.can_send_media_messages);
    ASSERT_EQ(can_send_polls, restricted1.can_send_polls);
    ASSERT_EQ(can_send_other_messages, restricted1.can_send_other_messages);
    ASSERT_EQ(can_add_web_page_previews, restricted1.can_add_web_page_previews);
    ASSERT_EQ(until_date, restricted1.until_date);
}


}
