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

bool LeftJabCommandDetector::isStand(void) const
{
    Vector shoulder = user->positionLeftShoulder();
    Vector elbow    = user->positionLeftElbow();
    Vector hand     = user->positionLeftHand();

    return user->leftArmIsBentRightAngle()
        && hand.Y > shoulder.Y
        && hand.Y > elbow.Y;
}

bool LeftJabCommandDetector::isLeftJab(void) const
{
    Vector shoulder = user->positionLeftShoulder();
    Vector elbow    = user->positionLeftElbow();
    Vector hand     = user->positionLeftHand();

    return user->leftArmIsStraight()
        && hand.Y > shoulder.Y
        && hand.Y > elbow.Y;
}
