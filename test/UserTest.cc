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

TEST_F(UserTest, TesSkeletonRightUpperArm) {
    ON_CALL(*object, skeletonRightUpperArm())
        .WillByDefault(Invoke(object, &MockUser::FakeSkeletonRightUpperArm));

    EXPECT_CALL(*object, positionRightShoulder())
        .WillOnce(Return(ty::Vector(0.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*object, positionRightElbow())
        .WillOnce(Return(ty::Vector(3.0f, 3.0f, 0.0f)));

    ASSERT_TRUE(ty::Vector(3.0f, 3.0f, 0.0f) == object->skeletonRightUpperArm());
}

TEST_F(UserTest, TesSkeletonRightForearm) {
    ON_CALL(*object, skeletonRightForearm())
        .WillByDefault(Invoke(object, &MockUser::FakeSkeletonRightForearm));

    EXPECT_CALL(*object, positionRightElbow())
        .WillOnce(Return(ty::Vector(0.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*object, positionRightHand())
        .WillOnce(Return(ty::Vector(3.0f, 3.0f, 0.0f)));

    ASSERT_TRUE(ty::Vector(3.0f, 3.0f, 0.0f) == object->skeletonRightForearm());
}

TEST_F(UserTest, TesSkeletonLeftUpperArm) {
    ON_CALL(*object, skeletonLeftUpperArm())
        .WillByDefault(Invoke(object, &MockUser::FakeSkeletonLeftUpperArm));

    EXPECT_CALL(*object, positionLeftShoulder())
        .WillOnce(Return(ty::Vector(0.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*object, positionLeftElbow())
        .WillOnce(Return(ty::Vector(3.0f, 3.0f, 0.0f)));

    ASSERT_TRUE(ty::Vector(3.0f, 3.0f, 0.0f) == object->skeletonLeftUpperArm());
}

TEST_F(UserTest, TesSkeletonLeftForearm) {
    ON_CALL(*object, skeletonLeftForearm())
        .WillByDefault(Invoke(object, &MockUser::FakeSkeletonLeftForearm));

    EXPECT_CALL(*object, positionLeftElbow())
        .WillOnce(Return(ty::Vector(0.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*object, positionLeftHand())
        .WillOnce(Return(ty::Vector(3.0f, 3.0f, 0.0f)));

    ASSERT_TRUE(ty::Vector(3.0f, 3.0f, 0.0f) == object->skeletonLeftForearm());
}

TEST_F(UserTest, TesSkeletonRightUpperThigh) {
    ON_CALL(*object, skeletonRightUpperThigh())
        .WillByDefault(Invoke(object, &MockUser::FakeSkeletonRightUpperThigh));

    EXPECT_CALL(*object, positionRightHip())
        .WillOnce(Return(ty::Vector(0.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*object, positionRightKnee())
        .WillOnce(Return(ty::Vector(3.0f, 3.0f, 0.0f)));

    ASSERT_TRUE(ty::Vector(3.0f, 3.0f, 0.0f) == object->skeletonRightUpperThigh());
}

TEST_F(UserTest, TesSkeletonRightLowerThigh) {
    ON_CALL(*object, skeletonRightLowerThigh())
        .WillByDefault(Invoke(object, &MockUser::FakeSkeletonRightLowerThigh));

    EXPECT_CALL(*object, positionRightKnee())
        .WillOnce(Return(ty::Vector(0.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*object, positionRightAnkle())
        .WillOnce(Return(ty::Vector(3.0f, 3.0f, 0.0f)));

    ASSERT_TRUE(ty::Vector(3.0f, 3.0f, 0.0f) == object->skeletonRightLowerThigh());
}

TEST_F(UserTest, TesSkeletonLeftUpperThigh) {
    ON_CALL(*object, skeletonLeftUpperThigh())
        .WillByDefault(Invoke(object, &MockUser::FakeSkeletonLeftUpperThigh));

    EXPECT_CALL(*object, positionLeftHip())
        .WillOnce(Return(ty::Vector(0.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*object, positionLeftKnee())
        .WillOnce(Return(ty::Vector(3.0f, 3.0f, 0.0f)));

    ASSERT_TRUE(ty::Vector(3.0f, 3.0f, 0.0f) == object->skeletonLeftUpperThigh());
}

TEST_F(UserTest, TesSkeletonLeftLowerThigh) {
    ON_CALL(*object, skeletonLeftLowerThigh())
        .WillByDefault(Invoke(object, &MockUser::FakeSkeletonLeftLowerThigh));

    EXPECT_CALL(*object, positionLeftKnee())
        .WillOnce(Return(ty::Vector(0.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*object, positionLeftAnkle())
        .WillOnce(Return(ty::Vector(3.0f, 3.0f, 0.0f)));

    ASSERT_TRUE(ty::Vector(3.0f, 3.0f, 0.0f) == object->skeletonLeftLowerThigh());
}

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
