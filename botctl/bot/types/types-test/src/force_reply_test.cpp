#include <gtest/gtest.h>
#include <force_reply.h>

namespace force_reply_test {

using namespace std;
using namespace bot::types;

bool FORCE_REPLY = true;
string PLACEHOLDER = "&";
bool SELECTIVE = true;

ForceReply f0(FORCE_REPLY, PLACEHOLDER, SELECTIVE);

TEST(force_reply_test, constructor_params) {
    ASSERT_EQ(f0.force_reply, FORCE_REPLY);
    ASSERT_EQ(*f0.input_field_placeholder, PLACEHOLDER);
    ASSERT_EQ(*f0.selective, SELECTIVE);
}


TEST(force_reply_test, serialize) {
    string json = f0.toString();
    ForceReply f1(json);
    ASSERT_EQ(f1.force_reply, FORCE_REPLY);
    ASSERT_EQ(*f1.input_field_placeholder, PLACEHOLDER);
    ASSERT_EQ(*f1.selective, SELECTIVE);
}

}
