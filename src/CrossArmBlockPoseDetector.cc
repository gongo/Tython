#include <stdio.h>
#include "CrossArmBlockPoseDetector.h"
#include "Vector.h"
#include <math.h>

bool CrossArmBlockPoseDetector::isPosing(void)
{
    return isCrossArmBlockForm();
}

bool CrossArmBlockPoseDetector::isCrossArmBlockForm(void)
{
    Vector rarm = user->getSkeletonVector(XN_SKEL_RIGHT_HAND, XN_SKEL_RIGHT_ELBOW);
    Vector larm = user->getSkeletonVector(XN_SKEL_LEFT_HAND, XN_SKEL_LEFT_ELBOW);
    return rarm.isOrthogonal(larm);
}
