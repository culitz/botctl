#include <gtest/gtest.h>
#include "../bot_command_scope_chat_administrators.h"
#include "../constants.h"

namespace bot_command_scope_chat_administrators_test {

using namespace bot::types;

BotCommandScopeChatAdministrators admins;

TEST(bot_command_scope_chat_administrators_test, scope_type) {
    ASSERT_EQ(admins.type, consts::command::scope::CHAT_ADMINISTRATORS);
}

TEST(bot_command_scope_chat_administrators_test, serialize) {
    string json = admins.toString();
    BotCommandScopeChatAdministrators admins0;
    admins0.fromString(json);
    ASSERT_EQ(admins0.type, consts::command::scope::CHAT_ADMINISTRATORS);
}

TEST(bot_command_scope_chat_administrators_test, chat_id) {
    BotCommandScopeChatAdministrators admin0;
    admin0.chat_id = 123;
    string json = admin0.toString();
    BotCommandScopeChatAdministrators admins1;
    admins1.fromString(json);
    ASSERT_EQ(admins1.type, consts::command::scope::CHAT_ADMINISTRATORS);
    ASSERT_EQ(*admins1.chat_id, *admin0.chat_id);
}

TEST(bot_command_scope_chat_administrators_test, chat_sup_username) {
    BotCommandScopeChatAdministrators admin0;
    admin0.chat_sup_username = "supgroup_username";
    string json = admin0.toString();
    BotCommandScopeChatAdministrators admins1;
    admins1.fromString(json);
    ASSERT_EQ(admins1.type, consts::command::scope::CHAT_ADMINISTRATORS);
    ASSERT_EQ(admins1.chat_sup_username, admin0.chat_sup_username);
}

}
