#include "LeftHookTriggerDetector.h"

LeftHookTriggerDetector::LeftHookTriggerDetector(User* _user) : TriggerDetector(_user)
{
    setTrigger(1, 4,
               &LeftHookTriggerDetector::isStand,
               &LeftHookTriggerDetector::isLeftHookBefore,
               &LeftHookTriggerDetector::isLeftHookAfter,
               &LeftHookTriggerDetector::isStand);
}

LeftHookTriggerDetector::~LeftHookTriggerDetector(void)
{
}

bool LeftHookTriggerDetector::isStand(void)
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

bool LeftHookTriggerDetector::isLeftHookBefore(void)
{
    Vector shoulder = user->positionLeftShoulder();
    Vector elbow    = user->positionLeftElbow();
    Vector hand     = user->positionLeftHand();
    Vector upperArm = user->skeletonLeftUpperArm().reverse();
    Vector forearm  = user->skeletonLeftForearm();

    return shoulder.X > hand.X
        && shoulder.X > elbow.X
        && upperArm.isOrthogonal(forearm);
}

bool LeftHookTriggerDetector::isLeftHookAfter(void)
{
    Vector shoulder = user->positionLeftShoulder();
    Vector elbow    = user->positionLeftElbow();
    Vector hand     = user->positionLeftHand();
    Vector neck     = user->positionNeck();
    Vector upperArm = user->skeletonLeftUpperArm();
    Vector forearm  = user->skeletonLeftForearm();

    return shoulder.X < elbow.X
        && elbow.X < hand.X
        && neck.X < hand.X
        && upperArm.isOrthogonal(forearm);
}
