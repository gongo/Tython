#include <gtest/gtest.h>
#include "RightStraightCommandDetector.h"
#include "MockUser.h"
#include "MockVector.h"

using ::testing::Return;

class RightStraightCommandDetectorTest : public testing::Test {
public:
    virtual void SetUp() {
        mock = new MockUser;
        object = new ty::RightStraightCommandDetector(mock);
    }    

    virtual void TearDown() {
        delete object;
        delete mock;
    }
protected:
    ty::RightStraightCommandDetector* object;
    MockUser* mock;
};

#define SET_SKELETON_CALL() do {                                    \
        EXPECT_CALL(*mock, rightShoulder())                         \
            .WillRepeatedly(Return(ty::Vector(0.0f, 1.0f, 0.0f)));  \
        EXPECT_CALL(*mock, rightElbow())                            \
            .WillRepeatedly(Return(ty::Vector(0.0f, 1.0f, 0.0f)));  \
        EXPECT_CALL(*mock, rightHand())                             \
            .WillRepeatedly(Return(ty::Vector(0.0f, 3.0f, 0.0f)));  \
    } while (0)

TEST_F(RightStraightCommandDetectorTest, TestIsStand) {
    SET_SKELETON_CALL();
    EXPECT_CALL(*mock, vectorRightUpperArm())
        .WillRepeatedly(Return(MockVector::v00));
    EXPECT_CALL(*mock, vectorRightForearm())
        .WillRepeatedly(Return(MockVector::v120));

    ASSERT_TRUE(object->isStand());
}

TEST_F(RightStraightCommandDetectorTest, TestIsStandError) {
    SET_SKELETON_CALL();
    EXPECT_CALL(*mock, vectorRightUpperArm())
        .WillOnce(Return(MockVector::v00));
    EXPECT_CALL(*mock, vectorRightForearm())
        .WillOnce(Return(MockVector::v60));

    ASSERT_FALSE(object->isStand());
}

TEST_F(RightStraightCommandDetectorTest, TestIsRightStraight) {
    SET_SKELETON_CALL();
    EXPECT_CALL(*mock, rightArmIsStraight()).WillOnce(Return(true));
    ASSERT_TRUE(object->isRightStraight());
}

TEST_F(RightStraightCommandDetectorTest, TestIsRightStraightError) {
    SET_SKELETON_CALL();
    EXPECT_CALL(*mock, rightArmIsStraight()).WillOnce(Return(false));
    ASSERT_FALSE(object->isRightStraight());
}
