#include "OwataPoseDetector.h"

bool OwataPoseDetector::isPosing(void)
{
    Vector rightUpperArm = user->skeletonRightUpperArm();
    Vector leftUpperArm  = user->skeletonLeftUpperArm();
    Vector medianLine    = user->skeletonHead();
    Vector rightHand     = user->positionRightHand();
    Vector leftHand      = user->positionLeftHand();
    Vector head          = user->positionHead();

    return user->rightArmIsStraight()
        && user->leftArmIsStraight()
        && medianLine.betweenAngle(rightUpperArm, 45.0f)
        && medianLine.betweenAngle(leftUpperArm, 45.0f)
        && head.Y < rightHand.Y
        && head.Y < leftHand.Y;
}
