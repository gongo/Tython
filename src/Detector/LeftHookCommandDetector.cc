#include "LeftHookCommandDetector.h"

namespace ty {

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
    Vector shoulder = user->leftShoulder();
    Vector elbow    = user->leftElbow();
    Vector hand     = user->leftHand();

    return user->leftArmIsBentRightAngle()
        && hand.Y > shoulder.Y
        && hand.Y > elbow.Y;
}

bool LeftHookCommandDetector::isLeftHookBefore(void) const
{
    Vector shoulder = user->leftShoulder();
    Vector elbow    = user->leftElbow();
    Vector hand     = user->leftHand();

    return user->leftArmIsBentRightAngle()
        && shoulder.X > hand.X
        && shoulder.X > elbow.X;
}

bool LeftHookCommandDetector::isLeftHookAfter(void) const
{
    Vector shoulder = user->leftShoulder();
    Vector elbow    = user->leftElbow();
    Vector hand     = user->leftHand();
    Vector neck     = user->neck();

    return shoulder.X < elbow.X
        && elbow.X < hand.X
        && neck.X < hand.X;
}

} // namespace ty
