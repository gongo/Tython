// -*- C++ -*-

#ifndef _TYTHON_MOCK_USER_H
#define _TYTHON_MOCK_USER_H

#include <gmock/gmock.h>
#include "User.h"

class MockUser : public User {
public:
    MockUser(void) : User(NULL) {}
    virtual ~MockUser(void) {}

    /**
     * トラッキングされているか
     *
     * スタブのため、常時 true を返す
     *
     * @return true
     */
    bool isTracking(void) {
        return true;
    }

    /**
     * キャリブレーションされているか
     *
     * スタブのため、常時 true を返す
     *
     * @return true
     */
    bool isCalibrated(void) {
        return true;
    }

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
};

#endif // _TYTHON_MOCK_USER_H
