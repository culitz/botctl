#include <iostream>
#include "botctl/bot/types/base_file.h"
#include <sstream>
#

int main()
{
    std::stringstream ss;
    std::string file_id = "fl";
    std::string file_unique_id = "uid";
    ss << "{"
       << "\"file_id\":" << "\""<< file_id << "\", "
       << "\"file_unique_id\":" << "\"" << file_unique_id << "\""
       << "}";
    std::cout << ss.str() <<std::endl;
    bot::types::BaseFile b(ss.str());
}
