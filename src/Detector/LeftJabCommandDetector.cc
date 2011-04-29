#include "LeftJabCommandDetector.h"

LeftJabCommandDetector::LeftJabCommandDetector(User* _user) : CommandDetector(_user)
{
    setCommand(1, 3,
               &LeftJabCommandDetector::isStand,
               &LeftJabCommandDetector::isLeftJab,
               &LeftJabCommandDetector::isStand);
}

LeftJabCommandDetector::~LeftJabCommandDetector(void)
{
}

bool LeftJabCommandDetector::isStand(void)
{
    Vector shoulder = user->positionLeftShoulder();
    Vector elbow    = user->positionLeftElbow();
    Vector hand     = user->positionLeftHand();
    Vector upperArm = user->skeletonLeftUpperArm();
    Vector forearm  = user->skeletonLeftForearm();
    printf("%f %f\n", hand.X, hand.Y);
    return shoulder.Y < hand.Y
        && hand.Y > elbow.Y
        && upperArm.isOrthogonal(forearm);
}

bool LeftJabCommandDetector::isLeftJab(void)
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
