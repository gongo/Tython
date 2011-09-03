// -*- C++ -*-

#ifndef _TYTHON_MOCK_USER_H
#define _TYTHON_MOCK_USER_H

#include <gmock/gmock.h>
#include "User.h"

using ::testing::Return;

class MockUser : public ty::User {
public:
    MockUser(void) : User(NULL) {
        _fake = new User(NULL);
        ON_CALL(*this, isTracking()).WillByDefault(Return(true));
        ON_CALL(*this, isCalibrated()).WillByDefault(Return(true));
    }
    virtual ~MockUser(void) {}

    MOCK_METHOD0(skeletonRightUpperArm, ty::Vector(void));
    MOCK_METHOD0(skeletonRightForearm, ty::Vector(void));
    MOCK_METHOD0(skeletonLeftUpperArm, ty::Vector(void));
    MOCK_METHOD0(skeletonLeftForearm, ty::Vector(void));
    MOCK_METHOD0(skeletonHead, ty::Vector(void));
    MOCK_METHOD0(positionHead, ty::Vector(void));
    MOCK_METHOD0(positionNeck, ty::Vector(void));
    MOCK_METHOD0(positionRightShoulder, ty::Vector(void));
    MOCK_METHOD0(positionRightElbow, ty::Vector(void));
    MOCK_METHOD0(positionRightHand, ty::Vector(void));
    MOCK_METHOD0(positionLeftShoulder, ty::Vector(void));
    MOCK_METHOD0(positionLeftElbow, ty::Vector(void));
    MOCK_METHOD0(positionLeftHand, ty::Vector(void));
    MOCK_METHOD0(positionWaist, ty::Vector(void));
    MOCK_METHOD0(rightArmIsStraight, bool(void));
    MOCK_METHOD0(leftArmIsStraight, bool(void));
    MOCK_METHOD0(rightArmIsBentRightAngle, bool(void));
    MOCK_METHOD0(leftArmIsBentRightAngle, bool(void));
    MOCK_METHOD0(isTracking, bool(void));
    MOCK_METHOD0(isCalibrated, bool(void));

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
