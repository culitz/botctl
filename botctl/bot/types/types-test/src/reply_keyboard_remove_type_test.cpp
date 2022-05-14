#include <reply_keyboard_remove.h>
#include <gtest/gtest.h>
#include <fields.h>
#include <sstream>


namespace reply_keyboard_remove_type_test {

using namespace bot::types;

TEST(reply_keyboard_remove_type_test, serialize) {
    ReplyKeyboardRemove kbn0(false, false);
    string json = kbn0.toString();
    ReplyKeyboardRemove kbn1(json);

    ASSERT_EQ(kbn0.selective, kbn1.selective);
    ASSERT_EQ(kbn0.remove_keyboard, kbn1.remove_keyboard);
}

}   
