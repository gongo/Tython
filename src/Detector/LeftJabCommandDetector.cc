#include "LeftJabTriggerDetector.h"

LeftJabTriggerDetector::LeftJabTriggerDetector(User* _user) : TriggerDetector(_user)
{
    setTrigger(1, 3,
               &LeftJabTriggerDetector::isStand,
               &LeftJabTriggerDetector::isLeftJab,
               &LeftJabTriggerDetector::isStand);
}

LeftJabTriggerDetector::~LeftJabTriggerDetector(void)
{
}

bool LeftJabTriggerDetector::isStand(void)
{
    Vector shoulder = user->positionLeftShoulder();
    Vector elbow    = user->positionLeftElbow();
    Vector hand     = user->positionLeftHand();
    Vector upperArm = user->skeletonLeftUpperArm();
    Vector forearm  = user->skeletonLeftForearm();

    return shoulder.Y < hand.Y
        && hand.Y > elbow.Y
        && upperArm.isOrthogonal(forearm);
}

bool LeftJabTriggerDetector::isLeftJab(void)
{
    Vector shoulder = user->positionLeftShoulder();
    Vector elbow    = user->positionLeftElbow();
    Vector hand     = user->positionLeftHand();
    Vector upperArm = user->skeletonLeftUpperArm().reverse();
    Vector forearm  = user->skeletonLeftForearm();

    return shoulder.Y < hand.Y
        && hand.Y > elbow.Y
        && upperArm.isStraight(forearm);
}
