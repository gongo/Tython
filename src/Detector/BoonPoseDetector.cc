#include "BoonPoseDetector.h"

bool BoonPoseDetector::isPosing(void)
{
    Vector rightUpperArm = user->skeletonRightUpperArm();
    Vector leftUpperArm  = user->skeletonLeftUpperArm();
    Vector medianLine    = user->skeletonHead();
    Vector rightHand     = user->positionRightHand();
    Vector leftHand      = user->positionLeftHand();
    Vector head          = user->positionHead();

    return user->rightArmIsStraight()
        && user->leftArmIsStraight()
        && medianLine.betweenAngle(rightUpperArm, 90.0f)
        && medianLine.betweenAngle(leftUpperArm, 90.0f);
}
