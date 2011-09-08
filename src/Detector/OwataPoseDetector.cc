#include "OwataPoseDetector.h"

namespace ty {

bool OwataPoseDetector::isPosing(void)
{
    Vector rightUpperArm = user->vectorRightUpperArm();
    Vector leftUpperArm  = user->vectorLeftUpperArm();
    Vector medianLine    = user->vectorHead();
    Vector rightHand     = user->rightHand();
    Vector leftHand      = user->leftHand();
    Vector head          = user->head();

    return user->rightArmIsStraight()
        && user->leftArmIsStraight()
        && medianLine.betweenAngle(rightUpperArm, 45.0f)
        && medianLine.betweenAngle(leftUpperArm, 45.0f)
        && head.Y < rightHand.Y
        && head.Y < leftHand.Y;
}

} // namespace ty
