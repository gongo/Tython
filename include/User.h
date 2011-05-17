// -*- C++ -*-

#ifndef _TYTHON_USER_H
#define _TYTHON_USER_H

#include "UserContext.h"

class User {
public: 
    User(UserContext *_context);
    ~User(void);

    static const float THRESHOLD_CONFIDENCE;

    Vector getSkeletonPosition(XnSkeletonJoint j);
    Vector getSkeletonVector(XnSkeletonJoint j1, XnSkeletonJoint j2);

    void updatePixels(xn::SceneMetaData* data);
    bool isTracking(void);
    bool isCalibrated(void);

    /**
     * 頭の座標を取得する
     *
     * @return 頭の座標(ベクトル)
     */
    virtual Vector positionHead(void);

    /**
     * 首の座標を取得する
     *
     * @return 首の座標(ベクトル)
     */
    virtual Vector positionNeck(void);

    /**
     * 右肩の座標を取得する
     *
     * @return 右肩の座標(ベクトル)
     */
    virtual Vector positionRightShoulder(void);

    /**
     * 右手の座標を取得する
     *
     * @return 右手の座標(ベクトル)
     */
    virtual Vector positionRightHand(void);

    /**
     * 右肘の座標を取得する
     *
     * @return 右肘の座標(ベクトル)
     */
    virtual Vector positionRightElbow(void);

    /**
     * 左肩の座標を取得する
     *
     * @return 左肩の座標(ベクトル)
     */
    virtual Vector positionLeftShoulder(void);

    /**
     * 左手の座標を取得する
     *
     * @return 左手の座標(ベクトル)
     */
    virtual Vector positionLeftHand(void);

    /**
     * 左肘の座標を取得する
     *
     * @return 左肘の座標(ベクトル)
     */
    virtual Vector positionLeftElbow(void);

    /**
     * 腰の座標を取得する
     *
     * @return 腰の座標(ベクトル)
     */
    virtual Vector positionWaist(void);

    /**
     * 首から頭へのベクトルを取得する
     *
     * @return 首から頭へのベクトル
     */
    virtual Vector skeletonHead(void);

    /**
     * 正中線(頭から腰にかけて)のベクトルを取得する
     *
     * @return 正中線のベクトル
     */
    virtual Vector skeletonMedianLine(void);

    /**
     * 右上腕(右肩から右肘にかけて)のベクトルを取得する
     *
     * @return 右上腕のベクトル
     */
    virtual Vector skeletonRightUpperArm(void);

    /**
     * 右前腕(右肘から右手にかけて)のベクトルを取得する
     *
     * @return 右前腕のベクトル
     */
    virtual Vector skeletonRightForearm(void);

    /**
     * 左上腕(左肩から左肘にかけて)のベクトルを取得する
     *
     * @return 左上腕のベクトル
     */
    virtual Vector skeletonLeftUpperArm(void);

    /**
     * 左前腕(左肘から左手にかけて)のベクトルを取得する
     *
     * @return 左前腕のベクトル
     */
    virtual Vector skeletonLeftForearm(void);

protected:
    /**
     * デフォルトコンストラクタ
     *
     * 1. 継承するクラスのみ呼び出し可能
     * 2. 主に MockUser 用
     *
     * @see MockUser
     */
    User(void);

private:
    /**
     *
     */
    bool isConfident(XnSkeletonJointPosition p) const;
    
    /**
     * 
     */
    int userId;

    /**
     *
     */
    UserContext* context;

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
