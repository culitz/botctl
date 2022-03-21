#include <gtest/gtest.h>
#include "../fields.h"
#include "../video.h"
#include "rapidjson/document.h"


namespace test_base_file_type
{

using namespace bot::types;

TEST(type_video, from_string)
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

    ss << "{"
       << "\"" << fields::FILE_ID << "\":" << "\""<< file_id << "\", "
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
    bot::types::Video video(json);

    ASSERT_EQ(video.file_id, file_id) << ss.str();
    ASSERT_EQ(video.file_unique_id, file_unique_id) << ss.str();
    ASSERT_EQ(video.file_size, file_size);
    ASSERT_EQ(video.file_name, file_name);
    ASSERT_EQ(video.mime_type, mime_type);
    ASSERT_EQ(video.height, height);
    ASSERT_EQ(video.width, width);
    ASSERT_EQ(video.duration, duration);
    ASSERT_EQ(video.thumb->file_id, thumb_file_id);
    ASSERT_EQ(video.thumb->file_unique_id, thumb_file_unique_id);
    ASSERT_EQ(video.thumb->width, thumb_width);
    ASSERT_EQ(video.thumb->height, thumb_height);
    ASSERT_EQ(video.thumb->file_size, thumb_size);
}


}
