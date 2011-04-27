#include "LeftHookCommandDetector.h"

LeftHookCommandDetector::LeftHookCommandDetector(User* _user) : CommandDetector(_user)
{
    setCommand(1, 4,
               &LeftHookCommandDetector::isStand,
               &LeftHookCommandDetector::isLeftHookBefore,
               &LeftHookCommandDetector::isLeftHookAfter,
               &LeftHookCommandDetector::isStand);
}

LeftHookCommandDetector::~LeftHookCommandDetector(void)
{
}

bool LeftHookCommandDetector::isStand(void)
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

bool LeftHookCommandDetector::isLeftHookBefore(void)
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

bool LeftHookCommandDetector::isLeftHookAfter(void)
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
