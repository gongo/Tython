#include "User.h"
#include "util.h"

const float User::THRESHOLD_CONFIDENCE = 0.5;

User::User(UserContext *_context) : context(_context)
{
    userId = 1;
}

User::~User(void)
{
}

void User::updatePixels(xn::SceneMetaData* data)
{
    context->updatePixels(userId, data);
}

bool User::isTracking(void)
{
    return context->isTracking(userId);
}

bool User::isCalibrated(void)
{
    return context->isCalibrated(userId);
}

Vector User::getSkeletonPosition(XnSkeletonJoint j)
{
    XnSkeletonJointPosition p = context->getSkeletonJointPosition(userId, j);

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

inline bool User::isConfident(XnSkeletonJointPosition p) const
{
    return p.fConfidence >= THRESHOLD_CONFIDENCE;
}

Vector User::positionHead(void)
{
    return getSkeletonPosition(XN_SKEL_HEAD);
}

Vector User::positionNeck(void)
{
    return getSkeletonPosition(XN_SKEL_NECK);
}

Vector User::positionRightShoulder(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_SHOULDER);
}

Vector User::positionRightHand(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_HAND);
}

Vector User::positionRightElbow(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_ELBOW);
}

Vector User::positionLeftShoulder(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_SHOULDER);
}

Vector User::positionLeftHand(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_HAND);
}

Vector User::positionLeftElbow(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_ELBOW);
}

Vector User::positionWaist(void)
{
    return getSkeletonPosition(XN_SKEL_WAIST);
}

Vector User::skeletonHead(void)
{
    return getSkeletonVector(XN_SKEL_NECK, XN_SKEL_HEAD);
}

Vector User::skeletonMedianLine(void)
{
    return getSkeletonVector(XN_SKEL_HEAD, XN_SKEL_WAIST);
}

Vector User::skeletonRightUpperArm(void)
{
    return getSkeletonVector(XN_SKEL_RIGHT_SHOULDER, XN_SKEL_RIGHT_ELBOW);
}

Vector User::skeletonRightForearm(void)
{
    return getSkeletonVector(XN_SKEL_RIGHT_ELBOW, XN_SKEL_RIGHT_HAND);
}

Vector User::skeletonLeftUpperArm(void)
{
    return getSkeletonVector(XN_SKEL_LEFT_SHOULDER, XN_SKEL_LEFT_ELBOW);
}

Vector User::skeletonLeftForearm(void)
{
    return getSkeletonVector(XN_SKEL_LEFT_ELBOW, XN_SKEL_LEFT_HAND);
}

bool User::rightArmIsStraight(void)
{
    Vector forearm = skeletonRightForearm();
    Vector upperArm = skeletonRightUpperArm();
    
    return forearm.isStraight(upperArm.reverse());
}

bool User::leftArmIsStraight(void)
{
    Vector forearm = skeletonLeftForearm();
    Vector upperArm = skeletonLeftUpperArm();

    return forearm.isStraight(upperArm.reverse());
}

bool User::rightArmIsBentRightAngle(void)
{
    Vector upperArm = skeletonRightUpperArm();
    Vector forearm  = skeletonRightForearm();

    return upperArm.isOrthogonal(forearm);
}

bool User::leftArmIsBentLeftAngle(void)
{
    Vector upperArm = skeletonLeftUpperArm();
    Vector forearm  = skeletonLeftForearm();

    return upperArm.isOrthogonal(forearm);
}
