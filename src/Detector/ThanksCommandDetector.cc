#include "ThanksCommandDetector.h"
#include "CrossArmBlockPoseDetector.h"

ThanksCommandDetector::ThanksCommandDetector(User* _user) : CommandDetector(_user)
{
    setCommand(2, 1,
               &ThanksCommandDetector::isCrossArm,
               &ThanksCommandDetector::isBottomArm);
}

ThanksCommandDetector::~ThanksCommandDetector(void)
{
}

bool ThanksCommandDetector::isCrossArm(void)
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

bool ThanksCommandDetector::isBottomArm(void)
{
    Vector rightForearm= user->skeletonRightForearm();
    Vector rightUpperArm= user->skeletonRightUpperArm();
    Vector leftForearm = user->skeletonLeftForearm();
    Vector leftUpperArm = user->skeletonLeftUpperArm();
    Vector rightHand = user->positionRightHand();
    Vector leftHand = user->positionLeftHand();
    Vector waist = user->positionWaist();
    Vector neck = user->positionNeck();

    return rightForearm.isStraight(rightUpperArm.reverse())
        && leftForearm.isStraight(leftUpperArm.reverse())
        && rightHand.Y > neck.Y
        && leftHand.Y > neck.Y;
}
