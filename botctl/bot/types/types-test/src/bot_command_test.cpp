#include <gtest/gtest.h>
#include "bot_command.h"


namespace bot_command_test {

using namespace std;
using namespace bot::types;

string command = "command";
string description = "description";
BotCommand command0(command, description);

TEST(bot_command_test, constructor_params) {
    ASSERT_EQ(command0.command, command);
    ASSERT_EQ(command0.description, description);
}

TEST(bot_command_test, serialize) {
    string json = command0.toString();
    BotCommand command1(json);
    ASSERT_EQ(command1.command, command);
    ASSERT_EQ(command1.description, description);
}


}
