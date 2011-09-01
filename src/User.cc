#include "User.h"
#include "util.h"

const float User::THRESHOLD_CONFIDENCE = 0.5;

User::User(UserContext *_context) : context(_context), userId(1)
{
}

User::User(UserContext *_context, int id) : context(_context), userId(id)
{
}

int User::id(void)
{
    return userId;
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

inline Vector User::positionHead(void)
{
    return getSkeletonPosition(XN_SKEL_HEAD);
}

inline Vector User::positionNeck(void)
{
    return getSkeletonPosition(XN_SKEL_NECK);
}

inline Vector User::positionTorso(void)
{
    return getSkeletonPosition(XN_SKEL_TORSO);
}

inline Vector User::positionWaist(void)
{
    return getSkeletonPosition(XN_SKEL_WAIST);
}

inline Vector User::positionLeftCollar(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_COLLAR);
}

inline Vector User::positionLeftShoulder(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_SHOULDER);
}

inline Vector User::positionLeftElbow(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_ELBOW);
}

inline Vector User::positionLeftWrist(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_WRIST);
}

inline Vector User::positionLeftHand(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_HAND);
}

inline Vector User::positionLeftFingertip(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_FINGERTIP);
}

inline Vector User::positionRightCollar(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_COLLAR);
}

inline Vector User::positionRightShoulder(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_SHOULDER);
}

inline Vector User::positionRightElbow(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_ELBOW);
}

inline Vector User::positionRightWrist(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_WRIST);
}

inline Vector User::positionRightHand(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_HAND);
}

inline Vector User::positionRightFingertip(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_FINGERTIP);
}

inline Vector User::positionLeftHip(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_HIP);
}

inline Vector User::positionLeftKnee(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_KNEE);
}

inline Vector User::positionLeftAnkle(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_ANKLE);
}

inline Vector User::positionLeftFoot(void)
{
    return getSkeletonPosition(XN_SKEL_LEFT_FOOT);
}

inline Vector User::positionRightHip(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_HIP);
}

inline Vector User::positionRightKnee(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_KNEE);
}

inline Vector User::positionRightAnkle(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_ANKLE);
}

inline Vector User::positionRightFoot(void)
{
    return getSkeletonPosition(XN_SKEL_RIGHT_FOOT);
}

inline Vector User::skeletonHead(void)
{
    return positionHead() - positionNeck();
}

inline Vector User::skeletonMedianLine(void)
{
    return positionWaist() - positionHead();
}

inline Vector User::skeletonRightUpperArm(void)
{
    return positionRightElbow() - positionRightShoulder();
}

inline Vector User::skeletonRightForearm(void)
{
    return positionRightHand() - positionRightElbow();
}

inline Vector User::skeletonLeftUpperArm(void)
{
    return positionLeftElbow() - positionLeftShoulder();
}

inline Vector User::skeletonLeftForearm(void)
{
    return positionLeftHand() - positionLeftElbow();
}

inline Vector User::skeletonLeftUpperThigh(void)
{
    return positionLeftKnee() - positionLeftHip();
}

inline Vector User::skeletonLeftLowerThigh(void)
{
    return positionLeftAnkle() - positionLeftKnee();
}

inline Vector User::skeletonRightUpperThigh(void)
{
    return positionRightKnee() - positionRightHip();
}

inline Vector User::skeletonRightLowerThigh(void)
{
    return positionRightAnkle() - positionRightKnee();
}

inline bool User::rightArmIsStraight(void)
{
    Vector forearm = skeletonRightForearm();
    Vector upperArm = skeletonRightUpperArm();
    
    return forearm.isStraight(upperArm.reverse());
}

inline bool User::leftArmIsStraight(void)
{
    Vector forearm = skeletonLeftForearm();
    Vector upperArm = skeletonLeftUpperArm();

    return forearm.isStraight(upperArm.reverse());
}

inline bool User::rightArmIsBentRightAngle(void)
{
    Vector upperArm = skeletonRightUpperArm();
    Vector forearm  = skeletonRightForearm();

    return upperArm.isOrthogonal(forearm);
}


inline bool User::leftArmIsBentRightAngle(void)
{
    Vector upperArm = skeletonLeftUpperArm();
    Vector forearm  = skeletonLeftForearm();

    return upperArm.isOrthogonal(forearm);
}
