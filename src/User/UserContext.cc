#include "UserContext.h"
#include "util.h"

namespace ty {

static void XN_CALLBACK_TYPE s_onNewUser(xn::UserGenerator& generator, XnUserID uid, void* t)
{
    static_cast<UserContext*>(t)->onNewUser(uid);
}

static void XN_CALLBACK_TYPE s_onCalibrationEnd(xn::SkeletonCapability& capability, XnUserID uid, XnBool bSuccess, void* t)
{
    static_cast<UserContext*>(t)->onCalibrationEnd(uid, bSuccess);
}

static void XN_CALLBACK_TYPE s_onCalibrationStart(xn::SkeletonCapability& capability, XnUserID uid, void* t)
{
    static_cast<UserContext*>(t)->onCalibrationStart(uid);
}

static void XN_CALLBACK_TYPE s_onPoseStart(xn::PoseDetectionCapability& capability, const XnChar* strPose, XnUserID uid, void* t)
{
    static_cast<UserContext*>(t)->onPoseStart(uid);
}

UserContext::UserContext(xn::Context *ctx)
{
    XnStatus rc;

    userGenerator = new xn::UserGenerator;
    
    rc = ctx->FindExistingNode(XN_NODE_TYPE_USER, *userGenerator);
    if (!XN_OK(rc)) {
        userGenerator->Create(*ctx);
    }
    userGenerator->GetSkeletonCap().SetSkeletonProfile(XN_SKEL_PROFILE_ALL);

    DIE_IF(!userGenerator->IsCapabilitySupported(XN_CAPABILITY_SKELETON), "This configuration is not supported.");

    userGenerator->GetSkeletonCap().GetCalibrationPose(poseName);
    userGenerator->RegisterUserCallbacks(s_onNewUser, NULL, this, handleUserCallbacks);
    userGenerator->GetPoseDetectionCap().RegisterToPoseCallbacks(s_onPoseStart, NULL, this, handlePoseCallbacks);
    userGenerator->GetSkeletonCap().RegisterCalibrationCallbacks(s_onCalibrationStart, s_onCalibrationEnd, this, handleCalibrationCallbacks);
}

UserContext::~UserContext(void)
{
    delete userGenerator;
}

void UserContext::updatePixels(int userId, xn::SceneMetaData* data)
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
    userGenerator->GetPoseDetectionCap().StartPoseDetection(poseName, uid);
}

void UserContext::onCalibrationStart(XnUserID uid)
{
    printf("onCalibrationStart user[%02d]\n", uid);
}

void UserContext::onCalibrationEnd(XnUserID uid, bool isCalibration)
{
    if (isCalibration) {
        printf("onCalibrationEnd - user[%02d] Success!\n", uid);
        userGenerator->GetSkeletonCap().StartTracking(uid);
    } else {
        printf("onCalibrationEnd - user[%02d] Failure...\n", uid);
        userGenerator->GetPoseDetectionCap().StartPoseDetection(poseName, uid);
    }
}

void UserContext::onPoseStart(XnUserID uid)
{
    printf("onPoseStart user[%02d]\n", uid);
    userGenerator->GetPoseDetectionCap().StopPoseDetection(uid);
    userGenerator->GetSkeletonCap().RequestCalibration(uid, true);
}

} // namespace ty
