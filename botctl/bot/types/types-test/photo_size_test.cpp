#include <gtest/gtest.h>
#include "../photo_size.h"


namespace test_photo_size
{

TEST(test_photo_size, from_string)
{
    std::stringstream ss;
    std::string file_id = "fl";
    int size = 100;
    std::string file_unique_id = "uid";
    int width = 200;
    int height = 300;

    ss << "{"
       << "\"file_id\":" << "\""<< file_id << "\", "
       << "\"file_unique_id\":" << "\"" << file_unique_id << "\", "
       << "\"file_size\": " << std::to_string(size) << ", "
       << "\"width\": " << std::to_string(width) << ", "
       << "\"height\": " << std::to_string(height)
       << "}";

    std::string json = ss.str();
    bot::types::PhotoSize b(json);

    ASSERT_EQ(b.file_id, file_id) << ss.str();
    ASSERT_EQ(b.file_unique_id, file_unique_id) << ss.str();
    ASSERT_EQ(b.file_size, size);
    ASSERT_EQ(b.height, height);
    ASSERT_EQ(b.width, width);
}

}
