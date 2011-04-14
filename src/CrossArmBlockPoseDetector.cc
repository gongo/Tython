#include <stdio.h>
#include "CrossArmBlockPoseDetector.h"

bool CrossArmBlockPoseDetector::isPosing(void)
{
    return isCrossArmBlockForm();
}

bool CrossArmBlockPoseDetector::isCrossArmBlockForm(void)
{
    Vector rarm = user->skeletonRightForearm();
    Vector larm = user->skeletonLeftForearm();
    return rarm.isOrthogonal(larm);
}
