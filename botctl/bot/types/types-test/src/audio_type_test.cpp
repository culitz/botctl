#include <sstream>
#include <gtest/gtest.h>
#include "audio.h"
#include "rapidjson/document.h"


namespace test_audio_type 
{

TEST(type_base_object, initialize)
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
    std::string thumb_file_id = "thumb_file_id";
    std::string thumb_file_unique_id = "thumb_file_unique_id";
    std::string performer = "performer";
    std::string title = "title";

    std::stringstream ss;
    ss << "{\n"
       << "\"file_id\":" << "\""<< file_id << "\", \n"
       << "\"file_unique_id\":" << "\"" << file_unique_id << "\", \n"
       << "\"file_size\": " << std::to_string(size) <<", \n"
       << "\"file_name\": " << "\"" << file_name << "\", \n"
       << "\"mime_type\": " << "\"" << mime_type << "\", \n"
       << "\"duration\": " << std::to_string(duration) << ", \n"
       << "\t\"performer\": " << "\"" << performer << "\", \n"
       << "\t\"title\": " << "\"" << title << "\",\n"
       << "\"thumb\":" << "\n"
       << "{\n"
       << "\t\"file_id\":" << "\""<< thumb_file_id << "\", \n"
       << "\t\"file_unique_id\":" << "\"" << thumb_file_unique_id << "\", \n"
       << "\t\"file_size\": " << std::to_string(thumb_width) << ", \n"
       << "\t\"width\": " << std::to_string(thumb_size) << ", \n"
       << "\t\"height\": " << std::to_string(thumb_height) << "\n"
       << "}\n"
       << "}";
    std::string json = ss.str();
    bot::types::Audio audio(json);
}

}
