// -*- C++ -*-

#ifndef _TYTHON_CROSS_ARM_BLOCK_POSE_DETECTOR_H_
#define _TYTHON_CROSS_ARM_BLOCK_POSE_DETECTOR_H_

#include "PoseDetector.h"

class CrossArmBlockPoseDetector : public PoseDetector {
public:
    CrossArmBlockPoseDetector(User* _user) : PoseDetector(_user) {}
    virtual ~CrossArmBlockPoseDetector(void) {}

    /**
     * ポーズをとっているか判定
     * 
     * @return ポーズを検出できれば true
     */
    bool isPosing(void);

protected:
    /**
     * クロスアームブロックのポーズをとっているか判定
     *
     * 両腕を 90 度に交差
     * 
     * @return ポーズを検出できれば true / できなければ false
     */
    bool isCrossArmBlockForm(void);
    
private:
};

#endif // _TYTHON_CROSS_ARM_BLOCK_POSE_DETECTOR_H_
