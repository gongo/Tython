
#include <gtest/gtest.h>
#include "TriggerDetector.h"
#include "MockTimer.h"
using ::testing::Return;

#define TIMELIMIT 2

class ExampleTriggerDetector : public TriggerDetector {
public:
    ExampleTriggerDetector(void) : TriggerDetector(NULL) {
        setTrigger(TIMELIMIT, 3,
                   &ExampleTriggerDetector::isProc,
                   &ExampleTriggerDetector::isProc,
                   &ExampleTriggerDetector::isProc);
    }

    void setTimer(Timer *_timer) {
        timer = _timer;
    }

private:
    bool isProc(void) { return true; }
};

class ExampleFailureTriggerDetector : public ExampleTriggerDetector {
public:
    ExampleFailureTriggerDetector(void) : ExampleTriggerDetector() {
        setTrigger(TIMELIMIT, 2,
                   &ExampleFailureTriggerDetector::isProc1,
                   &ExampleFailureTriggerDetector::isProc2);
    }

private:
    bool isProc1(void) {
        return true;
    }

    bool isProc2(void) {
        return false;
    }
};

class ExampleNoSetTriggerDetector : public ExampleTriggerDetector {
public:
    ExampleNoSetTriggerDetector(void) : ExampleTriggerDetector() {}
};

class TriggerDetectorTest : public testing::Test {
public:
    ExampleTriggerDetector *object;
    ExampleFailureTriggerDetector *object2;
    ExampleNoSetTriggerDetector *object3;
protected:
    virtual void SetUp() {
        timer = new MockTimer;
        object = new ExampleTriggerDetector();
        object2 = new ExampleFailureTriggerDetector();
        object3 = new ExampleNoSetTriggerDetector();
        object->setTimer(timer);
        object2->setTimer(timer);
        object3->setTimer(timer);
    }

    virtual void TearDown() {
        delete object;
        delete object2;
        delete object3;
        delete timer;
    }

    MockTimer* timer;
};

TEST_F(TriggerDetectorTest, TestIsPosing) {
    EXPECT_CALL(*timer, current())
        .Times(6)
        .WillRepeatedly(Return(0));

    // 1週目
    ASSERT_FALSE(object->isPosing());
    ASSERT_FALSE(object->isPosing());
    ASSERT_TRUE(object->isPosing());

    // 2週目
    ASSERT_FALSE(object->isPosing());
    ASSERT_FALSE(object->isPosing());
    ASSERT_TRUE(object->isPosing());
}

TEST_F(TriggerDetectorTest, TestIsPosingErrorTimeLimit) {
    EXPECT_CALL(*timer, current())
        .Times(3)
        .WillOnce(Return(0))
        .WillOnce(Return(0))
        .WillOnce(Return(TIMELIMIT+1));

    ASSERT_FALSE(object->isPosing());
    ASSERT_FALSE(object->isPosing());
    ASSERT_FALSE(object->isPosing());
}

TEST_F(TriggerDetectorTest, TestIsPosingError) {
    EXPECT_CALL(*timer, current())
        .Times(4)
        .WillRepeatedly(Return(0));

    // 1週目
    ASSERT_FALSE(object2->isPosing());
    ASSERT_FALSE(object2->isPosing());

    // 2週目
    ASSERT_FALSE(object2->isPosing());
    ASSERT_FALSE(object2->isPosing());
}

TEST_F(TriggerDetectorTest, TestIsPosingErrorNoSetTrigger) {
    EXPECT_CALL(*timer, current())
        .Times(1)
        .WillOnce(Return(0));
    ASSERT_FALSE(object3->isPosing());
}
