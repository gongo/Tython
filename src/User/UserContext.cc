#include "UserContext.h"
#include "util.h"

namespace ty {

UserContext::UserContext(xn::Context& ctx)
{
    XnStatus rc;

    if (!ty::xnCheck(ctx.FindExistingNode(XN_NODE_TYPE_USER, generator))) {
        ty::xnRuntimeCheck(generator.Create(ctx));
    }

    skeletonCap().SetSkeletonProfile(XN_SKEL_PROFILE_ALL);

    DIE_IF(!generator.IsCapabilitySupported(XN_CAPABILITY_SKELETON),
           "This configuration is not supported.");

    skeletonCap().GetCalibrationPose(poseName);
    ty::xnRuntimeCheck(generator.RegisterUserCallbacks(UserContext::onNewUserCallback,
                                                       UserContext::onLostUserCallback,
                                                       this,
                                                       handleUserCallbacks));

    ty::xnRuntimeCheck(poseDetectionCap().RegisterToPoseDetected(UserContext::onPoseStartCallback,
                                                                 this,
                                                                 handlePoseCallbacks));
    ty::xnRuntimeCheck(skeletonCap().RegisterToCalibrationStart(UserContext::onCalibrationStartCallback,
                                                                this,
                                                                handleCalibrationCallbacks));
    ty::xnRuntimeCheck(skeletonCap().RegisterToCalibrationComplete(UserContext::onCalibrationEndCallback,
                                                                   this,
                                                                   handleCalibrationCallbacks));
}

UserContext::~UserContext(void)
{
    generator.Release();
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
    ty::xnRuntimeCheck(poseDetectionCap().StartPoseDetection(poseName, uid));
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
    if (isCalibration) {
        printf("onCalibrationEnd - user[%02d] Success!\n", uid);
        ty::xnRuntimeCheck(skeletonCap().StartTracking(uid));
    } else {
        printf("onCalibrationEnd - user[%02d] Failure...\n", uid);
        ty::xnRuntimeCheck(poseDetectionCap().StartPoseDetection(poseName, uid));
    }
}

void UserContext::onPoseStart(XnUserID uid)
{
    printf("onPoseStart user[%02d]\n", uid);
    ty::xnRuntimeCheck(poseDetectionCap().StopPoseDetection(uid));
    ty::xnRuntimeCheck(skeletonCap().RequestCalibration(uid, true));
}

} // namespace ty
