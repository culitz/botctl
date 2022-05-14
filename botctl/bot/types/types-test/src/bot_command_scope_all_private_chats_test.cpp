#include <gtest/gtest.h>
#include "bot_command_scope_all_private_chats.h"
#include "constants.h"


namespace bot_command_scope_all_private_chats_test {

using namespace bot::types;

TEST(bot_command_scope_all_private_chats_test, initialize) {
    BotCommandScopeAllPrivateChats chats;
    ASSERT_EQ(chats.type, consts::command::scope::ALL_PRIVATE_CHATS);
}

}
