// -*- C++ -*-

#ifndef _TYTHON_USER_H
#define _TYTHON_USER_H

#include "UserContext.h"

class User {
public: 
    User(UserContext *_context);
    ~User(void);

    static const float THRESHOLD_CONFIDENCE;

    virtual Vector getSkeletonPosition(XnSkeletonJoint j);

    void updatePixels(xn::SceneMetaData* data);
    virtual bool isTracking(void);
    virtual bool isCalibrated(void);

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
     * 胴の座標を取得する
     *
     * @return 胴の座標(ベクトル)
     */
    virtual Vector positionTorso(void);

    /**
     * 腰の座標を取得する
     *
     * @return 腰の座標(ベクトル)
     */
    virtual Vector positionWaist(void);

    /**
     * 左鎖骨の座標を取得する
     *
     * @return 左鎖骨の座標(ベクトル)
     */
    virtual Vector positionLeftCollar(void);

    /**
     * 左肩の座標を取得する
     *
     * @return 左肩の座標(ベクトル)
     */
    virtual Vector positionLeftShoulder(void);

    /**
     * 左肘の座標を取得する
     *
     * @return 左肘の座標(ベクトル)
     */
    virtual Vector positionLeftElbow(void);

    /**
     * 左手首の座標を取得する
     *
     * @return 左手首の座標(ベクトル)
     */
    virtual Vector positionLeftWrist(void);

    /**
     * 左手の座標を取得する
     *
     * @return 左手の座標(ベクトル)
     */
    virtual Vector positionLeftHand(void);

    /**
     * 左手先の座標を取得する
     *
     * @return 左手先の座標(ベクトル)
     */
    virtual Vector positionLeftFingertip(void);

    /**
     * 右鎖骨の座標を取得する
     *
     * @return 右鎖骨の座標(ベクトル)
     */
    virtual Vector positionRightCollar(void);

    /**
     * 右肩の座標を取得する
     *
     * @return 右肩の座標(ベクトル)
     */
    virtual Vector positionRightShoulder(void);

    /**
     * 右肘の座標を取得する
     *
     * @return 右肘の座標(ベクトル)
     */
    virtual Vector positionRightElbow(void);

    /**
     * 右手首の座標を取得する
     *
     * @return 右手首の座標(ベクトル)
     */
    virtual Vector positionRightWrist(void);

    /**
     * 右手の座標を取得する
     *
     * @return 右手の座標(ベクトル)
     */
    virtual Vector positionRightHand(void);

    /**
     * 右手先の座標を取得する
     *
     * @return 右手先の座標(ベクトル)
     */
    virtual Vector positionRightFingertip(void);

    /**
     * 左尻の座標を取得する
     *
     * @return 左尻の座標(ベクトル)
     */
    virtual Vector positionLeftHip(void);

    /**
     * 左膝の座標を取得する
     *
     * @return 左膝の座標(ベクトル)
     */
    virtual Vector positionLeftKnee(void);

    /**
     * 左足首の座標を取得する
     *
     * @return 左足首の座標(ベクトル)
     */
    virtual Vector positionLeftAnkle(void);

    /**
     * 左足の座標を取得する
     *
     * @return 左足の座標(ベクトル)
     */
    virtual Vector positionLeftFoot(void);

    /**
     * 右尻の座標を取得する
     *
     * @return 右尻の座標(ベクトル)
     */
    virtual Vector positionRightHip(void);

    /**
     * 右膝の座標を取得する
     *
     * @return 右膝の座標(ベクトル)
     */
    virtual Vector positionRightKnee(void);

    /**
     * 右足首の座標を取得する
     *
     * @return 右足首の座標(ベクトル)
     */
    virtual Vector positionRightAnkle(void);

    /**
     * 右足の座標を取得する
     *
     * @return 右足の座標(ベクトル)
     */
    virtual Vector positionRightFoot(void);

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

    /**
     * 左上腿(左尻から左膝にかけて)のベクトルを取得する
     *
     * @return 左上腿のベクトル
     */
    virtual Vector skeletonLeftUpperThigh(void);

    /**
     * 左下腿(左膝から左足首にかけて)のベクトルを取得する
     *
     * @return 左下腿のベクトル
     */
    virtual Vector skeletonLeftLowerThigh(void);

    /**
     * 右上腿(右尻から右膝にかけて)のベクトルを取得する
     *
     * @return 右上腿のベクトル
     */
    virtual Vector skeletonRightUpperThigh(void);

    /**
     * 右下腿(右膝から右足首にかけて)のベクトルを取得する
     *
     * @return 右下腿のベクトル
     */
    virtual Vector skeletonRightLowerThigh(void);

    /**
     * 右腕がまっすぐ伸びているかどうか
     *
     * @see skeletonRightForearm()
     * @see skeletonRightUpperArm()
     *
     * @return 右腕がまっすぐ伸びていれば true
     */
    virtual bool rightArmIsStraight(void);

    /**
     * 左腕がまっすぐ伸びているかどうか
     *
     * @see skeletonLeftForearm()
     * @see skeletonLeftUpperArm()
     *
     * return 左腕がまっすぐ伸びていれば true
     */
    virtual bool leftArmIsStraight(void);

    /**
     * 右腕が直角に曲がっているか
     *
     * @see skeletonRightForearm()
     * @see skeletonRightUpperArm()
     *
     * @return 右腕が直角に曲がっていれば true
     */
    virtual bool rightArmIsBentRightAngle(void);

    /**
     * 左腕が直角に曲がっているか
     *
     * @see skeletonLeftForearm()
     * @see skeletonLeftUpperArm()
     *
     * @return 左腕が直角に曲がっていれば true
     */
    virtual bool leftArmIsBentLeftAngle(void);
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
