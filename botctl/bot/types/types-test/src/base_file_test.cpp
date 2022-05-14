#include <gtest/gtest.h>
#include "base_file.h"
#include "rapidjson/document.h"

namespace test_document_type
{


TEST(type_document_test, from_string)
{
    std::stringstream ss;
    std::string file_id = "fl";
    int size = 100;
    std::string file_unique_id = "uid";
    std::string file_name = "file_name";
    std::string mime_type = "mime_type";

    ss << "{"
       << "\"file_id\":" << "\""<< file_id << "\", "
       << "\"file_unique_id\":" << "\"" << file_unique_id << "\", "
       << "\"file_size\": " << std::to_string(size) <<", "
       << "\"file_name\": " << "\"" << file_name << "\", "
       << "\"mime_type\": " << "\"" << mime_type << "\""
       << "}";
    bot::types::BaseFile b(ss.str());

    ASSERT_EQ(b.file_id, file_id) << ss.str();
    ASSERT_EQ(b.file_unique_id, file_unique_id) << ss.str();
    ASSERT_EQ(b.file_size, size);
    ASSERT_EQ(b.file_name, file_name);
    ASSERT_EQ(b.mime_type, mime_type);
}


}
