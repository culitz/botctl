#include <sstream>
#include <iostream>
#include "botctl/bot/types/base_file.h"
#include "botctl/bot/types/video.h"
#include "botctl/bot/types/fields.h"
#include "botctl/bot/types/contact.h"
#include "botctl/bot/types/user.h"
#include "botctl/bot/types/poll_answer.h"


using namespace bot::types;


int main()
{
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
        << "\"" << fields::POOL_ID << "\": "
        << "\"" << poll_id << "\", \n"
        << "\"" << fields::OPTION_IDS << "\": ["
        << std::to_string(option_ids[0]) << ", "
        << std::to_string(option_ids[1]) << ", "
        << std::to_string(option_ids[2]) << "], \n"
        << "\"" << fields::USER << "\"" << user.toString() << "\n"
        << "}";
    
    std::string json = ss.str();
    std::cout << json << std::endl;
    bot::types::PollAnswer pool_answer(json);
}
