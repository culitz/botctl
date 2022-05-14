#include <gtest/gtest.h>
#include <user.h>
#include <proximity_alert_triggered.h>


namespace test_proximity_alert_triggered {

using namespace bot::types;

TEST(proximity_alert_triggered_type_test, serialization) {
    User traveler("user1", true);
    User watcher("user2", true);
    ProximityAlertTriggered pat0(traveler, watcher, 100);
    std::string json = pat0.toString();
    ProximityAlertTriggered pat1(json);

    ASSERT_EQ(pat0.traveler.first_name, pat1.traveler.first_name);
    ASSERT_EQ(pat0.watcher.is_bot, pat1.watcher.is_bot);
    ASSERT_EQ(pat0.distance, pat1.distance);
}

}
