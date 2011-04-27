#include "RightStraightCommandDetector.h"

RightStraightCommandDetector::RightStraightCommandDetector(User* _user) : CommandDetector(_user)
{
    setCommand(1, 3,
               &RightStraightCommandDetector::isStand,
               &RightStraightCommandDetector::isRightStraight,
               &RightStraightCommandDetector::isStand);
}

RightStraightCommandDetector::~RightStraightCommandDetector(void)
{
}

bool RightStraightCommandDetector::isStand(void)
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

bool RightStraightCommandDetector::isRightStraight(void)
{
    Vector shoulder = user->positionRightShoulder();
    Vector elbow    = user->positionRightElbow();
    Vector hand     = user->positionRightHand();
    Vector upperArm = user->skeletonRightUpperArm().reverse();
    Vector forearm  = user->skeletonRightForearm();

    return shoulder.Y < hand.Y
        && upperArm.isStraight(forearm);
}
