// -*- C++ -*-

#ifndef _TYTHON_USER_CONTEXT_H
#define _TYTHON_USER_CONTEXT_H

#include <XnCppWrapper.h>
#include "Vector.h"

namespace ty {

class UserContext {
public: 
    UserContext(xn::Context *ctx);
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

    XnSkeletonJointPosition getSkeletonJointPosition(int userId, XnSkeletonJoint joint);

    void onNewUser(XnUserID uid);
    void onPoseStart(XnUserID uid);
    void onCalibrationStart(XnUserID uid);
    void onCalibrationEnd(XnUserID uid, bool isCalibration);

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

private:
    /**
     *
     */
    xn::UserGenerator* userGenerator;

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
