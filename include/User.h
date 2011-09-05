// -*- C++ -*-

#ifndef _TYTHON_USER_H
#define _TYTHON_USER_H

#include "UserContext.h"

namespace ty {

class User {
public:
    /**
     * コンストラクタ
     *
     * ユーザID が 1 の User を生成
     */
    User(UserContext *_context);

    /**
     * コンストラクタ
     *
     * ユーザID が id の User を生成
     */
    User(UserContext *_context, int id);

    /**
     * デストラクタ
     */
    ~User(void) {}

    /**
     *
     */
    virtual ty::Vector getSkeletonPosition(XnSkeletonJoint j);

    void updatePixels(xn::SceneMetaData* data);

    /**
     * ユーザがトラッキングされているかチェックする
     *
     * @see userId
     *
     * @return トラッキングされていれば true
     */
    virtual bool isTracking(void);

    /**
     * ユーザがキャリブレーションされているかチェックする
     *
     * @see userId
     *
     * @return キャリブレーションされていれば true
     */
    virtual bool isCalibrated(void);

    /**
     * ユーザの ID を返す
     *
     * @see userId
     * 
     * @return ユーザ ID
     */
    int id(void);

    /**
     * 頭の座標を取得する
     *
     * @return 頭の座標(ベクトル)
     */
    virtual ty::Vector positionHead(void);

    /**
     * 首の座標を取得する
     *
     * @return 首の座標(ベクトル)
     */
    virtual ty::Vector positionNeck(void);

    /**
     * 胴の座標を取得する
     *
     * @return 胴の座標(ベクトル)
     */
    virtual ty::Vector positionTorso(void);

    /**
     * 腰の座標を取得する
     *
     * @return 腰の座標(ベクトル)
     */
    virtual ty::Vector positionWaist(void);

    /**
     * 左鎖骨の座標を取得する
     *
     * @return 左鎖骨の座標(ベクトル)
     */
    virtual ty::Vector positionLeftCollar(void);

    /**
     * 左肩の座標を取得する
     *
     * @return 左肩の座標(ベクトル)
     */
    virtual ty::Vector positionLeftShoulder(void);

    /**
     * 左肘の座標を取得する
     *
     * @return 左肘の座標(ベクトル)
     */
    virtual ty::Vector positionLeftElbow(void);

    /**
     * 左手首の座標を取得する
     *
     * @return 左手首の座標(ベクトル)
     */
    virtual ty::Vector positionLeftWrist(void);

    /**
     * 左手の座標を取得する
     *
     * @return 左手の座標(ベクトル)
     */
    virtual ty::Vector positionLeftHand(void);

    /**
     * 左手先の座標を取得する
     *
     * @return 左手先の座標(ベクトル)
     */
    virtual ty::Vector positionLeftFingertip(void);

    /**
     * 右鎖骨の座標を取得する
     *
     * @return 右鎖骨の座標(ベクトル)
     */
    virtual ty::Vector positionRightCollar(void);

    /**
     * 右肩の座標を取得する
     *
     * @return 右肩の座標(ベクトル)
     */
    virtual ty::Vector positionRightShoulder(void);

    /**
     * 右肘の座標を取得する
     *
     * @return 右肘の座標(ベクトル)
     */
    virtual ty::Vector positionRightElbow(void);

    /**
     * 右手首の座標を取得する
     *
     * @return 右手首の座標(ベクトル)
     */
    virtual ty::Vector positionRightWrist(void);

    /**
     * 右手の座標を取得する
     *
     * @return 右手の座標(ベクトル)
     */
    virtual ty::Vector positionRightHand(void);

    /**
     * 右手先の座標を取得する
     *
     * @return 右手先の座標(ベクトル)
     */
    virtual ty::Vector positionRightFingertip(void);

    /**
     * 左尻の座標を取得する
     *
     * @return 左尻の座標(ベクトル)
     */
    virtual ty::Vector positionLeftHip(void);

    /**
     * 左膝の座標を取得する
     *
     * @return 左膝の座標(ベクトル)
     */
    virtual ty::Vector positionLeftKnee(void);

    /**
     * 左足首の座標を取得する
     *
     * @return 左足首の座標(ベクトル)
     */
    virtual ty::Vector positionLeftAnkle(void);

    /**
     * 左足の座標を取得する
     *
     * @return 左足の座標(ベクトル)
     */
    virtual ty::Vector positionLeftFoot(void);

    /**
     * 右尻の座標を取得する
     *
     * @return 右尻の座標(ベクトル)
     */
    virtual ty::Vector positionRightHip(void);

    /**
     * 右膝の座標を取得する
     *
     * @return 右膝の座標(ベクトル)
     */
    virtual ty::Vector positionRightKnee(void);

    /**
     * 右足首の座標を取得する
     *
     * @return 右足首の座標(ベクトル)
     */
    virtual ty::Vector positionRightAnkle(void);

    /**
     * 右足の座標を取得する
     *
     * @return 右足の座標(ベクトル)
     */
    virtual ty::Vector positionRightFoot(void);

    /**
     * 首から頭へのベクトルを取得する
     *
     * @return 首から頭へのベクトル
     */
    virtual ty::Vector skeletonHead(void);

    /**
     * 正中線(頭から腰にかけて)のベクトルを取得する
     *
     * @return 正中線のベクトル
     */
    virtual ty::Vector skeletonMedianLine(void);

    /**
     * 右上腕(右肩から右肘にかけて)のベクトルを取得する
     *
     * @return 右上腕のベクトル
     */
    virtual ty::Vector skeletonRightUpperArm(void);

    /**
     * 右前腕(右肘から右手にかけて)のベクトルを取得する
     *
     * @return 右前腕のベクトル
     */
    virtual ty::Vector skeletonRightForearm(void);

    /**
     * 左上腕(左肩から左肘にかけて)のベクトルを取得する
     *
     * @return 左上腕のベクトル
     */
    virtual ty::Vector skeletonLeftUpperArm(void);

    /**
     * 左前腕(左肘から左手にかけて)のベクトルを取得する
     *
     * @return 左前腕のベクトル
     */
    virtual ty::Vector skeletonLeftForearm(void);

    /**
     * 左上腿(左尻から左膝にかけて)のベクトルを取得する
     *
     * @return 左上腿のベクトル
     */
    virtual ty::Vector skeletonLeftUpperThigh(void);

    /**
     * 左下腿(左膝から左足首にかけて)のベクトルを取得する
     *
     * @return 左下腿のベクトル
     */
    virtual ty::Vector skeletonLeftLowerThigh(void);

    /**
     * 右上腿(右尻から右膝にかけて)のベクトルを取得する
     *
     * @return 右上腿のベクトル
     */
    virtual ty::Vector skeletonRightUpperThigh(void);

    /**
     * 右下腿(右膝から右足首にかけて)のベクトルを取得する
     *
     * @return 右下腿のベクトル
     */
    virtual ty::Vector skeletonRightLowerThigh(void);

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
    virtual bool leftArmIsBentRightAngle(void);

    /**
     * 認識のしきい値
     *
     * @see isConfident
     */
    static const float THRESHOLD_CONFIDENCE;

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

    /**
     * ユーザの骨格座標を持つ
     *
     * @see XnSkeletonJoint
     */
    XnSkeletonJointPosition skeletonPosition[24];

private:
    /**
     * 座標の認識度がしきい値を超えているかチェックする
     *
     * 超えていなければ、認識できていないと判断し、
     * skeletonPosition に保存された値を使うようにする
     *
     * @see skeletonPosition
     * @see getSkeletonPosition
     *
     * @param   p
     * @return    しきい値を超えていれば true
     */
    bool isConfident(XnSkeletonJointPosition p) const;
    
    /**
     * UserContext のインスタンス
     */
    UserContext* context;

    /**
     * ユーザ ID
     */
    const int userId;

    /**
     *
     */
    XnChar poseName[20];

    XnCallbackHandle handleUserCallbacks;
    XnCallbackHandle handleCalibrationCallbacks;
    XnCallbackHandle handlePoseCallbacks;
};

} // namespace ty

#endif // _TYTHON_USER_H
