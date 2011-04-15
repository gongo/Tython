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

TEST_F(TimerTest, TestGetInstance) {
    ASSERT_TRUE(NULL != object);
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
