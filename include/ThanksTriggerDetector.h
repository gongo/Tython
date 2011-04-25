// -*- C++ -*-

#ifndef _TYTHON_LEFT_THANKS_DETECTOR_H_
#define _TYTHON_LEFT_THANKS_DETECTOR_H_

#include "TriggerDetector.h"

/**
 * 十字礼を検知する TriggerDetector
 */
class ThanksTriggerDetector : public TriggerDetector {
public:
    ThanksTriggerDetector(User* _user);
    virtual ~ThanksTriggerDetector(void);

protected:

private:
    /**
     * 胴の前で腕を十字にしているかチェックする
     *
     * @return  構え状態であれば true
     */
    bool isCrossArm(void);

    /**
     * 両手を下に払っているかチェックする
     *
     * @return  構え状態であれば true
     */
    bool isBottomArm(void);
};

#endif // _TYTHON_LEFT_THANKS_DETECTOR_H_
