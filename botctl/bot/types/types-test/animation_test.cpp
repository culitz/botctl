#include <gtest/gtest.h>
#include "../animation.h"


namespace test_animation
{

TEST(type_base_file, from_string)
{
    std::stringstream ss;
    int size = 100;
    int duaration = 200;
    std::string file_id = "fl";
    std::string file_unique_id = "uid";
    std::string file_name = "file_name";
    std::string mime_type = "mime_type";
    int width = 1234;
    int height = 12345;

    int thumb_width = 1234;
    int thumb_size = 4321;
    int thumb_height = 12345;
    std::string thumb_file_id = "thumb_file_id";
    std::string thumb_file_unique_id = "thumb_file_unique_id";

    ss << "{\n"
       << "\"file_id\":" << "\""<< file_id << "\", \n"
       << "\"file_unique_id\":" << "\"" << file_unique_id << "\", \n"
       << "\"file_size\": " << std::to_string(size) <<", \n"
       << "\"file_name\": " << "\"" << file_name << "\", \n"
       << "\"mime_type\": " << "\"" << mime_type << "\", \n"
       << "\"duration\": " << std::to_string(duaration) << ", \n"
       << "\t\"width\": " << std::to_string(width) << ", \n"
       << "\t\"height\": " << std::to_string(height) << ",\n"
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
    bot::types::Animation b(json);

    ASSERT_EQ(b.file_id, file_id) << ss.str();
    ASSERT_EQ(b.file_unique_id, file_unique_id) << ss.str();
    ASSERT_EQ(b.file_size, size);
    ASSERT_EQ(b.file_name, file_name);
    ASSERT_EQ(b.mime_type, mime_type);
}

}