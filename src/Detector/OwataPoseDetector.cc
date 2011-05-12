#include "OwataPoseDetector.h"

bool OwataPoseDetector::isPosing(void)
{
    Vector rightForearm  = user->skeletonRightForearm();
    Vector rightUpperArm = user->skeletonRightUpperArm();
    Vector leftForearm   = user->skeletonLeftForearm();
    Vector leftUpperArm  = user->skeletonLeftUpperArm();
    //Vector medianLine    = user->skeletonMedianLine().reverse();
    Vector medianLine    = user->skeletonHead();
    Vector rightHand     = user->positionRightHand();
    Vector leftHand      = user->positionLeftHand();
    Vector head          = user->positionHead();

    return rightForearm.isStraight(rightUpperArm.reverse())
        && leftForearm.isStraight(leftUpperArm.reverse())
        && medianLine.betweenAngle(rightUpperArm, 45.0f)
        && medianLine.betweenAngle(leftUpperArm, 45.0f)
        && head.Y < rightHand.Y
        && head.Y < leftHand.Y;
}
