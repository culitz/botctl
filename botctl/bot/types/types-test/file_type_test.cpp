#include "../file.h"
#include <gtest/gtest.h>
#include "../fields.h"
#include <sstream>


namespace test_type_file {
using namespace bot::types;

TEST(test_type_file, from_string) {
    string file_id = "file_id"; 
    string file_unique_id = "file_unique_id"; 
    int file_size = 100; 
    string file_path = "file_path";

    File file0(file_id, file_unique_id, file_size, file_path);
    
    std::string json = file0.toString();
    File file1(json);
    ASSERT_EQ(file1.file_id, file0.file_id);
    ASSERT_EQ(file1.file_unique_id, file0.file_unique_id);
    ASSERT_EQ(file1.file_size, file0.file_size);
    ASSERT_EQ(file1.file_path, file0.file_path);
    
}

}