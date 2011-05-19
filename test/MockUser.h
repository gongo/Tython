// -*- C++ -*-

#ifndef _TYTHON_MOCK_USER_H
#define _TYTHON_MOCK_USER_H

#include <gmock/gmock.h>
#include "User.h"

using ::testing::Return;

class MockUser : public User {
public:
    MockUser(void) : User(NULL) {
        ON_CALL(*this, isTracking()).WillByDefault(Return(true));
        ON_CALL(*this, isCalibrated()).WillByDefault(Return(true));
    }
    virtual ~MockUser(void) {}

    MOCK_METHOD0(skeletonRightUpperArm, Vector(void));
    MOCK_METHOD0(skeletonRightForearm, Vector(void));
    MOCK_METHOD0(skeletonRightHand, Vector(void));
    MOCK_METHOD0(skeletonLeftUpperArm, Vector(void));
    MOCK_METHOD0(skeletonLeftForearm, Vector(void));
    MOCK_METHOD0(skeletonLeftHand, Vector(void));
    MOCK_METHOD0(skeletonHead, Vector(void));
    MOCK_METHOD0(positionHead, Vector(void));
    MOCK_METHOD0(positionNeck, Vector(void));
    MOCK_METHOD0(positionRightShoulder, Vector(void));
    MOCK_METHOD0(positionRightElbow, Vector(void));
    MOCK_METHOD0(positionRightHand, Vector(void));
    MOCK_METHOD0(positionLeftShoulder, Vector(void));
    MOCK_METHOD0(positionLeftElbow, Vector(void));
    MOCK_METHOD0(positionLeftHand, Vector(void));
    MOCK_METHOD0(positionWaist, Vector(void));
    MOCK_METHOD0(rightArmIsStraight, bool(void));
    MOCK_METHOD0(leftArmIsStraight, bool(void));
    MOCK_METHOD0(rightArmIsBentRightAngle, bool(void));
    MOCK_METHOD0(leftArmIsBentLeftAngle, bool(void));
    MOCK_METHOD0(isTracking, bool(void));
    MOCK_METHOD0(isCalibrated, bool(void));
};

#endif // _TYTHON_MOCK_USER_H
