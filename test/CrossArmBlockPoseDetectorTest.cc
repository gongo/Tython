#include <gtest/gtest.h>
#include "CrossArmBlockPoseDetector.h"
#include "MockUser.h"

using ::testing::Return;

class CrossArmBlockPoseDetectorTest : public testing::Test {
public:
    virtual void SetUp() {
        mock = new MockUser;
        object = new ty::CrossArmBlockPoseDetector(mock);
    }    

    virtual void TearDown() {
        delete object;
        delete mock;
    }
protected:
    ty::CrossArmBlockPoseDetector* object;
    MockUser* mock;
};

TEST_F(CrossArmBlockPoseDetectorTest, TestIsPosing) {
    EXPECT_CALL(*mock, skeletonRightForearm())
        .WillOnce(Return(ty::Vector(0, 100, 0)));
    EXPECT_CALL(*mock, skeletonLeftForearm())
        .WillOnce(Return(ty::Vector(100, 0, 0)));
    
    ASSERT_TRUE(object->isPosing());
}

TEST_F(CrossArmBlockPoseDetectorTest, TestIsPosingError) {
    ASSERT_FALSE(object->isPosing());
}
