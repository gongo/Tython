#include "ThanksTriggerDetector.h"
#include "CrossArmBlockPoseDetector.h"

ThanksTriggerDetector::ThanksTriggerDetector(User* _user) : TriggerDetector(_user)
{
    setTrigger(2, 2,
               &ThanksTriggerDetector::isCrossArm,
               &ThanksTriggerDetector::isBottomArm);
}

ThanksTriggerDetector::~ThanksTriggerDetector(void)
{
}

bool ThanksTriggerDetector::isCrossArm(void)
{
    Vector rightForearm= user->skeletonRightForearm();
    Vector rightUpperArm= user->skeletonRightUpperArm();
    Vector leftForearm = user->skeletonLeftForearm();
    Vector leftUpperArm = user->skeletonLeftUpperArm();

    return rightForearm.isOrthogonal(leftForearm)
        || rightUpperArm.isStraight(leftUpperArm.reverse());
}

bool ThanksTriggerDetector::isBottomArm(void)
{
    Vector rightForearm= user->skeletonRightForearm();
    Vector rightUpperArm= user->skeletonRightUpperArm();
    Vector leftForearm = user->skeletonLeftForearm();
    Vector leftUpperArm = user->skeletonLeftUpperArm();

    return rightForearm.isStraight(rightUpperArm.reverse())
        || leftForearm.isStraight(leftUpperArm.reverse());
}
