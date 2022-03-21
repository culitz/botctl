#include <iostream>
#include "botctl/bot/types/base_file.h"
#include <sstream>
#include "botctl/bot/types/video.h"
#include "botctl/bot/types/fields.h"
#include "botctl/bot/types/contact.h"


using namespace bot::types;


int main()
{
    int user_id = 123;
    std::string phone_number = "phone_number";
    std::string first_name = "first_name";
    std::string last_name = "last_name";
    std::string vcard = "vcard";

    std::stringstream ss;
    ss << "{\n"
       << "\"user_id\":" << std::to_string(user_id) <<", \n"
       << "\"phone_number\":" << "\"" << phone_number << "\", \n"
       << "\"last_name\": " << "\"" << last_name <<"\", \n"
       << "\"first_name\": " << "\"" << first_name << "\", \n"
       << "\"vcard\": " << "\"" << vcard << "\" \n"
       << "}";
    std::string json = ss.str();
    std::cout << json << std::endl;
    bot::types::Contact contact(json);
       
}
