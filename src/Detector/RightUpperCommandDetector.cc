#include "RightUpperCommandDetector.h"

RightUpperCommandDetector::RightUpperCommandDetector(User* _user) : CommandDetector(_user)
{
    setCommand(1, 4,
               &RightUpperCommandDetector::isStand,
               &RightUpperCommandDetector::isRightUpperBefore,
               &RightUpperCommandDetector::isRightUpperAfter,
               &RightUpperCommandDetector::isStand);
}

RightUpperCommandDetector::~RightUpperCommandDetector(void)
{
}

bool RightUpperCommandDetector::isStand(void)
{
    Vector shoulder = user->positionRightShoulder();
    Vector elbow    = user->positionRightElbow();
    Vector hand     = user->positionRightHand();
    Vector upperArm = user->skeletonRightUpperArm().reverse();
    Vector forearm  = user->skeletonRightForearm();

    return shoulder.Y < hand.Y
        && hand.Y > elbow.Y
        && upperArm.withinAngle(forearm, 90.0f);
}

bool RightUpperCommandDetector::isRightUpperBefore(void)
{
    Vector shoulder = user->positionRightShoulder();
    Vector elbow    = user->positionRightElbow();
    Vector hand     = user->positionRightHand();
    Vector neck     = user->positionNeck();
    Vector upperArm = user->skeletonRightUpperArm();
    Vector forearm  = user->skeletonRightForearm();

    return shoulder.Y > hand.Y
        && shoulder.Y > elbow.Y
        && neck.X < hand.X
        && upperArm.isOrthogonal(forearm);
}

bool RightUpperCommandDetector::isRightUpperAfter(void)
{
    Vector shoulder = user->positionRightShoulder();
    Vector elbow    = user->positionRightElbow();
    Vector hand     = user->positionRightHand();
    Vector neck     = user->positionNeck();
    Vector upperArm = user->skeletonRightUpperArm();
    Vector forearm  = user->skeletonRightForearm();

    return shoulder.Y < hand.Y
        && neck.X < hand.X
        && neck.X < elbow.X
        && upperArm.isOrthogonal(forearm);
}
