#include <gtest/gtest.h>
#include <message_auto_delete_timer_changed.h>

namespace message_auto_delete_timer_changed {

using namespace bot::types;

TEST(message_auto_delete_timer_changed, serialization) {
    MessageAutoDeleteTimerChanged m0(200);
    std::string json = m0.toString();
    MessageAutoDeleteTimerChanged m1(json);
    ASSERT_EQ(m0.message_auto_delete_time, m1.message_auto_delete_time);
}

}
