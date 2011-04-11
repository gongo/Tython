// -*- C++ -*-

#ifndef _TYTHON_USER_H
#define _TYTHON_USER_H

#include <XnCppWrapper.h>
#include "Vector.h"

class User {
public: 
    User(xn::Context *ctx);
    ~User(void);

    static const float THRESHOLD_CONFIDENCE;

    XnUserID getTrackingId(void) const;
    Vector getSkeletonPosition(XnSkeletonJoint j);
    Vector getSkeletonVector(XnSkeletonJoint j1, XnSkeletonJoint j2);

    void onNewUser(XnUserID uid);
    void onPoseStart(XnUserID uid);
    void onCalibrationEnd(XnUserID uid, bool isCalibration);

private:
    /**
     *
     */
    bool isConfident(XnSkeletonJointPosition p) const;
    
    /**
     *
     */
    xn::UserGenerator* userGenerator;

    /**
     * @see XnSkeletonJoint
     */
    XnSkeletonJointPosition skeletonPosition[24];

    /**
     *
     */
    XnChar poseName[20];

    XnCallbackHandle handleUserCallbacks;
    XnCallbackHandle handleCalibrationCallbacks;
    XnCallbackHandle handlePoseCallbacks;
};

#endif // _TYTHON_USER_H
