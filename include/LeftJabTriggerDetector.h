// -*- C++ -*-

#ifndef _TYTHON_LEFT_JAB_TRIGGER_DETECTOR_H_
#define _TYTHON_LEFT_JAB_TRIGGER_DETECTOR_H_

#include "TriggerDetector.h"

class LeftJabTriggerDetector : public TriggerDetector {
public:
    LeftJabTriggerDetector(User* _user);
    virtual ~LeftJabTriggerDetector(void);

protected:

private:
    /**
     * 
     */
    bool isStand(void);

    /**
     * 
     */
    bool isLeftJab(void);
};

#endif // _TYTHON_LEFT_JAB_TRIGGER_DETECTOR_H_
