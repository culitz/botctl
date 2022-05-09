#include <gtest/gtest.h>
#include "../constants.h"
#include "../bot_command_scope_chat_member.h"


namespace bot_command_scope_chat_member_test {

using namespace bot::types;

int user_id = 123;
int chat_id = 345;

TEST(bot_command_scope_chat_member_test, params) {
    BotCommandScopeChatMember obj;
    obj.user_id = user_id;
    obj.chat_id = chat_id;
    ASSERT_EQ(obj.type, consts::command::scope::CHAT_MEMBER);
    ASSERT_EQ(obj.chat_id, chat_id);
    ASSERT_EQ(obj.user_id, user_id);
}

TEST(bot_command_scope_chat_member_test, serialize) {
    BotCommandScopeChatMember obj;
    obj.user_id = user_id;
    obj.chat_id = chat_id;
    string json = obj.toString();
    BotCommandScopeChatMember member(json);
    ASSERT_EQ(member.type, consts::command::scope::CHAT_MEMBER);
    ASSERT_EQ(member.chat_id, chat_id);
    ASSERT_EQ(member.user_id, user_id);
}


}
