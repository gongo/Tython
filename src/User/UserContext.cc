#include "UserContext.h"
#include "util.h"

namespace ty {

UserContext::UserContext(xn::Context *ctx)
{
    XnStatus rc;

    userGenerator = new xn::UserGenerator;
    
    rc = ctx->FindExistingNode(XN_NODE_TYPE_USER, *userGenerator);
    if (!ty::xnCheck(rc)) {
        ty::xnRuntimeCheck(userGenerator->Create(*ctx));
    }
    userGenerator->GetSkeletonCap().SetSkeletonProfile(XN_SKEL_PROFILE_ALL);

    DIE_IF(!userGenerator->IsCapabilitySupported(XN_CAPABILITY_SKELETON), "This configuration is not supported.");

    userGenerator->GetSkeletonCap().GetCalibrationPose(poseName);
    ty::xnRuntimeCheck(userGenerator->RegisterUserCallbacks(UserContext::onNewUserCallback,
                                                            UserContext::onLostUserCallback,
                                                            this,
                                                            handleUserCallbacks));
    ty::xnRuntimeCheck(userGenerator->GetPoseDetectionCap().RegisterToPoseCallbacks(UserContext::onPoseStartCallback,
                                                                                    NULL,
                                                                                    this,
                                                                                    handlePoseCallbacks));
    userGenerator->GetSkeletonCap().RegisterCalibrationCallbacks(UserContext::onCalibrationStartCallback,
                                                                 UserContext::onCalibrationEndCallback,
                                                                 this,
                                                                 handleCalibrationCallbacks);
}

UserContext::~UserContext(void)
{
    delete userGenerator;
}

void UserContext::setSceneData(int userId, xn::SceneMetaData* data)
{
    userGenerator->GetUserPixels(userId, *data);
}

bool UserContext::isTracking(int userId)
{
    return userGenerator->IsValid()
        && userGenerator->GetSkeletonCap().IsTracking(userId);
}

bool UserContext::isCalibrated(int userId)
{
    return userGenerator->IsValid()
        && userGenerator->GetSkeletonCap().IsCalibrated(userId);
}

XnSkeletonJointPosition UserContext::getSkeletonJointPosition(int userId, XnSkeletonJoint joint)
{
    XnSkeletonJointPosition p;
    userGenerator->GetSkeletonCap().GetSkeletonJointPosition(userId, joint, p);
    return p;
}

void UserContext::onNewUser(XnUserID uid)
{
    printf("onNewUser[%02d]\n", uid);
    ty::xnRuntimeCheck(userGenerator->GetPoseDetectionCap().StartPoseDetection(poseName, uid));
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
        ty::xnRuntimeCheck(userGenerator->GetSkeletonCap().StartTracking(uid));
    } else {
        printf("onCalibrationEnd - user[%02d] Failure...\n", uid);
        ty::xnRuntimeCheck(userGenerator->GetPoseDetectionCap().StartPoseDetection(poseName, uid));
    }
}

void UserContext::onPoseStart(XnUserID uid)
{
    printf("onPoseStart user[%02d]\n", uid);
    ty::xnRuntimeCheck(userGenerator->GetPoseDetectionCap().StopPoseDetection(uid));
    ty::xnRuntimeCheck(userGenerator->GetSkeletonCap().RequestCalibration(uid, true));
}

} // namespace ty
