#include <iostream>
#include "botctl/bot/types/base_file.h"
#include <sstream>
#include "botctl/bot/types/video.h"
#include "botctl/bot/types/fields.h"
#include "botctl/bot/types/chat.h"


using namespace bot::types;


int main()
{
    std::stringstream ss;
    std::string file_id = "fl";
    int file_size = 100;
    int width = 200;
    int height = 300;
    int duration = 400;
    std::string file_unique_id = "uid";
    std::string file_name = "file_name";
    std::string mime_type = "mime_type";
    int thumb_width = 50;
    int thumb_size = 60;
    int thumb_height = 70;
    std::string thumb_file_id = "thumb_file_id";
    std::string thumb_file_unique_id = "thumb_file_unique_id";

    ss << "{\n"
       << "\"" << fields::FILE_ID << "\":" << "\""<< file_id << "\", \n"
       << "\"" << fields::FILE_UNIQUE_ID << "\":" << "\"" << file_unique_id << "\", \n"
       << "\"" << fields::FILE_SIZE << "\": " << std::to_string(file_size) <<", \n"
       << "\"" << fields::FILE_NAME << "\": " << "\"" << file_name << "\", \n"
       << "\"" << fields::MIME_TYPE << "\": " << "\"" << mime_type << "\", \n"
       << "\"" << fields::WIDTH << "\": " << std::to_string(width) << ", \n"
       << "\"" << fields::DURATION << "\": " << std::to_string(duration) << ", \n"
       << "\"" << fields::HEIGHT << "\": " << std::to_string(height) << ", \n"
       << "\"" << fields::THUMB << "\":" << "\n"
       << "{\n"
       << "\t\"" << fields::FILE_ID << "\":" << "\""<< thumb_file_id << "\", \n"
       << "\t\"" << fields::FILE_UNIQUE_ID << "\":" << "\"" << thumb_file_unique_id << "\", \n"
       << "\t\"" << fields::WIDTH << "\": " << std::to_string(thumb_width) << ", \n"
       << "\t\"" << fields::FILE_SIZE << "\": " << std::to_string(thumb_size) << ", \n"
       << "\t\"" << fields::HEIGHT << "\": " << std::to_string(thumb_height) << "\n"
       << "}\n"
       << "}";

    std::string json = ss.str();
    std::cout << json << std::endl;
    bot::types::Video video(json);
}
