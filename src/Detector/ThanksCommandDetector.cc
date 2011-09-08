#include "ThanksCommandDetector.h"

namespace ty {

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
    Vector rightForearm= user->vectorRightForearm();
    Vector leftForearm = user->vectorLeftForearm();
    Vector rightHand = user->rightHand();
    Vector leftHand = user->leftHand();
    Vector neck = user->neck();
    Vector waist = user->waist();

    return rightForearm.isOrthogonal(leftForearm)
        && rightHand.Y < neck.Y
        && leftHand.Y < neck.Y
        && rightHand.Y > waist.Y
        && leftHand.Y > waist.Y;    
}

bool ThanksCommandDetector::isBottomArm(void)
{
    Vector rightForearm= user->vectorRightForearm();
    Vector rightUpperArm= user->vectorRightUpperArm();
    Vector leftForearm = user->vectorLeftForearm();
    Vector leftUpperArm = user->vectorLeftUpperArm();
    Vector rightHand = user->rightHand();
    Vector leftHand = user->leftHand();
    Vector waist = user->waist();

    return rightForearm.isStraight(rightUpperArm)
        && leftForearm.isStraight(leftUpperArm)
        && rightHand.Y < waist.Y
        && leftHand.Y < waist.Y;
}

} // namespace ty
