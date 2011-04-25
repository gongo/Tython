// -*- C++ -*-

#ifndef _TYTHON_RIGHT_UPPDER_TRIGGER_DETECTOR_H_
#define _TYTHON_RIGHT_UPPDER_TRIGGER_DETECTOR_H_

#include "TriggerDetector.h"

class RightUpperTriggerDetector : public TriggerDetector {
public:
    RightUpperTriggerDetector(User* _user);
    virtual ~RightUpperTriggerDetector(void);

protected:

private:
    /**
     * 構え状態かチェックする
     *
     * @return  構え状態であれば true
     */
    bool isStand(void);

    /**
     * アッパー打つ前の体勢かどうかチェックする
     *
     * @return  構え状態であれば true
     */
    bool isRightUpperBefore(void);

    /**
     * アッパー打った後の体勢かどうかチェックする
     *
     * @return  構え状態であれば true
     */
    bool isRightUpperAfter(void);
};

#endif // _TYTHON_RIGHT_UPPDER_TRIGGER_DETECTOR_H_
