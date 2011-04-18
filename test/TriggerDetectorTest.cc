#include <gtest/gtest.h>
#include "TriggerDetector.h"

#define TIMELIMIT 2

class ExampleTriggerDetector : public TriggerDetector {
public:
    ExampleTriggerDetector(void) : TriggerDetector(NULL) {
        setTrigger(TIMELIMIT, 3,
                   &ExampleTriggerDetector::isProc,
                   &ExampleTriggerDetector::isProc,
                   &ExampleTriggerDetector::isProc);
    }

private:
    bool isProc(void) { return true; }
};

class ExampleFailureTriggerDetector : public TriggerDetector {
public:
    ExampleFailureTriggerDetector(void) : TriggerDetector(NULL) {
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

class ExampleNoSetTriggerDetector : public TriggerDetector {
public:
    ExampleNoSetTriggerDetector(void) : TriggerDetector(NULL) {}
};

class TriggerDetectorTest : public testing::Test {
public:
    ExampleTriggerDetector *object;
    ExampleFailureTriggerDetector *object2;
protected:
    virtual void SetUp() {
        object = new ExampleTriggerDetector();
        object2 = new ExampleFailureTriggerDetector();
    }

    virtual void TearDown() {
        delete object;
        delete object2;
    }
};

TEST_F(TriggerDetectorTest, TestIsPosing) {
    // 1週目
    ASSERT_FALSE(object->isPosing());
    ASSERT_FALSE(object->isPosing());
    ASSERT_TRUE(object->isPosing());

    // 2週目
    ASSERT_FALSE(object->isPosing());
    sleep(TIMELIMIT - 1);
    ASSERT_FALSE(object->isPosing());
    ASSERT_TRUE(object->isPosing());
}

TEST_F(TriggerDetectorTest, TestIsPosingError) {
    // 1週目
    ASSERT_FALSE(object2->isPosing());
    ASSERT_FALSE(object2->isPosing());

    // 2週目
    ASSERT_FALSE(object2->isPosing());
    ASSERT_FALSE(object2->isPosing());
}

TEST_F(TriggerDetectorTest, TestIsPosingErrorTimeLimit) {
    ASSERT_FALSE(object->isPosing());
    ASSERT_FALSE(object->isPosing());
    sleep(TIMELIMIT + 1);
    ASSERT_FALSE(object->isPosing());
}

TEST_F(TriggerDetectorTest, TestIsPosingErrorNoSetTrigger) {
    ASSERT_FALSE(object->isPosing());
}
