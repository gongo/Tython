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

#define SET_SKELETON_CALL() do {                                \
        EXPECT_CALL(*mock, positionRightShoulder())             \
            .WillRepeatedly(Return(Vector(0.0f, 1.0f, 0.0f)));  \
        EXPECT_CALL(*mock, positionRightElbow())                \
            .WillRepeatedly(Return(Vector(0.0f, 1.0f, 0.0f)));  \
        EXPECT_CALL(*mock, positionRightHand())                 \
            .WillRepeatedly(Return(Vector(0.0f, 3.0f, 0.0f)));  \
    } while (0)

TEST_F(RightStraightCommandDetectorTest, TestIsPosing) {
    SET_SKELETON_CALL();

    EXPECT_CALL(*mock, rightArmIsStraight())
        .WillRepeatedly(Return(true));
    EXPECT_CALL(*mock, skeletonRightUpperArm())
        .WillRepeatedly(Return(MockVector::v00));
    EXPECT_CALL(*mock, skeletonRightForearm())
        .WillRepeatedly(Return(MockVector::v120));

    ASSERT_FALSE(object->isPosing());
    ASSERT_FALSE(object->isPosing());
    ASSERT_TRUE(object->isPosing());
}

TEST_F(RightStraightCommandDetectorTest, TestIsPosingError) {
    SET_SKELETON_CALL();

    EXPECT_CALL(*mock, rightArmIsStraight())
        .WillRepeatedly(Return(false));
    EXPECT_CALL(*mock, skeletonRightUpperArm())
        .WillRepeatedly(Return(MockVector::v00));
    EXPECT_CALL(*mock, skeletonRightForearm())
        .WillRepeatedly(Return(MockVector::v120));
    
    ASSERT_FALSE(object->isPosing());
    ASSERT_FALSE(object->isPosing());
    ASSERT_FALSE(object->isPosing());
}
