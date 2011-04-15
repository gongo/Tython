#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "TriggerDetector.h"
using ::testing::Return;

class ExampleTriggerDetector : public TriggerDetector {
public:
    ExampleTriggerDetector(void) : TriggerDetector(NULL) {
        setTrigger(timeLimit, 2,
                   &ExampleTriggerDetector::isProc1,
                   &ExampleTriggerDetector::isProc2);
    }

    static int timeLimit;

private:
    bool isProc1(void) {
        return true;
    }

    bool isProc2(void) {
        return true;
    }
};

int ExampleTriggerDetector::timeLimit = 2;

class TriggerDetectorTest : public testing::Test {
public:
    ExampleTriggerDetector *object;
protected:
    virtual void SetUp() {
        object = new ExampleTriggerDetector();
    }
};

TEST_F(TriggerDetectorTest, TestIsPosing) {
    ASSERT_FALSE(object->isPosing());
    ASSERT_TRUE(object->isPosing());

    ASSERT_FALSE(object->isPosing());
    sleep(ExampleTriggerDetector::timeLimit - 1);
    ASSERT_TRUE(object->isPosing());
}

TEST_F(TriggerDetectorTest, TestIsPosingError) {
    ASSERT_FALSE(object->isPosing());
    ASSERT_FALSE(object->isPosing());
}

TEST_F(TriggerDetectorTest, TestIsPosingErrorTimeLimit) {
    ASSERT_FALSE(object->isPosing());
    sleep(ExampleTriggerDetector::timeLimit + 1);
    ASSERT_FALSE(object->isPosing());
}
