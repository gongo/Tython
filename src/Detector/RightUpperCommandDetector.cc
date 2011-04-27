#include "RightUpperTriggerDetector.h"

RightUpperTriggerDetector::RightUpperTriggerDetector(User* _user) : TriggerDetector(_user)
{
    setTrigger(1, 4,
               &RightUpperTriggerDetector::isStand,
               &RightUpperTriggerDetector::isRightUpperBefore,
               &RightUpperTriggerDetector::isRightUpperAfter,
               &RightUpperTriggerDetector::isStand);
}

RightUpperTriggerDetector::~RightUpperTriggerDetector(void)
{
}

bool RightUpperTriggerDetector::isStand(void)
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

bool RightUpperTriggerDetector::isRightUpperBefore(void)
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

bool RightUpperTriggerDetector::isRightUpperAfter(void)
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
