// -*- C++ -*-

#ifndef _TYTHON_MOCK_USER_H
#define _TYTHON_MOCK_USER_H

#include <gmock/gmock.h>
#include "User.h"

using ::testing::Return;

class MockUser : public ty::User {
public:
    MockUser(void) : User(NULL) {
        ON_CALL(*this, isTracking()).WillByDefault(Return(true));
        ON_CALL(*this, isCalibrated()).WillByDefault(Return(true));
    }
    virtual ~MockUser(void) {}

    MOCK_METHOD0(skeletonRightUpperArm, ty::Vector(void));
    MOCK_METHOD0(skeletonRightForearm, ty::Vector(void));
    MOCK_METHOD0(skeletonRightHand, ty::Vector(void));
    MOCK_METHOD0(skeletonLeftUpperArm, ty::Vector(void));
    MOCK_METHOD0(skeletonLeftForearm, ty::Vector(void));
    MOCK_METHOD0(skeletonLeftHand, ty::Vector(void));
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
};

#endif // _TYTHON_MOCK_USER_H
