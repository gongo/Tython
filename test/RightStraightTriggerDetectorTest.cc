#include <gtest/gtest.h>
#include "RightStraightTriggerDetector.h"
#include "MockUser.h"

using ::testing::Return;

class RightStraightTriggerDetectorTest : public testing::Test {
public:
    virtual void SetUp() {
        mock = new MockUser;
        object = new RightStraightTriggerDetector(mock);
    }    

    virtual void TearDown() {
        delete object;
        delete mock;
    }
protected:
    RightStraightTriggerDetector* object;
    MockUser* mock;
};

TEST_F(RightStraightTriggerDetectorTest, TestIsPosing) {
    EXPECT_CALL(*mock, positionRightShoulder())
        .Times(2)
        .WillRepeatedly(Return(Vector(0.0f, 1.0f, 0.0f)));
    EXPECT_CALL(*mock, positionRightElbow())
        .Times(2)
        .WillRepeatedly(Return(Vector(0.0f, 1.0f, 0.0f)));
    EXPECT_CALL(*mock, positionRightHand())
        .Times(2)
        .WillRepeatedly(Return(Vector(0.0f, 3.0f, 0.0f)));
    EXPECT_CALL(*mock, skeletonRightUpperArm())
        .Times(3)
        .WillRepeatedly(Return(Vector(1.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*mock, skeletonRightForearm())
        .Times(3)
        .WillOnce(Return(Vector(0.34f, 0.93f, 0.0f))) // 70度
        .WillOnce(Return(Vector(1.0f, 0.0f, 0.0f)))
        .WillOnce(Return(Vector(0.34f, 0.93f, 0.0f)));
    ASSERT_FALSE(object->isPosing());
    ASSERT_FALSE(object->isPosing());
    ASSERT_TRUE(object->isPosing());
}

TEST_F(RightStraightTriggerDetectorTest, TestIsPosingError) {
    EXPECT_CALL(*mock, positionRightShoulder())
        .Times(1)
        .WillRepeatedly(Return(Vector(0.0f, 1.0f, 0.0f)));
    EXPECT_CALL(*mock, positionRightElbow())
        .Times(1)
        .WillRepeatedly(Return(Vector(0.0f, 1.0f, 0.0f)));
    EXPECT_CALL(*mock, positionRightHand())
        .Times(1)
        .WillRepeatedly(Return(Vector(0.0f, 3.0f, 0.0f)));
    EXPECT_CALL(*mock, skeletonRightUpperArm())
        .Times(3)
        .WillRepeatedly(Return(Vector(1.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*mock, skeletonRightForearm())
        .Times(3)
        .WillOnce(Return(Vector(0.34f, 0.93f, 0.0f)))
        .WillOnce(Return(Vector(1.0f, 1.0f, 0.0f)))
        .WillOnce(Return(Vector(0.34f, 0.93f, 0.0f)));
    
    ASSERT_FALSE(object->isPosing());
    ASSERT_FALSE(object->isPosing());
    ASSERT_FALSE(object->isPosing());
}
