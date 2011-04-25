#include "RightStraightTriggerDetector.h"

RightStraightTriggerDetector::RightStraightTriggerDetector(User* _user) : TriggerDetector(_user)
{
    setTrigger(1, 3,
               &RightStraightTriggerDetector::isStand,
               &RightStraightTriggerDetector::isRightStraight,
               &RightStraightTriggerDetector::isStand);
}

RightStraightTriggerDetector::~RightStraightTriggerDetector(void)
{
}

bool RightStraightTriggerDetector::isStand(void)
{
    Vector shoulder = user->positionRightShoulder();
    Vector elbow    = user->positionRightElbow();
    Vector hand     = user->positionRightHand();
    Vector forearm  = user->skeletonRightForearm();
    Vector upperArm = user->skeletonRightUpperArm();
    printf("%f\n", upperArm.dot(forearm));
    return (shoulder.Y < hand.Y) && (hand.Y > elbow.Y)
        && upperArm.withinAngle(forearm, 80.0f);
}

bool RightStraightTriggerDetector::isRightStraight(void)
{
    Vector upperArm = user->skeletonRightUpperArm().reverse();
    Vector forearm  = user->skeletonRightForearm();
    return upperArm.isStraight(forearm);
}
