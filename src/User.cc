#include "User.h"

namespace ty {

const float User::THRESHOLD_CONFIDENCE = 0.5;

/**
 * @todo delegating constructor みたいにしたいよね...
 */
User::User(UserContext *_context) : context(_context), userId(1)
{
    sceneData = new xn::SceneMetaData;
}

User::User(UserContext *_context, int id) : context(_context), userId(id)
{
    sceneData = new xn::SceneMetaData;
}

User::~User(void)
{
    delete sceneData;
}

int User::id(void) const
{
    return userId;
}

xn::SceneMetaData* User::scene(void)
{
    context->setSceneData(userId, sceneData);
    return sceneData;
}

bool User::isTracking(void) const
{
    return context->isTracking(userId);
}

bool User::isCalibrated(void) const
{
    return context->isCalibrated(userId);
}

bool User::isAvailable(void) const
{
    return context->isAvailable(userId);
}

void User::updateSkeletonJointPosition(XnSkeletonJoint j)
{
    XnSkeletonJointPosition p = context->getSkeletonJointPosition(userId, j);

    if (isConfident(p)) {
        skeletonPosition[j - 1] = p;
    }    
}

Vector User::getSkeletonPosition(XnSkeletonJoint j)
{
    updateSkeletonJointPosition(j);
    return Vector(skeletonPosition[j - 1].position);
}

inline bool User::isConfident(XnSkeletonJointPosition p) const
{
    return p.fConfidence >= THRESHOLD_CONFIDENCE;
}

inline Vector User::head(void)
{
    return getSkeletonPosition(XN_SKEL_HEAD);
}

inline Vector User::neck(void)
{
    return getSkeletonPosition(XN_SKEL_NECK);
}

inline Vector User::torso(void)
{
    return getSkeletonPosition(XN_SKEL_TORSO);
}

inline Vector User::waist(void)
{
    return getSkeletonPosition(XN_SKEL_WAIST);
}

inline Vector User::leftCollar(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_COLLAR);
}

inline Vector User::leftShoulder(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_SHOULDER);
}

inline Vector User::leftElbow(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_ELBOW);
}

inline Vector User::leftWrist(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_WRIST);
}

inline Vector User::leftHand(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_HAND);
}

inline Vector User::leftFingertip(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_FINGERTIP);
}

inline Vector User::rightCollar(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_COLLAR);
}

inline Vector User::rightShoulder(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_SHOULDER);
}

inline Vector User::rightElbow(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_ELBOW);
}

inline Vector User::rightWrist(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_WRIST);
}

inline Vector User::rightHand(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_HAND);
}

inline Vector User::rightFingertip(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_FINGERTIP);
}

inline Vector User::leftHip(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_HIP);
}

inline Vector User::leftKnee(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_KNEE);
}

inline Vector User::leftAnkle(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_ANKLE);
}

inline Vector User::leftFoot(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_FOOT);
}

inline Vector User::rightHip(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_HIP);
}

inline Vector User::rightKnee(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_KNEE);
}

inline Vector User::rightAnkle(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_ANKLE);
}

inline Vector User::rightFoot(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_FOOT);
}

inline Vector User::vectorHead(void)
{
    return head() - neck();
}

inline Vector User::vectorMedianLine(void)
{
    return waist() - head();
}

inline Vector User::vectorRightUpperArm(void)
{
    return rightElbow() - rightShoulder();
}

inline Vector User::vectorRightForearm(void)
{
    return rightHand() - rightElbow();
}

inline Vector User::vectorLeftUpperArm(void)
{
    return leftElbow() - leftShoulder();
}

inline Vector User::vectorLeftForearm(void)
{
    return leftHand() - leftElbow();
}

inline Vector User::vectorLeftUpperThigh(void)
{
    return leftKnee() - leftHip();
}

inline Vector User::vectorLeftLowerThigh(void)
{
    return leftAnkle() - leftKnee();
}

inline Vector User::vectorRightUpperThigh(void)
{
    return rightKnee() - rightHip();
}

inline Vector User::vectorRightLowerThigh(void)
{
    return rightAnkle() - rightKnee();
}

inline Vector User::vectorUpperBodyForward(void)
{
    return (rightShoulder() - torso()).cross(leftShoulder() - torso()).reverse();
}

inline bool User::rightArmIsStraight(void)
{   
    return vectorRightForearm().isStraight(vectorRightUpperArm());
}

inline bool User::leftArmIsStraight(void)
{
    return vectorLeftForearm().isStraight(vectorLeftUpperArm());
}

inline bool User::rightArmIsBentRightAngle(void)
{
    return vectorRightUpperArm().isOrthogonal(vectorRightForearm());
}

inline bool User::leftArmIsBentRightAngle(void)
{
    return vectorLeftUpperArm().isOrthogonal(vectorLeftForearm());
}

} // namespace ty
