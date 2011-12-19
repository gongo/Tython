// -*- C++ -*-

#ifndef _TYTHON_USER_CONTEXT_H
#define _TYTHON_USER_CONTEXT_H

#include <XnCppWrapper.h>
#include "Vector.h"

namespace ty {

class UserContext {
public:
    UserContext(xn::Context& ctx, XnBool needPoseFlag = false);
    ~UserContext(void);

    /**
     * 指定したユーザの SceneMetaData を取得する
     *
     * @param  userId  ユーザID
     * @param  data    取得したデータを格納する
     */
    void setSceneData(int userId, xn::SceneMetaData* data);

    /**
     * 指定したユーザがトラッキングされているかチェックする
     *
     * @param   userId  ユーザID
     * @return  トラッキングされていれば true
     */
    bool isTracking(int userId);

    /**
     * 指定したユーザがキャリブレーションされているかチェックする
     *
     * @param   userId  ユーザID
     * @return  キャリブレーションされていれば true
     */
    bool isCalibrated(int userId);

    /**
     * 指定したユーザが認識されているかチェックする
     *
     * @param   userId  ユーザID
     * @return  認識されていれば true
     */
    bool isAvailable(int userId);

    XnSkeletonJointPosition getSkeletonJointPosition(int userId, XnSkeletonJoint joint);

    /**
     * @brief ユーザを検出したときにコールバックされる関数
     *
     * generator.RegisterUserCallbacks() に登録するため
     * static として宣言している。
     * ty::UserContext::onNewUser へのつなぎ役
     *
     * @see ty::onNewUser
     */
    static void XN_CALLBACK_TYPE onNewUserCallback(xn::UserGenerator& generator,
                                                   XnUserID uid,
                                                   void* t) {
        static_cast<UserContext*>(t)->onNewUser(uid);
    }

    /**
     * @brief ユーザを見失ったときにコールバックされる関数
     *
     * generator.RegisterUserCallbacks() に登録するため
     * static として宣言している。
     * ty::UserContext::onLostUser へのつなぎ役
     *
     * @see ty::onListUser
     */
    static void XN_CALLBACK_TYPE onLostUserCallback(xn::UserGenerator& generator,
                                                    XnUserID uid,
                                                    void* t) {
        static_cast<UserContext*>(t)->onLostUser(uid);
    }

    /**
     * @brief 検出されたユーザがポーズを取り始めたときにコールバックされる関数
     *
     * generator.RegisterUserCallbacks() に登録するため
     * static として宣言している。
     * ty::UserContext::onPoseStart へのつなぎ役
     *
     * @see ty::onPoseStart
     */
    static void XN_CALLBACK_TYPE onPoseStartCallback(xn::PoseDetectionCapability& capability,
                                                     const XnChar* strPose,
                                                     XnUserID uid,
                                                     void* t) {
        static_cast<UserContext*>(t)->onPoseStart(uid);
    }

    /**
     * @brief ポーズをとっているユーザのキャリブレーションが開始された時にコールバックされる関数
     *
     * generator.GetSkeletonCap().RegisterCalibrationCallbacks() に登録するため
     * static として宣言している。
     * ty::UserContext::onCalibrationStart へのつなぎ役
     *
     * @see ty::onPoseStart
     */
    static void XN_CALLBACK_TYPE onCalibrationStartCallback(xn::SkeletonCapability& capability,
                                                            XnUserID uid,
                                                            void* t) {
        static_cast<UserContext*>(t)->onCalibrationStart(uid);
    }

    /**
     * @brief ポーズをとっているユーザのキャリブレーションが終了した時にコールバックされる関数
     *
     * generator.GetSkeletonCap().RegisterCalibrationCallbacks() に登録するため
     * static として宣言している。
     * ty::UserContext::onCalibrationEnd へのつなぎ役
     *
     * @see ty::onPoseStart
     */
    static void XN_CALLBACK_TYPE onCalibrationEndCallback(xn::SkeletonCapability& capability,
                                                          XnUserID uid,
                                                          XnCalibrationStatus status,
                                                          void* t) {
        static_cast<UserContext*>(t)->onCalibrationEnd(uid, (status == XN_CALIBRATION_STATUS_OK));
    }

    /**
     * @brief キャリブレーションにポーズを必要とするか否か
     */
    XnBool isNeedPoseForCalibration;

protected:
    /**
     * デフォルトコンストラクタ
     *
     * 1. 継承するクラスのみ呼び出し可能
     * 2. 主に MockUser 用
     *
     * @see MockUser
     */
    UserContext(void);

    virtual void onNewUser(XnUserID uid);
    virtual void onLostUser(XnUserID uid);
    virtual void onPoseStart(XnUserID uid);
    virtual void onCalibrationStart(XnUserID uid);
    virtual void onCalibrationEnd(XnUserID uid, bool isCalibration);

private:
    /**
     * User ノードを作成する
     *
     * @param  ctx Context
     * @return ノード作成に成功したら true
     */
    XnStatus createNode(xn::Context& ctx);

    /**
     * ユーザの出現及び消失検知時のコールバックを設定
     *
     * @return  コールバック設定に成功したら true
     */
    XnStatus cbUserDetect(void);

    /**
     * ユーザのキャリブレーションポーズ検知時のコールバックを設定
     *
     * @return  コールバック設定に成功したら true
     */
    XnStatus cbPoseDetect(void);

    /**
     * ユーザのキャリブレーション開始時のコールバックを設定
     *
     * @return  コールバック設定に成功したら true
     */
    XnStatus cbCalibrationStart(void);

    /**
     * ユーザのキャリブレーション終了時のコールバックを設定
     *
     * @return  コールバック設定に成功したら true
     */
    XnStatus cbCalibrationComplete(void);

    /**
     * UserGenerator の SkeletonCapability を返す
     *
     * @return SkeletonCapability
     */
    xn::SkeletonCapability skeletonCap(void);

    /**
     * UserGenerator の PoseDetectionCapability を返す
     *
     * @return PoseDetectionCapability
     */
    xn::PoseDetectionCapability poseDetectionCap(void);

    /**
     * UserGenerator インスタンス
     */
    xn::UserGenerator generator;

    /**
     *
     */
    XnChar poseName[20];

    XnCallbackHandle handleUserCallbacks;
    XnCallbackHandle handleCalibrationCallbacks;
    XnCallbackHandle handlePoseCallbacks;
};

} // namespace ty

#endif // _TYTHON_USER_CONTEXT_H
