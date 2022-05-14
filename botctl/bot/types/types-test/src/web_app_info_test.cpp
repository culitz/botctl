#include <gtest/gtest.h>
#include <web_app_info.h>


namespace web_app_info_test {

using namespace std;
using namespace bot::types;

TEST(web_app_info_test, serialize) {
    WebAppInfo info;
    info.url = "https://url.com";
    string json = info.toString();
    WebAppInfo info1(json);
    ASSERT_EQ(info1.url, info.url);
}


}
