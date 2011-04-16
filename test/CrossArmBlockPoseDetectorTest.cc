#include <gtest/gtest.h>
#include "CrossArmBlockPoseDetector.h"
#include "MockUser.h"

using ::testing::Return;

class CrossArmBlockPoseDetectorTest : public testing::Test {
protected:
    CrossArmBlockPoseDetector* object;
};

TEST_F(CrossArmBlockPoseDetectorTest, TestIsPosing) {
    MockUser mock;

    EXPECT_CALL(mock, skeletonRightForearm()).WillOnce(Return(Vector(0, 100, 0)));
    EXPECT_CALL(mock, skeletonLeftForearm()).WillOnce(Return(Vector(-100, 0, 0)));

    object = new CrossArmBlockPoseDetector(&mock);
    
    ASSERT_TRUE(object->isPosing());
}

TEST_F(CrossArmBlockPoseDetectorTest, TestIsPosingError) {
    MockUser mock;

    EXPECT_CALL(mock, skeletonRightForearm()).WillOnce(Return(Vector(0, 100, 0)));
    EXPECT_CALL(mock, skeletonLeftForearm()).WillOnce(Return(Vector(0, 100, 0)));

    object = new CrossArmBlockPoseDetector(&mock);
    
    ASSERT_FALSE(object->isPosing());
}
