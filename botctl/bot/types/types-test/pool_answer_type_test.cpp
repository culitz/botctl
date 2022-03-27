#include "../poll_answer.h"
#include <gtest/gtest.h>
#include "../fields.h"
#include "../user.cpp"
#include <sstream>


namespace test_type_pool_answer {

using namespace bot::types;

TEST(type_pool_answer, from_string) {
    std::string poll_id = "12";
    std::vector<int> option_ids {1,2,3};
    User user;
    user.id = 1;
    user.first_name = "first_name";
    user.is_bot = true;
    user.language_code = "EN";
    user.last_name = "last_name";
    user.supports_inline_queries = true;
    user.username = "username";

    std::stringstream ss;
    ss  << "{ \n"
        << "\"" << fields::POOL_ID  << "\": "
        << "\"" << poll_id << "\", \n"
        << "\"" << fields::OPTION_IDS << "\": ["
        << std::to_string(option_ids[0]) << ", "
        << std::to_string(option_ids[1]) << ", "
        << std::to_string(option_ids[2]) << "], \n"
        << "\"" << fields::USER << "\":" << user.toString() << "\n"
        << "}";
    
    std::string json = ss.str();
    bot::types::PollAnswer pool_answer(json);
    ASSERT_EQ(pool_answer.poll_id, poll_id);
    ASSERT_EQ(pool_answer.user.last_name, user.last_name);
    ASSERT_EQ(pool_answer.user.id, user.id);
    ASSERT_EQ(pool_answer.user.first_name, user.first_name);
    ASSERT_EQ(pool_answer.user.is_bot, user.is_bot);
    ASSERT_EQ(pool_answer.user.supports_inline_queries, user.supports_inline_queries);
} 

}