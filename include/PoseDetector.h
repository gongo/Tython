// -*- C++ -*-

#ifndef _TYTHON_POSE_DETECTOR_H_
#define _TYTHON_POSE_DETECTOR_H_

#include "AbstractDetector.h"

class PoseDetector : public AbstractDetector {
public:
    PoseDetector(User* _user);
    virtual ~PoseDetector(void);

    /**
     * ポーズをとっているか判定
     * 
     * @return ポーズを検出できれば true
     */
    bool isPosing(void);
protected:

private:
};

#endif // _TYTHON_POSE_DETECTOR_H_
