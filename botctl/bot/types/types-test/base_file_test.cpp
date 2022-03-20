#include <gtest/gtest.h>
#include "../base_file.h"
#include "rapidjson/document.h"

namespace test_base_file_type
{


TEST(type_base_file, from_string)
{
    std::stringstream ss;
    std::string file_id = "fl";
    int size = 100;
    std::string file_unique_id = "uid";
    ss << "{"
       << "\"file_id\":" << "\""<< file_id << "\", "
       << "\"file_unique_id\":" << "\"" << file_unique_id << "\", "
       << "\"file_size\": " << std::to_string(size)
       << "}";
    bot::types::BaseFile b(ss.str());

    ASSERT_EQ(b.file_id, file_id) << ss.str();
    ASSERT_EQ(b.file_unique_id, file_unique_id) << ss.str();
    ASSERT_EQ(b.file_size, size);
}


}
