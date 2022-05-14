#include <gtest/gtest.h>
#include "bot_command_scope.h"


namespace bot_command_scope {

using namespace bot::types;

TEST(bot_command_scope, serialize) {
    std::string type = "type";
    BotCommandScope scope0{};
    scope0.type = type;

    string json = scope0.toString();
    BotCommandScope scope1(json);
    ASSERT_EQ(scope1.type, type);
}


}
