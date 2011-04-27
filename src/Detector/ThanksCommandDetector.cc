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
    Vector leftForearm = user->skeletonLeftForearm();
    Vector rightHand = user->positionRightHand();
    Vector leftHand = user->positionLeftHand();
    Vector waist = user->positionWaist();

    return rightForearm.isOrthogonal(leftForearm)
        && (rightHand.X < leftHand.X)
        && (rightHand.Y > waist.Y)
        && (leftHand.Y > waist.Y);
    
}

bool ThanksTriggerDetector::isBottomArm(void)
{
    Vector rightForearm= user->skeletonRightForearm();
    Vector rightUpperArm= user->skeletonRightUpperArm();
    Vector leftForearm = user->skeletonLeftForearm();
    Vector leftUpperArm = user->skeletonLeftUpperArm();
    Vector rightHand = user->positionRightHand();
    Vector leftHand = user->positionLeftHand();
    Vector waist = user->positionWaist();

    return rightForearm.isStraight(rightUpperArm.reverse())
        && leftForearm.isStraight(leftUpperArm.reverse())
        && rightHand.Y < waist.Y
        && leftHand.Y < waist.Y;
}
