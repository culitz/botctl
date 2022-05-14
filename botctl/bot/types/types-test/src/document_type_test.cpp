#include <gtest/gtest.h>
#include "document.h"
#include "rapidjson/document.h"

namespace test_base_file_type
{


TEST(type_base_file, from_string)
{
    std::stringstream ss;
    std::string file_id = "fl";
    int size = 100;
    std::string file_unique_id = "uid";
    std::string file_name = "file_name";
    std::string mime_type = "mime_type";
    int thumb_width = 50;
    int thumb_size = 60;
    int thumb_height = 70;
    std::string thumb_file_id = "thumb_file_id";
    std::string thumb_file_unique_id = "thumb_file_unique_id";

    ss << "{"
       << "\"file_id\":" << "\""<< file_id << "\", "
       << "\"file_unique_id\":" << "\"" << file_unique_id << "\", "
       << "\"file_size\": " << std::to_string(size) <<", "
       << "\"file_name\": " << "\"" << file_name << "\", "
       << "\"mime_type\": " << "\"" << mime_type << "\", "
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
    bot::types::Document b(json);

    ASSERT_EQ(b.file_id, file_id) << ss.str();
    ASSERT_EQ(b.file_unique_id, file_unique_id) << ss.str();
    ASSERT_EQ(b.file_size, size);
    ASSERT_EQ(b.file_name, file_name);
    ASSERT_EQ(b.mime_type, mime_type);
}


}
