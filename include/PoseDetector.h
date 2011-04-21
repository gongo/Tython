// -*- C++ -*-

#ifndef _TYTHON_POSE_DETECTOR_H_
#define _TYTHON_POSE_DETECTOR_H_

#include "AbstractDetector.h"

class PoseDetector : public AbstractDetector {
public:
    PoseDetector(User* _user);
    virtual ~PoseDetector(void);
protected:

private:
};

#endif // _TYTHON_POSE_DETECTOR_H_
