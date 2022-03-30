#include "../keyboard_button.h"
#include <gtest/gtest.h>
#include "../fields.h"
#include <sstream>


namespace test_type_keyboard_button {

using namespace bot::types;

TEST(keyboard_button_test, serialize) {
    string text = "text";
    KeyboardButtonPollType type;
    type.type = "type";
    KeyboardButton kbn0(text, false, false, type);
    string json = kbn0.toString();
    KeyboardButton kbn1(json);

    ASSERT_EQ(kbn0.text, kbn1.text);
    ASSERT_EQ(kbn0.request_contact, kbn1.request_contact);
    ASSERT_EQ(kbn0.request_location, kbn1.request_location);
    ASSERT_EQ(kbn0.request_poll, kbn1.request_poll);
}

}   