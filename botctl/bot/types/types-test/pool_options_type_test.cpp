#include "../pool_options.h"
#include <gtest/gtest.h>
#include "../fields.h"
#include <sstream>


namespace test_type_pool_options {

TEST(type_pool_options, from_string)
{
    int voite_count = 123;
    std::string text = "0x00";

    std::stringstream ss;
    ss  << "{ \n"
        << "\"" << bot::types::fields::TEXT << "\": "
        << "\"" << text << "\", \n"
        << "\"" << bot::types::fields::VOTER_COUNT << "\": "
        << voite_count << "\n"
        << "}";
    
    std::string json = ss.str();
    bot::types::PollOption pool_opt(json);
    ASSERT_EQ(pool_opt.text, text);
    ASSERT_EQ(pool_opt.voter_count, voite_count);
}

}