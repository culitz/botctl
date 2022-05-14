#include <gtest/gtest.h>
#include "user.h"
#include "chat_invite_link.h"

namespace chat_invite_link_test {

using namespace std;
using namespace bot::types;


std::string invite_link = "invite_link";
User creator("creator", false);
bool creates_join_request = true;
bool is_primary = false;
bool is_revoked = true;
std::optional<std::string> name = "name";
std::optional<int> expire_date = 12;
std::optional<int> member_limit = 123;
std::optional<int> pending_join_request_count = 1234;

ChatInviteLink link0(
    invite_link, 
    creator, 
    creates_join_request, 
    is_primary, 
    is_revoked,
    name,
    expire_date, 
    member_limit, 
    pending_join_request_count  
);

TEST(chat_invite_link_test, constructor_params) {
    ASSERT_EQ(invite_link, link0.invite_link);  
    ASSERT_EQ(creator, link0.creator);  
    ASSERT_EQ(creates_join_request, link0.creates_join_request);  
    ASSERT_EQ(is_primary, link0.is_primary);  
    ASSERT_EQ(is_revoked, link0.is_revoked);  
    ASSERT_EQ(name, link0.name);  
    ASSERT_EQ(expire_date, link0.expire_date);  
    ASSERT_EQ(member_limit, link0.member_limit);  
    ASSERT_EQ(pending_join_request_count, link0.pending_join_request_count);  
}

TEST(chat_invite_link_test, serialize) {
    string json = link0.toString();
    ChatInviteLink link1(json);
    ASSERT_EQ(invite_link, link1.invite_link);  
    ASSERT_EQ(creator, link1.creator);  
    ASSERT_EQ(creates_join_request, link1.creates_join_request);  
    ASSERT_EQ(is_primary, link1.is_primary);  
    ASSERT_EQ(is_revoked, link1.is_revoked);  
    ASSERT_EQ(name, link1.name);  
    ASSERT_EQ(expire_date, link1.expire_date);  
    ASSERT_EQ(member_limit, link1.member_limit);  
    ASSERT_EQ(pending_join_request_count, link1.pending_join_request_count);
}

}
