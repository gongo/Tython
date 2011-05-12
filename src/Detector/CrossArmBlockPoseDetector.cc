#include "CrossArmBlockPoseDetector.h"

bool CrossArmBlockPoseDetector::isPosing(void)
{
    Vector rarm = user->skeletonRightForearm();
    Vector larm = user->skeletonLeftForearm();
    return rarm.isOrthogonal(larm);
}
