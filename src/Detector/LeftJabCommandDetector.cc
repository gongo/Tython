#include "LeftJabCommandDetector.h"

namespace ty {

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
    Vector shoulder = user->leftShoulder();
    Vector elbow    = user->leftElbow();
    Vector hand     = user->leftHand();

    return user->leftArmIsBentRightAngle()
        && hand.Y > shoulder.Y
        && hand.Y > elbow.Y;
}

bool LeftJabCommandDetector::isLeftJab(void) const
{
    Vector shoulder = user->leftShoulder();
    Vector elbow    = user->leftElbow();
    Vector hand     = user->leftHand();

    return user->leftArmIsStraight()
        && hand.Y > shoulder.Y
        && hand.Y > elbow.Y;
}

} // namespace ty
