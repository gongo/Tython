#include <gtest/gtest.h>
#include "MockUser.h"

using ::testing::Return;
using ::testing::Invoke;

class UserTest : public testing::Test {
public:
    virtual void SetUp() {
        object = new MockUser;
    }    

    virtual void TearDown() {
        delete object;
    }
protected:
    MockUser* object;
};



TEST_F(UserTest, TestLeftArmIsStriaght) {
    ON_CALL(*object, leftArmIsStraight())
        .WillByDefault(Invoke(object, &MockUser::FakeLeftArmIsStraight));

    EXPECT_CALL(*object, skeletonLeftUpperArm())
        .WillRepeatedly(Return(ty::Vector(3.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*object, skeletonLeftForearm())
        .WillOnce(Return(ty::Vector(3.0f, 0.0f, 0.0f)))
        .WillOnce(Return(ty::Vector(0.0f, 3.0f, 0.0f)));

    ASSERT_TRUE(object->leftArmIsStraight());
    ASSERT_FALSE(object->leftArmIsStraight());
}

TEST_F(UserTest, TestLeftArmIsBentRightAngle) {
    ON_CALL(*object, leftArmIsBentRightAngle())
        .WillByDefault(Invoke(object, &MockUser::FakeLeftArmIsBentRightAngle));

    EXPECT_CALL(*object, skeletonLeftUpperArm())
        .WillRepeatedly(Return(ty::Vector(3.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*object, skeletonLeftForearm())
        .WillOnce(Return(ty::Vector(0.0f, 3.0f, 0.0f)))
        .WillOnce(Return(ty::Vector(3.0f, 0.0f, 0.0f)));

    ASSERT_TRUE(object->leftArmIsBentRightAngle());
    ASSERT_FALSE(object->leftArmIsBentRightAngle());
}

TEST_F(UserTest, TestRightArmIsBentRightAngle) {
    ON_CALL(*object, rightArmIsBentRightAngle())
        .WillByDefault(Invoke(object, &MockUser::FakeRightArmIsBentRightAngle));

    EXPECT_CALL(*object, skeletonRightUpperArm())
        .WillRepeatedly(Return(ty::Vector(3.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*object, skeletonRightForearm())
        .WillOnce(Return(ty::Vector(0.0f, 3.0f, 0.0f)))
        .WillOnce(Return(ty::Vector(3.0f, 0.0f, 0.0f)));

    ASSERT_TRUE(object->rightArmIsBentRightAngle());
    ASSERT_FALSE(object->rightArmIsBentRightAngle());
}

TEST_F(UserTest, TestRightArmIsStriaght) {
    ON_CALL(*object, rightArmIsStraight())
        .WillByDefault(Invoke(object, &MockUser::FakeRightArmIsStraight));

    EXPECT_CALL(*object, skeletonRightUpperArm())
        .WillRepeatedly(Return(ty::Vector(3.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*object, skeletonRightForearm())
        .WillOnce(Return(ty::Vector(3.0f, 0.0f, 0.0f)))
        .WillOnce(Return(ty::Vector(0.0f, 3.0f, 0.0f)));

    ASSERT_TRUE(object->rightArmIsStraight());
    ASSERT_FALSE(object->rightArmIsStraight());
}
