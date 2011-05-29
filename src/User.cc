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

Vector User::positionTorso(void)
{
    return getSkeletonPosition(XN_SKEL_TORSO);
}

Vector User::positionWaist(void)
{
    return getSkeletonPosition(XN_SKEL_WAIST);
}

Vector User::positionLeftCollar(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_COLLAR);
}

Vector User::positionLeftShoulder(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_SHOULDER);
}

Vector User::positionLeftElbow(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_ELBOW);
}

Vector User::positionLeftWrist(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_WRIST);
}

Vector User::positionLeftHand(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_HAND);
}

Vector User::positionLeftFingertip(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_FINGERTIP);
}

Vector User::positionRightCollar(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_COLLAR);
}

Vector User::positionRightShoulder(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_SHOULDER);
}

Vector User::positionRightElbow(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_ELBOW);
}

Vector User::positionRightWrist(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_WRIST);
}

Vector User::positionRightHand(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_HAND);
}

Vector User::positionRightFingertip(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_FINGERTIP);
}

Vector User::positionLeftHip(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_HIP);
}

Vector User::positionLeftKnee(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_KNEE);
}

Vector User::positionLeftAnkle(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_ANKLE);
}

Vector User::positionLeftFoot(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_FOOT);
}


Vector User::positionRightHip(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_HIP);
}

Vector User::positionRightKnee(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_KNEE);
}

Vector User::positionRightAnkle(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_ANKLE);
}

Vector User::positionRightFoot(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_FOOT);
}

Vector User::skeletonHead(void)
{
    return positionNeck() - positionHead();
}

Vector User::skeletonMedianLine(void)
{
    return positionHead() - positionWaist();
}

Vector User::skeletonRightUpperArm(void)
{
    return positionRightShoulder() - positionRightElbow();
}

Vector User::skeletonRightForearm(void)
{
    return positionRightElbow() - positionRightHand();
}

Vector User::skeletonLeftUpperArm(void)
{
    return positionLeftShoulder() - positionLeftElbow();
}

Vector User::skeletonLeftForearm(void)
{
    return positionLeftElbow() - positionLeftHand();
}

Vector User::skeletonLeftUpperThigh(void)
{
    return positionLeftHip() - positionLeftKnee();
}

Vector User::skeletonLeftLowerThigh(void)
{
    return positionLeftKnee() - positionLeftAnkle();
}

Vector User::skeletonRightUpperThigh(void)
{
    return positionRightHip() - positionRightKnee();
}

Vector User::skeletonRightLowerThigh(void)
{
    return positionRightKnee() - positionRightAnkle();
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
