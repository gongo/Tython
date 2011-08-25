// -*- C++ -*-

#ifndef _TYTHON_BOON_POSE_DETECTOR_H_
#define _TYTHON_BOON_POSE_DETECTOR_H_

#include "PoseDetector.h"

class BoonPoseDetector : public PoseDetector {
public:
    BoonPoseDetector(User* _user) : PoseDetector(_user) {}
    virtual ~BoonPoseDetector(void) {}

    /**
     *         ／⌒ヽ
     * ⊂二二二（  ＾ω＾）二⊃
     *        |       /
     *        （  ヽノ
     *          >ノ
     *    三    レ 
     * 
     * @return ポーズを検出できれば true / できなければ false
     */
    bool isPosing(void);
};

#endif // _TYTHON_BOON_POSE_DETECTOR_H_
