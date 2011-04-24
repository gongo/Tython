#include <gtest/gtest.h>
#include "Timer.h"

class TimerTest : public testing::Test {
public:
    Timer *object;
protected:
    virtual void SetUp() {
        object = Timer::instance();
    }
};

/**
 * シングルトンが機能しているか
 */
TEST_F(TimerTest, TestGetInstance) {
    Timer *object2 = Timer::instance();

    ASSERT_TRUE(NULL != object);
    ASSERT_TRUE(object == object2);
}

TEST_F(TimerTest, TestCurrent) {
    int time1 = object->current();
    int time2 = object->current();

    ASSERT_LE(time1, time2); 
}
