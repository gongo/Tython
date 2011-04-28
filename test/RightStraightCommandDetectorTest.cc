#include <gtest/gtest.h>
#include "RightStraightCommandDetector.h"
#include "MockUser.h"
#include "MockVector.h"

using ::testing::Return;

class RightStraightCommandDetectorTest : public testing::Test {
public:
    virtual void SetUp() {
        mock = new MockUser;
        object = new RightStraightCommandDetector(mock);
    }    

    virtual void TearDown() {
        delete object;
        delete mock;
    }
protected:
    RightStraightCommandDetector* object;
    MockUser* mock;
};

TEST_F(RightStraightCommandDetectorTest, TestIsPosing) {
    EXPECT_CALL(*mock, positionRightShoulder())
        .WillRepeatedly(Return(Vector(0.0f, 1.0f, 0.0f)));
    EXPECT_CALL(*mock, positionRightElbow())
        .WillRepeatedly(Return(Vector(0.0f, 1.0f, 0.0f)));
    EXPECT_CALL(*mock, positionRightHand())
        .WillRepeatedly(Return(Vector(0.0f, 3.0f, 0.0f)));

    EXPECT_CALL(*mock, skeletonRightUpperArm())
        .Times(3).WillRepeatedly(Return(MockVector::v00));
    EXPECT_CALL(*mock, skeletonRightForearm())
        .Times(3)
        .WillOnce(Return(MockVector::v120))
        .WillOnce(Return(MockVector::v00))
        .WillOnce(Return(MockVector::v120));

    ASSERT_FALSE(object->isPosing());
    ASSERT_FALSE(object->isPosing());
    ASSERT_TRUE(object->isPosing());
}

TEST_F(RightStraightCommandDetectorTest, TestIsPosingError) {
    EXPECT_CALL(*mock, positionRightShoulder())
        .WillRepeatedly(Return(Vector(0.0f, 1.0f, 0.0f)));
    EXPECT_CALL(*mock, positionRightElbow())
        .WillRepeatedly(Return(Vector(0.0f, 1.0f, 0.0f)));
    EXPECT_CALL(*mock, positionRightHand())
        .WillRepeatedly(Return(Vector(0.0f, 3.0f, 0.0f)));

    EXPECT_CALL(*mock, skeletonRightUpperArm())
        .Times(3).WillRepeatedly(Return(MockVector::v00));
    EXPECT_CALL(*mock, skeletonRightForearm())
        .Times(3)
        .WillOnce(Return(MockVector::v60))
        .WillOnce(Return(MockVector::v30))
        .WillOnce(Return(MockVector::v60));
    
    ASSERT_FALSE(object->isPosing());
    ASSERT_FALSE(object->isPosing());
    ASSERT_FALSE(object->isPosing());
}
