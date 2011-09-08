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

TEST_F(UserTest, TesVectorRightUpperArm) {
    ON_CALL(*object, vectorRightUpperArm())
        .WillByDefault(Invoke(object, &MockUser::FakeVectorRightUpperArm));

    EXPECT_CALL(*object, rightShoulder())
        .WillOnce(Return(ty::Vector(0.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*object, rightElbow())
        .WillOnce(Return(ty::Vector(3.0f, 3.0f, 0.0f)));

    ASSERT_TRUE(ty::Vector(3.0f, 3.0f, 0.0f) == object->vectorRightUpperArm());
}

TEST_F(UserTest, TesVectorRightForearm) {
    ON_CALL(*object, vectorRightForearm())
        .WillByDefault(Invoke(object, &MockUser::FakeVectorRightForearm));

    EXPECT_CALL(*object, rightElbow())
        .WillOnce(Return(ty::Vector(0.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*object, rightHand())
        .WillOnce(Return(ty::Vector(3.0f, 3.0f, 0.0f)));

    ASSERT_TRUE(ty::Vector(3.0f, 3.0f, 0.0f) == object->vectorRightForearm());
}

TEST_F(UserTest, TesVectorLeftUpperArm) {
    ON_CALL(*object, vectorLeftUpperArm())
        .WillByDefault(Invoke(object, &MockUser::FakeVectorLeftUpperArm));

    EXPECT_CALL(*object, leftShoulder())
        .WillOnce(Return(ty::Vector(0.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*object, leftElbow())
        .WillOnce(Return(ty::Vector(3.0f, 3.0f, 0.0f)));

    ASSERT_TRUE(ty::Vector(3.0f, 3.0f, 0.0f) == object->vectorLeftUpperArm());
}

TEST_F(UserTest, TesVectorLeftForearm) {
    ON_CALL(*object, vectorLeftForearm())
        .WillByDefault(Invoke(object, &MockUser::FakeVectorLeftForearm));

    EXPECT_CALL(*object, leftElbow())
        .WillOnce(Return(ty::Vector(0.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*object, leftHand())
        .WillOnce(Return(ty::Vector(3.0f, 3.0f, 0.0f)));

    ASSERT_TRUE(ty::Vector(3.0f, 3.0f, 0.0f) == object->vectorLeftForearm());
}

TEST_F(UserTest, TesVectorRightUpperThigh) {
    ON_CALL(*object, vectorRightUpperThigh())
        .WillByDefault(Invoke(object, &MockUser::FakeVectorRightUpperThigh));

    EXPECT_CALL(*object, rightHip())
        .WillOnce(Return(ty::Vector(0.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*object, rightKnee())
        .WillOnce(Return(ty::Vector(3.0f, 3.0f, 0.0f)));

    ASSERT_TRUE(ty::Vector(3.0f, 3.0f, 0.0f) == object->vectorRightUpperThigh());
}

TEST_F(UserTest, TesVectorRightLowerThigh) {
    ON_CALL(*object, vectorRightLowerThigh())
        .WillByDefault(Invoke(object, &MockUser::FakeVectorRightLowerThigh));

    EXPECT_CALL(*object, rightKnee())
        .WillOnce(Return(ty::Vector(0.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*object, rightAnkle())
        .WillOnce(Return(ty::Vector(3.0f, 3.0f, 0.0f)));

    ASSERT_TRUE(ty::Vector(3.0f, 3.0f, 0.0f) == object->vectorRightLowerThigh());
}

TEST_F(UserTest, TesVectorLeftUpperThigh) {
    ON_CALL(*object, vectorLeftUpperThigh())
        .WillByDefault(Invoke(object, &MockUser::FakeVectorLeftUpperThigh));

    EXPECT_CALL(*object, leftHip())
        .WillOnce(Return(ty::Vector(0.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*object, leftKnee())
        .WillOnce(Return(ty::Vector(3.0f, 3.0f, 0.0f)));

    ASSERT_TRUE(ty::Vector(3.0f, 3.0f, 0.0f) == object->vectorLeftUpperThigh());
}

TEST_F(UserTest, TesVectorLeftLowerThigh) {
    ON_CALL(*object, vectorLeftLowerThigh())
        .WillByDefault(Invoke(object, &MockUser::FakeVectorLeftLowerThigh));

    EXPECT_CALL(*object, leftKnee())
        .WillOnce(Return(ty::Vector(0.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*object, leftAnkle())
        .WillOnce(Return(ty::Vector(3.0f, 3.0f, 0.0f)));

    ASSERT_TRUE(ty::Vector(3.0f, 3.0f, 0.0f) == object->vectorLeftLowerThigh());
}

TEST_F(UserTest, TestLeftArmIsStriaght) {
    ON_CALL(*object, leftArmIsStraight())
        .WillByDefault(Invoke(object, &MockUser::FakeLeftArmIsStraight));

    EXPECT_CALL(*object, vectorLeftUpperArm())
        .WillRepeatedly(Return(ty::Vector(3.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*object, vectorLeftForearm())
        .WillOnce(Return(ty::Vector(3.0f, 0.0f, 0.0f)))
        .WillOnce(Return(ty::Vector(0.0f, 3.0f, 0.0f)));

    ASSERT_TRUE(object->leftArmIsStraight());
    ASSERT_FALSE(object->leftArmIsStraight());
}

TEST_F(UserTest, TestLeftArmIsBentRightAngle) {
    ON_CALL(*object, leftArmIsBentRightAngle())
        .WillByDefault(Invoke(object, &MockUser::FakeLeftArmIsBentRightAngle));

    EXPECT_CALL(*object, vectorLeftUpperArm())
        .WillRepeatedly(Return(ty::Vector(3.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*object, vectorLeftForearm())
        .WillOnce(Return(ty::Vector(0.0f, 3.0f, 0.0f)))
        .WillOnce(Return(ty::Vector(3.0f, 0.0f, 0.0f)));

    ASSERT_TRUE(object->leftArmIsBentRightAngle());
    ASSERT_FALSE(object->leftArmIsBentRightAngle());
}

TEST_F(UserTest, TestRightArmIsBentRightAngle) {
    ON_CALL(*object, rightArmIsBentRightAngle())
        .WillByDefault(Invoke(object, &MockUser::FakeRightArmIsBentRightAngle));

    EXPECT_CALL(*object, vectorRightUpperArm())
        .WillRepeatedly(Return(ty::Vector(3.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*object, vectorRightForearm())
        .WillOnce(Return(ty::Vector(0.0f, 3.0f, 0.0f)))
        .WillOnce(Return(ty::Vector(3.0f, 0.0f, 0.0f)));

    ASSERT_TRUE(object->rightArmIsBentRightAngle());
    ASSERT_FALSE(object->rightArmIsBentRightAngle());
}

TEST_F(UserTest, TestRightArmIsStriaght) {
    ON_CALL(*object, rightArmIsStraight())
        .WillByDefault(Invoke(object, &MockUser::FakeRightArmIsStraight));

    EXPECT_CALL(*object, vectorRightUpperArm())
        .WillRepeatedly(Return(ty::Vector(3.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*object, vectorRightForearm())
        .WillOnce(Return(ty::Vector(3.0f, 0.0f, 0.0f)))
        .WillOnce(Return(ty::Vector(0.0f, 3.0f, 0.0f)));

    ASSERT_TRUE(object->rightArmIsStraight());
    ASSERT_FALSE(object->rightArmIsStraight());
}
