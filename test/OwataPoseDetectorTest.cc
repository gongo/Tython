#include <gtest/gtest.h>
#include "OwataPoseDetector.h"
#include "MockUser.h"

using ::testing::Return;

class OwataPoseDetectorTest : public testing::Test {
public:
    virtual void SetUp() {
        mock = new MockUser;
        object = new ty::OwataPoseDetector(mock);
    }    

    virtual void TearDown() {
        delete object;
        delete mock;
    }
protected:
    ty::OwataPoseDetector* object;
    MockUser* mock;
};

#define SET_SKELETON_CALL() do {                                        \
        EXPECT_CALL(*mock, vectorRightUpperArm())                     \
            .WillRepeatedly(Return(ty::Vector(1.4f, 1.4f, 0.0f)));      \
        EXPECT_CALL(*mock, vectorLeftUpperArm())                      \
            .WillRepeatedly(Return(ty::Vector(-1.4f, 1.4f, 0.0f)));     \
        EXPECT_CALL(*mock, vectorHead())                              \
            .WillRepeatedly(Return(ty::Vector(0.0f, 1.4f, 0.0f)));      \
        EXPECT_CALL(*mock, head())                                      \
            .WillRepeatedly(Return(ty::Vector(0.0f, 1.0f, 0.0f)));      \
        EXPECT_CALL(*mock, rightHand())                                 \
            .WillRepeatedly(Return(ty::Vector(0.0f, 2.0f, 0.0f)));      \
        EXPECT_CALL(*mock, leftHand())                                  \
            .WillRepeatedly(Return(ty::Vector(0.0f, 2.0f, 0.0f)));      \
    } while (0)

TEST_F(OwataPoseDetectorTest, TestIsPosing) {
    SET_SKELETON_CALL();
    EXPECT_CALL(*mock, rightArmIsStraight()).WillRepeatedly(Return(true));
    EXPECT_CALL(*mock, leftArmIsStraight()).WillRepeatedly(Return(true));
    
    ASSERT_TRUE(object->isPosing());
}

TEST_F(OwataPoseDetectorTest, TestIsPosingError) {
    SET_SKELETON_CALL();
    EXPECT_CALL(*mock, rightArmIsStraight()).WillRepeatedly(Return(true));
    EXPECT_CALL(*mock, leftArmIsStraight()).WillRepeatedly(Return(false));
    
    ASSERT_FALSE(object->isPosing());
}
