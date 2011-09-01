// -*- C++ -*-

#ifndef _TYTHON_OWATA_POSE_DETECTOR_H_
#define _TYTHON_OWATA_POSE_DETECTOR_H_

#include "PoseDetector.h"

namespace ty {

class OwataPoseDetector : public PoseDetector {
public:
    OwataPoseDetector(User* _user) : PoseDetector(_user) {}
    virtual ~OwataPoseDetector(void) {}

    /**
     * ＼(^o^)／
     *     |
     *    / \
     *
     * 1. 両腕はまっすぐ
     * @todo 2. 正中線と両腕は角度45度
     * 3. 手は頭の上
     * 
     * @return ポーズを検出できれば true / できなければ false
     */
    bool isPosing(void);
};

} // namespace ty

#endif // _TYTHON_OWATA_POSE_DETECTOR_H_
