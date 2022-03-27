#include "../dice.h"
#include <gtest/gtest.h>
#include "../fields.h"
#include <sstream>


namespace test_type_dice {

TEST(type_dice, from_string)
{
    int value = 123;
    std::string emoji = "0x00";
    std::stringstream ss;
    ss  << "{ \n"
        << "\"" << bot::types::fields::EMOJI << "\": "
        << "\"" << emoji << "\", \n"
        << "\"" << bot::types::fields::VALUE << "\": "
        << value << " \n"
        << "}";
    
    std::string json = ss.str();
    bot::types::Dice dice(json);
    ASSERT_EQ(dice.value, value);
    ASSERT_EQ(dice.emoji, emoji);
}

}