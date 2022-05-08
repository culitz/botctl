#include <gtest/gtest.h>
#include "../constants.h"
#include "../bot_command_scope_default.h"

namespace bot_command_scope_default {

using namespace bot::types;

BotCommandScopeDefault defscope;

TEST(bot_command_scope_default, serialize) {
    ASSERT_EQ(defscope.type, consts::command::scope::DEFAULT);
}

}