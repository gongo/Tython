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

bool RightUpperCommandDetector::isStand(void) const
{
    Vector shoulder = user->positionRightShoulder();
    Vector elbow    = user->positionRightElbow();
    Vector hand     = user->positionRightHand();

    return user->rightArmIsBentRightAngle()
        && hand.Y > shoulder.Y
        && hand.Y > elbow.Y;
}

bool RightUpperCommandDetector::isRightUpperBefore(void) const
{
    Vector shoulder = user->positionRightShoulder();
    Vector elbow    = user->positionRightElbow();
    Vector hand     = user->positionRightHand();
    Vector neck     = user->positionNeck();

    return user->rightArmIsBentRightAngle()
        && shoulder.Y > hand.Y
        && shoulder.Y > elbow.Y
        && neck.X < hand.X;
}

bool RightUpperCommandDetector::isRightUpperAfter(void) const
{
    Vector shoulder = user->positionRightShoulder();
    Vector elbow    = user->positionRightElbow();
    Vector hand     = user->positionRightHand();
    Vector neck     = user->positionNeck();

    return user->rightArmIsBentRightAngle()
        && shoulder.Y < hand.Y
        && neck.X < hand.X
        && neck.X < elbow.X;
}
