#include <gtest/gtest.h>
#include "../login_url.h"


namespace login_url_type_test {


TEST(login_url_type_test, serialization) {
    string url = "url";
    std::optional<string> forward_text = "forward_text";
    std::optional<string> bot_username = "bot_username";
    std::optional<bool> request_write_access = true;
    
    bot::types::LoginUrl login_url0(url, forward_text, bot_username, request_write_access);
    std::string json = login_url0.toString();
    bot::types::LoginUrl login_url1(json);

    ASSERT_EQ(login_url0.longitude, login_url1.longitude);
    ASSERT_EQ(login_url0.latitude, login_url1.latitude);
    ASSERT_EQ(login_url0.horizontal_accuracy, login_url1.horizontal_accuracy);
    ASSERT_EQ(login_url0.live_period, login_url1.live_period);
    ASSERT_EQ(login_url0.heading, login_url1.heading);
    ASSERT_EQ(login_url0.proximity_alert_radius, login_url1.proximity_alert_radius);
}


}