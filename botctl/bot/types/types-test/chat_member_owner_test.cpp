#include <gtest/gtest.h>
#include "../chat_member_owner.h"

namespace chat_member_owner_test {

using namespace std;
using namespace bot::types;

User user("user", true);
std::string status = "status";
bool is_anonymous = true;
std::string custom_title = "title";
ChatMemberOwner owner0(user, status, is_anonymous, custom_title);

TEST(chat_member_owner_test, constructor_params) {
    ASSERT_EQ(user, owner0.user); 
    ASSERT_EQ(status, owner0.status); 
    ASSERT_EQ(is_anonymous, owner0.is_anonymous); 
    ASSERT_EQ(custom_title, owner0.custom_title);  
}

TEST(chat_member_owner_test, serialize) {
    string json = owner0.toString();
    ChatMemberOwner owner1(json);
    ASSERT_EQ(user, owner0.user); 
    ASSERT_EQ(status, owner0.status); 
    ASSERT_EQ(is_anonymous, owner0.is_anonymous); 
    ASSERT_EQ(custom_title, owner0.custom_title);  
}

}