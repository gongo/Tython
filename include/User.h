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

    /**
     * 右上腕(右肩から右肘にかけて)のベクトルを取得する
     *
     * @return 右上腕のベクトル
     */
    Vector skeletonRightUpperArm(void);

    /**
     * 右前腕(右肘から右手首にかけて)のベクトルを取得する
     *
     * @return 右前腕のベクトル
     */
    Vector skeletonRightForearm(void);

    /**
     * 右手(右手首から右手にかけて)のベクトルを取得する
     *
     * @return 右手のベクトル
     */
    Vector skeletonRightHand(void);

    /**
     * 左上腕(左肩から左肘にかけて)のベクトルを取得する
     *
     * @return 左上腕のベクトル
     */
    Vector skeletonLeftUpperArm(void);

    /**
     * 左前腕(左肘から左手首にかけて)のベクトルを取得する
     *
     * @return 左前腕のベクトル
     */
    Vector skeletonLeftForearm(void);

    /**
     * 左手(左手首から左手にかけて)のベクトルを取得する
     *
     * @return 左手のベクトル
     */
    Vector skeletonLeftHand(void);

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
