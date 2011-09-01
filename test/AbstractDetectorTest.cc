#include <gtest/gtest.h>
#include "AbstractDetector.h"
#include "MockUser.h"

using ::testing::Return;

class SuccessAbstractDetector : public ty::AbstractDetector {
public:
    SuccessAbstractDetector(ty::User* _user) : AbstractDetector(_user) {}

    bool isPosing(void) {
        return true;
    }
};

class FailureAbstractDetector : public ty::AbstractDetector {
public:
    FailureAbstractDetector(ty::User* _user) : AbstractDetector(_user) {}

    bool isPosing(void) {
        return false;
    }
};

class AbstractDetectorTest : public testing::Test {
public:
    virtual void SetUp() {
        user = new MockUser;
        s_object = new SuccessAbstractDetector(user);
        f_object = new FailureAbstractDetector(user);
    }    

    virtual void TearDown() {
        delete f_object;
        delete s_object;
        delete user;
    }

protected:
    SuccessAbstractDetector* s_object;
    FailureAbstractDetector* f_object;
    MockUser* user;
};

TEST_F(AbstractDetectorTest, TestIsDetect) {
    ASSERT_TRUE(s_object->detect());
}

TEST_F(AbstractDetectorTest, TestIsDetectError) {
    ASSERT_FALSE(f_object->detect());
}

TEST_F(AbstractDetectorTest, TestIsDetectErrorNoCalibrated) {
    EXPECT_CALL(*user, isCalibrated()).WillOnce(Return(false));
    ASSERT_FALSE(s_object->detect());
}
