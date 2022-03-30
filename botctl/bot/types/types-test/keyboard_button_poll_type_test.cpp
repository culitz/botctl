#include "../keyboard_button_poll_type.h"
#include <gtest/gtest.h>
#include "../fields.h"
#include <sstream>


namespace test_type_keyboard_button_pool_type {

using namespace bot::types;

TEST(test_type_keyboard_button_pool, serialize) {
    string type = "type";
    KeyboardButtonPollType type0;
    type0.type = type;
    string json = type0.toString();
    KeyboardButtonPollType type1(json);

    ASSERT_EQ(type0.type, type);
    ASSERT_EQ(type0.type, type1.type);    
}

}