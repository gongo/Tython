#include "UserContext.h"
#include "util.h"

namespace ty {

UserContext::UserContext(xn::Context& ctx, XnBool needPoseFlag)
{
    ty::throwRuntimeErrorIf({
        createNode(ctx),
        skeletonCap().SetSkeletonProfile(XN_SKEL_PROFILE_ALL),
        skeletonCap().GetCalibrationPose(poseName)
    });

    ty::throwRuntimeErrorIf({
            std::make_tuple(generator.IsCapabilitySupported(XN_CAPABILITY_SKELETON),
                            "This configuration is not supported.")
    });


    isNeedPoseForCalibration = (needPoseFlag || skeletonCap().NeedPoseForCalibration());
    if (isNeedPoseForCalibration) {
        printf("ポーズが必要です！！\n");
    }

    ty::throwRuntimeErrorIf({
        cbUserDetect(),
        cbPoseDetect(),
        cbCalibrationStart(),
        cbCalibrationComplete()
    });
}

UserContext::~UserContext(void)
{
    generator.Release();
}

XnStatus UserContext::createNode(xn::Context& ctx)
{
    XnStatus rc = XN_STATUS_OK;

    rc = ctx.FindExistingNode(XN_NODE_TYPE_USER, generator);

    if (!ty::isXnOK(rc)) {
        rc = generator.Create(ctx);
    }

    return rc;
}

XnStatus UserContext::cbUserDetect(void)
{
    return generator.RegisterUserCallbacks(
               UserContext::onNewUserCallback,
               UserContext::onLostUserCallback,
               this,
               handleUserCallbacks
           );
}

XnStatus UserContext::cbPoseDetect(void)
{
    return poseDetectionCap().RegisterToPoseDetected(
               UserContext::onPoseStartCallback,
               this,
               handlePoseCallbacks
           );
}

XnStatus UserContext::cbCalibrationStart(void)
{
    return skeletonCap().RegisterToCalibrationStart(
               UserContext::onCalibrationStartCallback,
               this,
               handleCalibrationCallbacks
           );
}

XnStatus UserContext::cbCalibrationComplete(void)
{
    return skeletonCap().RegisterToCalibrationComplete(
               UserContext::onCalibrationEndCallback,
               this,
               handleCalibrationCallbacks
           );
}

void UserContext::setSceneData(int userId, xn::SceneMetaData* data)
{
    generator.GetUserPixels(userId, *data);
}

bool UserContext::isTracking(int userId)
{
    return generator.IsValid()
        && skeletonCap().IsTracking(userId);
}

bool UserContext::isCalibrated(int userId)
{
    return generator.IsValid()
        && skeletonCap().IsCalibrated(userId);
}

/**
 * @todo マジックナンバーぇ...
 * @todo 標準で準備されてそうなもんだけど見つからない
 */
bool UserContext::isAvailable(int userId)
{
    XnUserID aUsers[15];
    XnUInt16 nUsers = 15;

    generator.GetUsers(aUsers, nUsers);

    for (int i = 0; i < nUsers; i++) {
        if (aUsers[i] == (XnUserID)userId) {
            return true;
        }
    }

    return false;
}

XnSkeletonJointPosition UserContext::getSkeletonJointPosition(int userId, XnSkeletonJoint joint)
{
    XnSkeletonJointPosition p;
    skeletonCap().GetSkeletonJointPosition(userId, joint, p);
    return p;
}

xn::SkeletonCapability UserContext::skeletonCap(void)
{
    return generator.GetSkeletonCap();
}

xn::PoseDetectionCapability UserContext::poseDetectionCap(void)
{
    return generator.GetPoseDetectionCap();
}

void UserContext::onNewUser(XnUserID uid)
{
    printf("onNewUser[%02d]\n", uid);

    if (isNeedPoseForCalibration) {
        ty::throwRuntimeErrorIf(poseDetectionCap().StartPoseDetection(poseName, uid));
    } else {
        ty::throwRuntimeErrorIf(skeletonCap().RequestCalibration(uid, TRUE));
    }
}

void UserContext::onLostUser(XnUserID uid)
{
    printf("onLostUser[%02d]\n", uid);
}

void UserContext::onCalibrationStart(XnUserID uid)
{
    printf("onCalibrationStart user[%02d]\n", uid);
}

void UserContext::onCalibrationEnd(XnUserID uid, bool isCalibration)
{
    XnStatus rc = XN_STATUS_OK;

    if (isCalibration) {
        printf("onCalibrationEnd - user[%02d] Success!\n", uid);
        rc = skeletonCap().StartTracking(uid);
    } else {
        printf("onCalibrationEnd - user[%02d] Failure...\n", uid);

        if (isNeedPoseForCalibration) {
            poseDetectionCap().StartPoseDetection(poseName, uid);
        } else {
            skeletonCap().RequestCalibration(uid, TRUE);
        }
    }

    ty::throwRuntimeErrorIf(rc);
}

void UserContext::onPoseStart(XnUserID uid)
{
    printf("onPoseStart user[%02d]\n", uid);

    ty::throwRuntimeErrorIf({
        poseDetectionCap().StopPoseDetection(uid),
        skeletonCap().RequestCalibration(uid, true)
    });
}

} // namespace ty
