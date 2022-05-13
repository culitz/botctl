#include <gtest/gtest.h>
#include "../response_parameters.h"


namespace response_parameters_test {

using namespace bot::types;
using namespace std;

int migrate_to_chat_id;
int retry_after;
ResponseParameters params0(migrate_to_chat_id, retry_after);

TEST(response_parameters_test, constructor_params) {
    ASSERT_EQ(params0.migrate_to_chat_id, migrate_to_chat_id);
    ASSERT_EQ(params0.retry_after, retry_after);
}

TEST(response_parameters_test, serialize) {
    string json = params0.toString();
    ResponseParameters params1(json);
    ASSERT_EQ(params1.migrate_to_chat_id, migrate_to_chat_id);
    ASSERT_EQ(params1.retry_after, retry_after);
}

}