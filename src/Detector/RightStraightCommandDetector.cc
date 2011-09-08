#include "RightStraightCommandDetector.h"

namespace ty {

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

bool RightStraightCommandDetector::isStand(void) const
{
    Vector shoulder = user->rightShoulder();
    Vector elbow    = user->rightElbow();
    Vector hand     = user->rightHand();
    Vector upperArm = user->vectorRightUpperArm().reverse();
    Vector forearm  = user->vectorRightForearm();

    return upperArm.withinAngle(forearm, 90.0f)
        && hand.Y > shoulder.Y
        && hand.Y > elbow.Y;
}

bool RightStraightCommandDetector::isRightStraight(void) const
{
    Vector shoulder = user->rightShoulder();
    Vector hand     = user->rightHand();

    return user->rightArmIsStraight()
        && hand.Y > shoulder.Y;
}

} // namespace ty
