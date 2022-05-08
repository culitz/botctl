#include <gtest/gtest.h>
#include "../chat_location.h"
#include "../location.h"


namespace chat_location_test {

using namespace bot::types;

float lon = 1234.23;
float lat = 2345.22;

Location location(lon, lat);
std::string address = "address";
ChatLocation chat_location0(location, address);

TEST(chat_location_test, constructor_params){
    ASSERT_EQ(chat_location0.location, location);
    ASSERT_EQ(chat_location0.address, address);
}

TEST(chat_location_test, serialize) {
    std::string json = chat_location0.toString();
    ChatLocation chat_location1(json);
    ASSERT_EQ(chat_location1.location, location);
    ASSERT_EQ(chat_location1.address, address);
}

}