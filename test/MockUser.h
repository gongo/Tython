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
        _fake = new User(NULL);
        ON_CALL(*this, isTracking()).WillByDefault(Return(true));
        ON_CALL(*this, isCalibrated()).WillByDefault(Return(true));
        ON_CALL(*this, isConfident(_)).WillByDefault(Return(true));
    }
    virtual ~MockUser(void) {}

    void setFakeSkeletonPosition(XnSkeletonJoint j, ty::Vector v) {
        skeletonPosition[j - 1].position = v;
    }

    MOCK_METHOD0(skeletonRightUpperArm, ty::Vector(void));
    MOCK_METHOD0(skeletonRightForearm, ty::Vector(void));
    MOCK_METHOD0(skeletonLeftUpperArm, ty::Vector(void));
    MOCK_METHOD0(skeletonLeftForearm, ty::Vector(void));
    MOCK_METHOD0(skeletonRightUpperThigh, ty::Vector(void));
    MOCK_METHOD0(skeletonRightLowerThigh, ty::Vector(void));
    MOCK_METHOD0(skeletonLeftUpperThigh, ty::Vector(void));
    MOCK_METHOD0(skeletonLeftLowerThigh, ty::Vector(void));
    MOCK_METHOD0(skeletonHead, ty::Vector(void));
    MOCK_METHOD0(positionHead, ty::Vector(void));
    MOCK_METHOD0(positionNeck, ty::Vector(void));
    MOCK_METHOD0(positionRightShoulder, ty::Vector(void));
    MOCK_METHOD0(positionRightElbow, ty::Vector(void));
    MOCK_METHOD0(positionRightHand, ty::Vector(void));
    MOCK_METHOD0(positionLeftShoulder, ty::Vector(void));
    MOCK_METHOD0(positionLeftElbow, ty::Vector(void));
    MOCK_METHOD0(positionLeftHand, ty::Vector(void));
    MOCK_METHOD0(positionRightHip, ty::Vector(void));
    MOCK_METHOD0(positionRightKnee, ty::Vector(void));
    MOCK_METHOD0(positionRightAnkle, ty::Vector(void));
    MOCK_METHOD0(positionRightFoot, ty::Vector(void));
    MOCK_METHOD0(positionLeftHip, ty::Vector(void));
    MOCK_METHOD0(positionLeftKnee, ty::Vector(void));
    MOCK_METHOD0(positionLeftAnkle, ty::Vector(void));
    MOCK_METHOD0(positionLeftFoot, ty::Vector(void));
    MOCK_METHOD0(positionWaist, ty::Vector(void));
    MOCK_METHOD0(rightArmIsStraight, bool(void));
    MOCK_METHOD0(leftArmIsStraight, bool(void));
    MOCK_METHOD0(rightArmIsBentRightAngle, bool(void));
    MOCK_METHOD0(leftArmIsBentRightAngle, bool(void));
    MOCK_METHOD0(isTracking, bool(void));
    MOCK_METHOD0(isCalibrated, bool(void));
    MOCK_CONST_METHOD1(isConfident, bool(XnSkeletonJointPosition p));

    ty::Vector FakeSkeletonRightUpperArm(void) {
        return ty::User::skeletonRightUpperArm();
    }
    ty::Vector FakeSkeletonRightForearm(void) {
        return ty::User::skeletonRightForearm();
    }
    ty::Vector FakeSkeletonLeftUpperArm(void) {
        return ty::User::skeletonLeftUpperArm();
    }
    ty::Vector FakeSkeletonLeftForearm(void) {
        return ty::User::skeletonLeftForearm();
    }
    ty::Vector FakeSkeletonRightUpperThigh(void) {
        return ty::User::skeletonRightUpperThigh();
    }
    ty::Vector FakeSkeletonRightLowerThigh(void) {
        return ty::User::skeletonRightLowerThigh();
    }
    ty::Vector FakeSkeletonLeftUpperThigh(void) {
        return ty::User::skeletonLeftUpperThigh();
    }
    ty::Vector FakeSkeletonLeftLowerThigh(void) {
        return ty::User::skeletonLeftLowerThigh();
    }
    ty::Vector FakeSkeletonHead(void) {
        return ty::User::skeletonHead();
    }
    ty::Vector FakePositionHead(void) {
        return ty::User::positionHead();
    }
    ty::Vector FakePositionNeck(void) {
        return ty::User::positionNeck();
    }
    ty::Vector FakePositionRightShoulder(void) {
        return ty::User::positionRightShoulder();
    }
    ty::Vector FakePositionRightElbow(void) {
        return ty::User::positionRightElbow();
    }
    ty::Vector FakePositionRightHand(void) {
        return ty::User::positionLeftHand();
    }
    ty::Vector FakePositionLeftShoulder(void) {
        return ty::User::positionLeftShoulder();
    }
    ty::Vector FakePositionLeftElbow(void) {
        return ty::User::positionLeftElbow();
    }
    ty::Vector FakePositionLeftHand(void) {
        return ty::User::positionLeftHand();
    }
    ty::Vector FakePositionRightHip(void) {
        return ty::User::positionRightHip();
    }
    ty::Vector FakePositionRightKnee(void) {
        return ty::User::positionRightKnee();
    }
    ty::Vector FakePositionRightAnkle(void) {
        return ty::User::positionRightAnkle();
    }
    ty::Vector FakePositionRightFoot(void) {
        return ty::User::positionRightFoot();
    }
    ty::Vector FakePositionLeftHip(void) {
        return ty::User::positionLeftHip();
    }
    ty::Vector FakePositionLeftKnee(void) {
        return ty::User::positionLeftKnee();
    }
    ty::Vector FakePositionLeftAnkle(void) {
        return ty::User::positionLeftAnkle();
    }
    ty::Vector FakePositionLeftFoot(void) {
        return ty::User::positionLeftFoot();
    }
    ty::Vector FakePositionWaist(void) {
        return ty::User::positionWaist();
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
    
private:
    User *_fake;
};

#endif // _TYTHON_MOCK_USER_H
