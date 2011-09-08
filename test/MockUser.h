// -*- C++ -*-

#ifndef _TYTHON_MOCK_USER_H
#define _TYTHON_MOCK_USER_H

#include <gmock/gmock.h>
#include "User.h"

using ::testing::Return;
using ::testing::_;

class MockUser : public ty::User {
public:
    MockUser(void) : User(NULL) {
        ON_CALL(*this, isTracking()).WillByDefault(Return(true));
        ON_CALL(*this, isCalibrated()).WillByDefault(Return(true));
        ON_CALL(*this, isConfident(_)).WillByDefault(Return(true));
    }
    virtual ~MockUser(void) {}

    void setFakeSkeletonPosition(XnSkeletonJoint j, ty::Vector v) {
        skeletonPosition[j - 1].position = v;
    }

    MOCK_METHOD0(vectorRightUpperArm, ty::Vector(void));
    MOCK_METHOD0(vectorRightForearm, ty::Vector(void));
    MOCK_METHOD0(vectorLeftUpperArm, ty::Vector(void));
    MOCK_METHOD0(vectorLeftForearm, ty::Vector(void));
    MOCK_METHOD0(vectorRightUpperThigh, ty::Vector(void));
    MOCK_METHOD0(vectorRightLowerThigh, ty::Vector(void));
    MOCK_METHOD0(vectorLeftUpperThigh, ty::Vector(void));
    MOCK_METHOD0(vectorLeftLowerThigh, ty::Vector(void));
    MOCK_METHOD0(vectorHead, ty::Vector(void));
    MOCK_METHOD0(head, ty::Vector(void));
    MOCK_METHOD0(neck, ty::Vector(void));
    MOCK_METHOD0(rightShoulder, ty::Vector(void));
    MOCK_METHOD0(rightElbow, ty::Vector(void));
    MOCK_METHOD0(rightHand, ty::Vector(void));
    MOCK_METHOD0(leftShoulder, ty::Vector(void));
    MOCK_METHOD0(leftElbow, ty::Vector(void));
    MOCK_METHOD0(leftHand, ty::Vector(void));
    MOCK_METHOD0(rightHip, ty::Vector(void));
    MOCK_METHOD0(rightKnee, ty::Vector(void));
    MOCK_METHOD0(rightAnkle, ty::Vector(void));
    MOCK_METHOD0(rightFoot, ty::Vector(void));
    MOCK_METHOD0(leftHip, ty::Vector(void));
    MOCK_METHOD0(leftKnee, ty::Vector(void));
    MOCK_METHOD0(leftAnkle, ty::Vector(void));
    MOCK_METHOD0(leftFoot, ty::Vector(void));
    MOCK_METHOD0(waist, ty::Vector(void));
    MOCK_METHOD0(rightArmIsStraight, bool(void));
    MOCK_METHOD0(leftArmIsStraight, bool(void));
    MOCK_METHOD0(rightArmIsBentRightAngle, bool(void));
    MOCK_METHOD0(leftArmIsBentRightAngle, bool(void));
    MOCK_METHOD0(isTracking, bool(void));
    MOCK_METHOD0(isCalibrated, bool(void));
    MOCK_CONST_METHOD1(isConfident, bool(XnSkeletonJointPosition p));

    ty::Vector FakeVectorRightUpperArm(void) {
        return ty::User::vectorRightUpperArm();
    }
    ty::Vector FakeVectorRightForearm(void) {
        return ty::User::vectorRightForearm();
    }
    ty::Vector FakeVectorLeftUpperArm(void) {
        return ty::User::vectorLeftUpperArm();
    }
    ty::Vector FakeVectorLeftForearm(void) {
        return ty::User::vectorLeftForearm();
    }
    ty::Vector FakeVectorRightUpperThigh(void) {
        return ty::User::vectorRightUpperThigh();
    }
    ty::Vector FakeVectorRightLowerThigh(void) {
        return ty::User::vectorRightLowerThigh();
    }
    ty::Vector FakeVectorLeftUpperThigh(void) {
        return ty::User::vectorLeftUpperThigh();
    }
    ty::Vector FakeVectorLeftLowerThigh(void) {
        return ty::User::vectorLeftLowerThigh();
    }
    ty::Vector FakeVectorHead(void) {
        return ty::User::vectorHead();
    }
    ty::Vector FakeHead(void) {
        return ty::User::head();
    }
    ty::Vector FakeNeck(void) {
        return ty::User::neck();
    }
    ty::Vector FakeRightShoulder(void) {
        return ty::User::rightShoulder();
    }
    ty::Vector FakeRightElbow(void) {
        return ty::User::rightElbow();
    }
    ty::Vector FakeRightHand(void) {
        return ty::User::leftHand();
    }
    ty::Vector FakeLeftShoulder(void) {
        return ty::User::leftShoulder();
    }
    ty::Vector FakeLeftElbow(void) {
        return ty::User::leftElbow();
    }
    ty::Vector FakeLeftHand(void) {
        return ty::User::leftHand();
    }
    ty::Vector FakeRightHip(void) {
        return ty::User::rightHip();
    }
    ty::Vector FakeRightKnee(void) {
        return ty::User::rightKnee();
    }
    ty::Vector FakeRightAnkle(void) {
        return ty::User::rightAnkle();
    }
    ty::Vector FakeRightFoot(void) {
        return ty::User::rightFoot();
    }
    ty::Vector FakeLeftHip(void) {
        return ty::User::leftHip();
    }
    ty::Vector FakeLeftKnee(void) {
        return ty::User::leftKnee();
    }
    ty::Vector FakeLeftAnkle(void) {
        return ty::User::leftAnkle();
    }
    ty::Vector FakeLeftFoot(void) {
        return ty::User::leftFoot();
    }
    ty::Vector FakeWaist(void) {
        return ty::User::waist();
    }
    bool FakeRightArmIsStraight(void) {
        return ty::User::rightArmIsStraight();
    }
    bool FakeLeftArmIsStraight(void) {
        return ty::User::leftArmIsStraight();
    }
    bool FakeRightArmIsBentRightAngle(void) {
        return ty::User::rightArmIsBentRightAngle();
    }
    bool FakeLeftArmIsBentRightAngle(void) {
        return ty::User::leftArmIsBentRightAngle();
    }
    bool FakeIsTracking(void) {
        return ty::User::isTracking();
    }
    bool FakeIsCalibrated(void) {
        return ty::User::isCalibrated();
    }
};

#endif // _TYTHON_MOCK_USER_H
