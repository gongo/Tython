#include "RightUpperCommandDetector.h"

namespace ty {

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

bool RightUpperCommandDetector::isStand(void) const
{
    Vector shoulder = user->rightShoulder();
    Vector elbow    = user->rightElbow();
    Vector hand     = user->rightHand();

    return user->rightArmIsBentRightAngle()
        && hand.Y > shoulder.Y
        && hand.Y > elbow.Y;
}

bool RightUpperCommandDetector::isRightUpperBefore(void) const
{
    Vector shoulder = user->rightShoulder();
    Vector elbow    = user->rightElbow();
    Vector hand     = user->rightHand();
    Vector neck     = user->neck();

    return user->rightArmIsBentRightAngle()
        && shoulder.Y > hand.Y
        && shoulder.Y > elbow.Y
        && neck.X < hand.X;
}

bool RightUpperCommandDetector::isRightUpperAfter(void) const
{
    Vector shoulder = user->rightShoulder();
    Vector elbow    = user->rightElbow();
    Vector hand     = user->rightHand();
    Vector neck     = user->neck();

    return user->rightArmIsBentRightAngle()
        && shoulder.Y < hand.Y
        && neck.X < hand.X
        && neck.X < elbow.X;
}

} // namespace ty
