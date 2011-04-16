#include "User.h"
#include "util.h"

const float User::THRESHOLD_CONFIDENCE = 0.5;

static void XN_CALLBACK_TYPE s_onNewUser(xn::UserGenerator& generator, XnUserID uid, void* t)
{
    static_cast<User*>(t)->onNewUser(uid);
}

static void XN_CALLBACK_TYPE s_onCalibrationEnd(xn::SkeletonCapability& capability, XnUserID uid, XnBool bSuccess, void* t)
{
    static_cast<User*>(t)->onCalibrationEnd(uid, bSuccess);
}

static void XN_CALLBACK_TYPE s_onPoseStart(xn::PoseDetectionCapability& capability, const XnChar* strPose, XnUserID uid, void* t)
{
    static_cast<User*>(t)->onPoseStart(uid);
}

User::User(xn::Context *ctx)
{
    userGenerator = new xn::UserGenerator;
    
    ctx->FindExistingNode(XN_NODE_TYPE_USER, *userGenerator);
    userGenerator->Create(*ctx);
    userGenerator->GetSkeletonCap().SetSkeletonProfile(XN_SKEL_PROFILE_ALL);

    DIE_IF(!userGenerator->IsCapabilitySupported(XN_CAPABILITY_SKELETON), "This configuration is not supported.");

    userGenerator->GetSkeletonCap().GetCalibrationPose(poseName);
    userGenerator->RegisterUserCallbacks(s_onNewUser, NULL, this, handleUserCallbacks);
    userGenerator->GetPoseDetectionCap().RegisterToPoseCallbacks(s_onPoseStart, NULL, this, handlePoseCallbacks);
    userGenerator->GetSkeletonCap().RegisterCalibrationCallbacks(NULL, s_onCalibrationEnd, this, handleCalibrationCallbacks);
}

User::User(void)
{
    userGenerator = NULL;
}

User::~User(void)
{
    if (userGenerator != NULL) {
        delete userGenerator;
    }
}

XnUserID User::getTrackingId(void) const
{
    XnUserID ids[1];
    XnUInt16 users = 1;
    userGenerator->GetUsers(ids, users);
    if (users == 0) {
        return 0;
    }

    if (userGenerator->GetSkeletonCap().IsTracking(1)) {
        return 1;
    }

    return 0;
}

Vector User::getSkeletonPosition(XnSkeletonJoint j)
{
    XnSkeletonJointPosition p;
    XnUserID id = getTrackingId();

    userGenerator->GetSkeletonCap().GetSkeletonJointPosition(id, j, p);

    if (isConfident(p)) {
        skeletonPosition[j - 1] = p;
    }

    return Vector(skeletonPosition[j - 1].position);
}

Vector User::getSkeletonVector(XnSkeletonJoint j1, XnSkeletonJoint j2)
{
    Vector v1 = getSkeletonPosition(j1);
    Vector v2 = getSkeletonPosition(j2);

    return v1 - v2;
}

void User::onNewUser(XnUserID uid)
{
    printf("onNewUser\n");
    userGenerator->GetPoseDetectionCap().StartPoseDetection(poseName, uid);
}

void User::onCalibrationEnd(XnUserID uid, bool isCalibration)
{
    printf("onCalibrationEnd\n");
    if (isCalibration) {
        userGenerator->GetSkeletonCap().StartTracking(uid);
    } else {
        userGenerator->GetPoseDetectionCap().StartPoseDetection(poseName, uid);
    }
}

void User::onPoseStart(XnUserID uid)
{
    printf("onPoseStart\n");
    userGenerator->GetPoseDetectionCap().StopPoseDetection(uid);
    userGenerator->GetSkeletonCap().RequestCalibration(uid, true);
}

inline bool User::isConfident(XnSkeletonJointPosition p) const
{
    return p.fConfidence >= THRESHOLD_CONFIDENCE;
}

Vector User::skeletonRightUpperArm(void)
{
    return getSkeletonVector(XN_SKEL_RIGHT_ELBOW, XN_SKEL_RIGHT_SHOULDER);
}

Vector User::skeletonRightForearm(void)
{
    return getSkeletonVector(XN_SKEL_RIGHT_WRIST, XN_SKEL_RIGHT_ELBOW);
}

Vector User::skeletonRightHand(void)
{
    return getSkeletonVector(XN_SKEL_RIGHT_HAND, XN_SKEL_RIGHT_WRIST);
}

Vector User::skeletonLeftUpperArm(void)
{
    return getSkeletonVector(XN_SKEL_LEFT_ELBOW, XN_SKEL_LEFT_SHOULDER);
}

Vector User::skeletonLeftForearm(void)
{
    return getSkeletonVector(XN_SKEL_LEFT_WRIST, XN_SKEL_LEFT_ELBOW);
}

Vector User::skeletonLeftHand(void)
{
    return getSkeletonVector(XN_SKEL_LEFT_HAND, XN_SKEL_LEFT_WRIST);
}
