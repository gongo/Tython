#include <gtest/gtest.h>
#include "Timer.h"

class TimerTest : public testing::Test {
public:
    Timer *object;
protected:
    virtual void SetUp() {
        object = Timer::getInstance();
    }
};

/**
 * シングルトンが機能しているか
 */
TEST_F(TimerTest, TestGetInstance) {
    Timer *object2 = Timer::getInstance();

    ASSERT_TRUE(NULL != object);
    ASSERT_TRUE(object == object2);
}

TEST_F(TimerTest, TestCurrent) {
    int wait = 2; // sec
    double start = object->current();
    sleep(wait);
    double stop = object->current();

    // wait - 1 < time < wait + 1
    ASSERT_LT(wait-1, stop - start); 
    ASSERT_LT(stop - start, wait+1);
}
