#include <sstream>
#include <gtest/gtest.h>
#include "../voice.h"
#include "rapidjson/document.h"


namespace test_voice_type 
{

TEST(type_voice_test, initialize)
{
    int size = 10;
    int duration = 20;
    int width = 30;
    int height = 40;
    int thumb_width = 50;
    int thumb_size = 60;
    int thumb_height = 70;
    std::string file_id = "file_id";
    std::string file_unique_id = "file_unique_id";
    std::string file_name = "file_name";
    std::string mime_type = "mime_type";

    std::stringstream ss;
    ss << "{\n"
       << "\"file_id\":" << "\""<< file_id << "\", \n"
       << "\"file_unique_id\":" << "\"" << file_unique_id << "\", \n"
       << "\"file_size\": " << std::to_string(size) <<", \n"
       << "\"file_name\": " << "\"" << file_name << "\", \n"
       << "\"mime_type\": " << "\"" << mime_type << "\", \n"
       << "\"duration\": " << std::to_string(duration) << "\n"
       << "}";
    std::string json = ss.str();
    bot::types::Voice voice(json);
}

}