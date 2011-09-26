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

TEST_F(UserTest, TestHead) {
    ty::Vector v(1.0f, 2.0f, 3.0f);

    ON_CALL(*object, head())
        .WillByDefault(Invoke(object, &MockUser::FakeHead));
    object->setFakeSkeletonPosition(XN_SKEL_HEAD, v);

    ASSERT_TRUE(v == object->head());
}

TEST_F(UserTest, TestNeck) {
    ty::Vector v(1.0f, 2.0f, 3.0f);

    ON_CALL(*object, neck())
        .WillByDefault(Invoke(object, &MockUser::FakeNeck));
    object->setFakeSkeletonPosition(XN_SKEL_NECK, v);

    ASSERT_TRUE(v == object->neck());
}

TEST_F(UserTest, TestTorso) {
    ty::Vector v(1.0f, 2.0f, 3.0f);

    ON_CALL(*object, torso())
        .WillByDefault(Invoke(object, &MockUser::FakeTorso));
    object->setFakeSkeletonPosition(XN_SKEL_TORSO, v);

    ASSERT_TRUE(v == object->torso());
}

TEST_F(UserTest, TestWaist) {
    ty::Vector v(1.0f, 2.0f, 3.0f);

    ON_CALL(*object, waist())
        .WillByDefault(Invoke(object, &MockUser::FakeWaist));
    object->setFakeSkeletonPosition(XN_SKEL_WAIST, v);

    ASSERT_TRUE(v == object->waist());
}

TEST_F(UserTest, TestLeftCollar) {
    ty::Vector v(1.0f, 2.0f, 3.0f);

    ON_CALL(*object, leftCollar())
        .WillByDefault(Invoke(object, &MockUser::FakeLeftCollar));
    object->setFakeSkeletonPosition(XN_SKEL_LEFT_COLLAR, v);

    ASSERT_TRUE(v == object->leftCollar());
}

TEST_F(UserTest, TestLeftShoulder) {
    ty::Vector v(1.0f, 2.0f, 3.0f);

    ON_CALL(*object, leftShoulder())
        .WillByDefault(Invoke(object, &MockUser::FakeLeftShoulder));
    object->setFakeSkeletonPosition(XN_SKEL_LEFT_SHOULDER, v);

    ASSERT_TRUE(v == object->leftShoulder());
}

TEST_F(UserTest, TestLeftElbow) {
    ty::Vector v(1.0f, 2.0f, 3.0f);

    ON_CALL(*object, leftElbow())
        .WillByDefault(Invoke(object, &MockUser::FakeLeftElbow));
    object->setFakeSkeletonPosition(XN_SKEL_LEFT_ELBOW, v);

    ASSERT_TRUE(v == object->leftElbow());
}

TEST_F(UserTest, TestLeftWrist) {
    ty::Vector v(1.0f, 2.0f, 3.0f);

    ON_CALL(*object, leftWrist())
        .WillByDefault(Invoke(object, &MockUser::FakeLeftWrist));
    object->setFakeSkeletonPosition(XN_SKEL_LEFT_WRIST, v);

    ASSERT_TRUE(v == object->leftWrist());
}

TEST_F(UserTest, TestLeftHand) {
    ty::Vector v(1.0f, 2.0f, 3.0f);

    ON_CALL(*object, leftHand())
        .WillByDefault(Invoke(object, &MockUser::FakeLeftHand));
    object->setFakeSkeletonPosition(XN_SKEL_LEFT_HAND, v);

    ASSERT_TRUE(v == object->leftHand());
}

TEST_F(UserTest, TestLeftFingertip) {
    ty::Vector v(1.0f, 2.0f, 3.0f);

    ON_CALL(*object, leftFingertip())
        .WillByDefault(Invoke(object, &MockUser::FakeLeftFingertip));
    object->setFakeSkeletonPosition(XN_SKEL_LEFT_FINGERTIP, v);

    ASSERT_TRUE(v == object->leftFingertip());
}

TEST_F(UserTest, TestRightCollar) {
    ty::Vector v(1.0f, 2.0f, 3.0f);

    ON_CALL(*object, rightCollar())
        .WillByDefault(Invoke(object, &MockUser::FakeRightCollar));
    object->setFakeSkeletonPosition(XN_SKEL_RIGHT_COLLAR, v);

    ASSERT_TRUE(v == object->rightCollar());
}

TEST_F(UserTest, TestRightShoulder) {
    ty::Vector v(1.0f, 2.0f, 3.0f);

    ON_CALL(*object, rightShoulder())
        .WillByDefault(Invoke(object, &MockUser::FakeRightShoulder));
    object->setFakeSkeletonPosition(XN_SKEL_RIGHT_SHOULDER, v);

    ASSERT_TRUE(v == object->rightShoulder());
}

TEST_F(UserTest, TestRightElbow) {
    ty::Vector v(1.0f, 2.0f, 3.0f);

    ON_CALL(*object, rightElbow())
        .WillByDefault(Invoke(object, &MockUser::FakeRightElbow));
    object->setFakeSkeletonPosition(XN_SKEL_RIGHT_ELBOW, v);

    ASSERT_TRUE(v == object->rightElbow());
}

TEST_F(UserTest, TestRightWrist) {
    ty::Vector v(1.0f, 2.0f, 3.0f);

    ON_CALL(*object, rightWrist())
        .WillByDefault(Invoke(object, &MockUser::FakeRightWrist));
    object->setFakeSkeletonPosition(XN_SKEL_RIGHT_WRIST, v);

    ASSERT_TRUE(v == object->rightWrist());
}

TEST_F(UserTest, TestRightHand) {
    ty::Vector v(1.0f, 2.0f, 3.0f);

    ON_CALL(*object, rightHand())
        .WillByDefault(Invoke(object, &MockUser::FakeRightHand));
    object->setFakeSkeletonPosition(XN_SKEL_RIGHT_HAND, v);

    ASSERT_TRUE(v == object->rightHand());
}

TEST_F(UserTest, TestRightFingertip) {
    ty::Vector v(1.0f, 2.0f, 3.0f);

    ON_CALL(*object, rightFingertip())
        .WillByDefault(Invoke(object, &MockUser::FakeRightFingertip));
    object->setFakeSkeletonPosition(XN_SKEL_RIGHT_FINGERTIP, v);

    ASSERT_TRUE(v == object->rightFingertip());
}

TEST_F(UserTest, TestLeftHip) {
    ty::Vector v(1.0f, 2.0f, 3.0f);

    ON_CALL(*object, leftHip())
        .WillByDefault(Invoke(object, &MockUser::FakeLeftHip));
    object->setFakeSkeletonPosition(XN_SKEL_LEFT_HIP, v);

    ASSERT_TRUE(v == object->leftHip());
}

TEST_F(UserTest, TestLeftKnee) {
    ty::Vector v(1.0f, 2.0f, 3.0f);

    ON_CALL(*object, leftKnee())
        .WillByDefault(Invoke(object, &MockUser::FakeLeftKnee));
    object->setFakeSkeletonPosition(XN_SKEL_LEFT_KNEE, v);

    ASSERT_TRUE(v == object->leftKnee());
}

TEST_F(UserTest, TestLeftAnkle) {
    ty::Vector v(1.0f, 2.0f, 3.0f);

    ON_CALL(*object, leftAnkle())
        .WillByDefault(Invoke(object, &MockUser::FakeLeftAnkle));
    object->setFakeSkeletonPosition(XN_SKEL_LEFT_ANKLE, v);

    ASSERT_TRUE(v == object->leftAnkle());
}

TEST_F(UserTest, TestLeftFoot) {
    ty::Vector v(1.0f, 2.0f, 3.0f);

    ON_CALL(*object, leftFoot())
        .WillByDefault(Invoke(object, &MockUser::FakeLeftFoot));
    object->setFakeSkeletonPosition(XN_SKEL_LEFT_FOOT, v);

    ASSERT_TRUE(v == object->leftFoot());
}

TEST_F(UserTest, TestRightHip) {
    ty::Vector v(1.0f, 2.0f, 3.0f);

    ON_CALL(*object, rightHip())
        .WillByDefault(Invoke(object, &MockUser::FakeRightHip));
    object->setFakeSkeletonPosition(XN_SKEL_RIGHT_HIP, v);

    ASSERT_TRUE(v == object->rightHip());
}

TEST_F(UserTest, TestRightKnee) {
    ty::Vector v(1.0f, 2.0f, 3.0f);

    ON_CALL(*object, rightKnee())
        .WillByDefault(Invoke(object, &MockUser::FakeRightKnee));
    object->setFakeSkeletonPosition(XN_SKEL_RIGHT_KNEE, v);

    ASSERT_TRUE(v == object->rightKnee());
}

TEST_F(UserTest, TestRightAnkle) {
    ty::Vector v(1.0f, 2.0f, 3.0f);

    ON_CALL(*object, rightAnkle())
        .WillByDefault(Invoke(object, &MockUser::FakeRightAnkle));
    object->setFakeSkeletonPosition(XN_SKEL_RIGHT_ANKLE, v);

    ASSERT_TRUE(v == object->rightAnkle());
}

TEST_F(UserTest, TestRightFoot) {
    ty::Vector v(1.0f, 2.0f, 3.0f);

    ON_CALL(*object, rightFoot())
        .WillByDefault(Invoke(object, &MockUser::FakeRightFoot));
    object->setFakeSkeletonPosition(XN_SKEL_RIGHT_FOOT, v);

    ASSERT_TRUE(v == object->rightFoot());
}

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

TEST_F(UserTest, TesVectorUpperBodyForward) {
    ON_CALL(*object, vectorUpperBodyForward())
        .WillByDefault(Invoke(object, &MockUser::FakeVectorUpperBodyForward));

    EXPECT_CALL(*object, torso())
        .WillRepeatedly(Return(ty::Vector(0.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*object, rightShoulder())
        .WillOnce(Return(ty::Vector( 3.0f, 3.0f,  0.0f)))
        .WillOnce(Return(ty::Vector( 0.0f, 3.0f,  3.0f)))
        .WillOnce(Return(ty::Vector(-3.0f, 3.0f,  0.0f)))
        .WillOnce(Return(ty::Vector( 0.0f, 3.0f, -3.0f)));
    EXPECT_CALL(*object, leftShoulder())
        .WillOnce(Return(ty::Vector(-3.0f, 3.0f,  0.0f)))
        .WillOnce(Return(ty::Vector( 0.0f, 3.0f, -3.0f)))
        .WillOnce(Return(ty::Vector( 3.0f, 3.0f,  0.0f)))
        .WillOnce(Return(ty::Vector( 0.0f, 3.0f,  3.0f)));

    ASSERT_TRUE(ty::Vector( 0.0f, 0.0f, -1.0f) == object->vectorUpperBodyForward());
    ASSERT_TRUE(ty::Vector( 1.0f, 0.0f,  0.0f) == object->vectorUpperBodyForward());
    ASSERT_TRUE(ty::Vector( 0.0f, 0.0f,  1.0f) == object->vectorUpperBodyForward());
    ASSERT_TRUE(ty::Vector(-1.0f, 0.0f,  0.0f) == object->vectorUpperBodyForward());
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

TEST_F(UserTest, TestIsConfident) {
    ON_CALL(*object, isConfident(_))
        .WillByDefault(Invoke(object, &MockUser::FakeIsConfident));

    XnSkeletonJointPosition p;
    p.position    = ty::Vector(0.0f, 0.0f, 0.0f);

    p.fConfidence = ty::User::THRESHOLD_CONFIDENCE;
    ASSERT_TRUE(object->isConfident(p));

    p.fConfidence = ty::User::THRESHOLD_CONFIDENCE + 0.1;
    ASSERT_TRUE(object->isConfident(p));

    p.fConfidence = ty::User::THRESHOLD_CONFIDENCE - 0.1;
    ASSERT_FALSE(object->isConfident(p));
}
