#include <gtest/gtest.h>
#include "chat_photo.h"

namespace chat_photo_test {

using namespace std;
using namespace bot::types;

string test_small_file_id = "test_small_file_id";
string test_small_file_unique_id = "test_small_file_unique_id";
string test_big_file_id = "test_big_file_id";
string test_big_file_unique_id = "test_big_file_unique_id";
ChatPhoto chat_photo0(
    test_small_file_id,
    test_small_file_unique_id,
    test_big_file_id,
    test_big_file_unique_id
);

TEST(chat_photo_test, constructor_params) {
    ASSERT_EQ(chat_photo0.small_file_id, test_small_file_id);    
    ASSERT_EQ(chat_photo0.small_file_unique_id, test_small_file_unique_id);
    ASSERT_EQ(chat_photo0.big_file_id, test_big_file_id);
    ASSERT_EQ(chat_photo0.big_file_unique_id, test_big_file_unique_id);
}

TEST(chat_photo_test, serialize) {
    string json = chat_photo0.toString();
    ChatPhoto chat_photo1(json);
    ASSERT_EQ(chat_photo1.small_file_id, test_small_file_id);    
    ASSERT_EQ(chat_photo1.small_file_unique_id, test_small_file_unique_id);
    ASSERT_EQ(chat_photo1.big_file_id, test_big_file_id);
    ASSERT_EQ(chat_photo1.big_file_unique_id, test_big_file_unique_id);
}

}
