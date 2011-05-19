
#include <gtest/gtest.h>
#include "CommandDetector.h"
#include "MockTimer.h"
using ::testing::Return;

#define TIMELIMIT 2

class ExampleCommandDetector : public CommandDetector {
public:
    ExampleCommandDetector(void) : CommandDetector(NULL) { }

    void setTimer(Timer *_timer) {
        timer = _timer;
    }

    bool successProc(void) {
        return true;
    }

    bool failureProc(void) {
        return false;
    }
};

class ExampleSuccessCommandDetector : public ExampleCommandDetector {
public:
    ExampleSuccessCommandDetector(void) : ExampleCommandDetector() {
        setCommand(TIMELIMIT, 3,
                   &ExampleCommandDetector::successProc,
                   &ExampleCommandDetector::successProc,
                   &ExampleCommandDetector::successProc);
    }
};

class ExampleFailureCommandDetector : public ExampleCommandDetector {
public:
    ExampleFailureCommandDetector(void) : ExampleCommandDetector() {
        setCommand(TIMELIMIT, 2,
                   &ExampleCommandDetector::successProc,
                   &ExampleCommandDetector::failureProc);
    }
};

class ExampleNoSetCommandDetector : public ExampleCommandDetector {
public:
    ExampleNoSetCommandDetector(void) : ExampleCommandDetector() {}
};

class CommandDetectorTest : public testing::Test {
public:
    ExampleSuccessCommandDetector *object;
    ExampleFailureCommandDetector *object2;
    ExampleNoSetCommandDetector *object3;

protected:
    virtual void SetUp() {
        timer = new MockTimer;
        object = new ExampleSuccessCommandDetector();
        object2 = new ExampleFailureCommandDetector();
        object3 = new ExampleNoSetCommandDetector();
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

TEST_F(CommandDetectorTest, TestIsPosing) {
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

TEST_F(CommandDetectorTest, TestIsPosingErrorTimeLimit) {
    EXPECT_CALL(*timer, current())
        .Times(3)
        .WillOnce(Return(0))
        .WillOnce(Return(0))
        .WillOnce(Return(TIMELIMIT+1));

    ASSERT_FALSE(object->isPosing());
    ASSERT_FALSE(object->isPosing());
    ASSERT_FALSE(object->isPosing());
}

TEST_F(CommandDetectorTest, TestIsPosingError) {
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

TEST_F(CommandDetectorTest, TestIsPosingErrorNoSetCommand) {
    ASSERT_FALSE(object3->isPosing());
}
