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
     * 構え状態かチェックする
     *
     * @return  構え状態であれば true
     */
    bool isStand(void);

    /**
     * ジャブ構え状態かチェックする
     *
     * @return  ジャブ構え状態であれば true
     */
    bool isLeftJab(void);
};

#endif // _TYTHON_LEFT_JAB_TRIGGER_DETECTOR_H_
