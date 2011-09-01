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

bool LeftHookCommandDetector::isStand(void) const
{
    Vector shoulder = user->positionLeftShoulder();
    Vector elbow    = user->positionLeftElbow();
    Vector hand     = user->positionLeftHand();

    return user->leftArmIsBentRightAngle()
        && hand.Y > shoulder.Y
        && hand.Y > elbow.Y;
}

bool LeftHookCommandDetector::isLeftHookBefore(void) const
{
    Vector shoulder = user->positionLeftShoulder();
    Vector elbow    = user->positionLeftElbow();
    Vector hand     = user->positionLeftHand();

    return user->leftArmIsBentRightAngle()
        && shoulder.X > hand.X
        && shoulder.X > elbow.X;
}

bool LeftHookCommandDetector::isLeftHookAfter(void) const
{
    Vector shoulder = user->positionLeftShoulder();
    Vector elbow    = user->positionLeftElbow();
    Vector hand     = user->positionLeftHand();
    Vector neck     = user->positionNeck();

    return shoulder.X < elbow.X
        && elbow.X < hand.X
        && neck.X < hand.X;
}
