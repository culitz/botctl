#include <gtest/gtest.h>
#include <location.h>


namespace location_type_test {


TEST(location_type_test, serialization) {
    float longitude = 245;
    float latitude = 236;
    float horizontal_accuracy = 200;
    int live_period = 300;
    int heading = 234;
    int proximity_alert_radius = 500;
    
    bot::types::Location location0(
        longitude, 
        latitude, 
        horizontal_accuracy,
        live_period,
        heading,
        proximity_alert_radius
    );

    std::string json = location0.toString();
    bot::types::Location location1(json);

    ASSERT_EQ(location0.longitude, location1.longitude);
    ASSERT_EQ(location0.latitude, location1.latitude);
    ASSERT_EQ(location0.horizontal_accuracy, location1.horizontal_accuracy);
    ASSERT_EQ(location0.live_period, location1.live_period);
    ASSERT_EQ(location0.heading, location1.heading);
    ASSERT_EQ(location0.proximity_alert_radius, location1.proximity_alert_radius);
}


}
