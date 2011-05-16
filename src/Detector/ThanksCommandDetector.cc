#include "ThanksCommandDetector.h"

ThanksCommandDetector::ThanksCommandDetector(User* _user) : CommandDetector(_user)
{
    setCommand(1, 2,
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
    Vector neck = user->positionNeck();
    Vector waist = user->positionWaist();

    return rightForearm.isOrthogonal(leftForearm)
        && rightHand.Y < neck.Y
        && leftHand.Y < neck.Y
        && rightHand.Y > waist.Y
        && leftHand.Y > waist.Y;    
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

    return rightForearm.isStraight(rightUpperArm.reverse())
        && leftForearm.isStraight(leftUpperArm.reverse())
        && rightHand.Y < waist.Y
        && leftHand.Y < waist.Y;
}
