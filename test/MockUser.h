// -*- C++ -*-

#ifndef _TYTHON_MOCK_USER_H
#define _TYTHON_MOCK_USER_H

#include <gmock/gmock.h>
#include "User.h"

class MockUser : public User {
public:
    MockUser(void) : User() {}
    virtual ~MockUser(void) {}

    /**
     * トラッキングされたユーザの ID を返す
     *
     * @return スタブのため 1 を返す
     */
    XnUserID getTrackingId(void) const {
        return 1;
    }

    MOCK_METHOD0(skeletonRightUpperArm, Vector(void));
    MOCK_METHOD0(skeletonRightForearm, Vector(void));
    MOCK_METHOD0(skeletonRightHand, Vector(void));
    MOCK_METHOD0(skeletonLeftUpperArm, Vector(void));
    MOCK_METHOD0(skeletonLeftForearm, Vector(void));
    MOCK_METHOD0(skeletonLeftHand, Vector(void));
    MOCK_METHOD0(positionNeck, Vector(void));
    MOCK_METHOD0(positionRightShoulder, Vector(void));
    MOCK_METHOD0(positionRightElbow, Vector(void));
    MOCK_METHOD0(positionRightHand, Vector(void));
    MOCK_METHOD0(positionLeftShoulder, Vector(void));
    MOCK_METHOD0(positionLeftElbow, Vector(void));
    MOCK_METHOD0(positionLeftHand, Vector(void));
    MOCK_METHOD0(positionWaist, Vector(void));
};

#endif // _TYTHON_MOCK_USER_H
