#include <sstream>
#include <gtest/gtest.h>
#include "../contact.h"
#include "rapidjson/document.h"


namespace test_type_contact 
{

TEST(type_contact, from_string)
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
    bot::types::Contact contact(json);

    ASSERT_EQ(contact.user_id, user_id);
    ASSERT_EQ(contact.phone_number, phone_number);
    ASSERT_EQ(contact.first_name, first_name);
    ASSERT_EQ(contact.last_name, last_name);
    ASSERT_EQ(contact.vcard, vcard);
}

}