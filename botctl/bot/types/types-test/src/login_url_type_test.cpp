#include <gtest/gtest.h>
#include <login_url.h>
#include <optional>

namespace login_url_type_test {

using namespace std;

TEST(login_url_type_test, serialization) {
    std::string url = "url";
    std::optional<string> forward_text = "forward_text";
    std::optional<string> bot_username = "bot_username";
    std::optional<bool> request_write_access = true;
    
    bot::types::LoginUrl login_url0(url, forward_text, bot_username, request_write_access);
    std::string json = login_url0.toString();
    bot::types::LoginUrl login_url1(json);

    ASSERT_EQ(login_url1.forward_text, forward_text);
    ASSERT_EQ(login_url1.bot_username, bot_username);
    ASSERT_EQ(login_url1.request_write_access, request_write_access);
}


}
