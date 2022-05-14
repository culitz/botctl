#include <gtest/gtest.h>
#include "callbackquery.h"
#include "user.h"

namespace callbackquery_test {

using namespace std;
using namespace bot::types;

User user("user", false);
CallbackQuery query0(user);

TEST(callbackquery_test, constructor_params) {
    ASSERT_EQ(user.first_name, query0.from.first_name);
    ASSERT_EQ(user.is_bot, query0.from.is_bot);
}

TEST(callbackquery_test, serialize) {
    string json = query0.toString();
    CallbackQuery query1(json);

    ASSERT_EQ(user.first_name, query1.from.first_name);
    ASSERT_EQ(user.is_bot, query1.from.is_bot);
}

}
