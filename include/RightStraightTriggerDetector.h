// -*- C++ -*-

#ifndef _TYTHON_RIGHT_STRAIGHT_TRIGGER_DETECTOR_H_
#define _TYTHON_RIGHT_STRAIGHT_TRIGGER_DETECTOR_H_

#include "TriggerDetector.h"

class RightStraightTriggerDetector : public TriggerDetector {
public:
    RightStraightTriggerDetector(User* _user);
    virtual ~RightStraightTriggerDetector(void);

protected:

private:
    /**
     * 構え状態かチェックする
     *
     * @return  構え状態であれば true
     */
    bool isStand(void);

    /**
     * 左ジャブ状態かチェックする
     *
     * @return  左ジャブ状態であれば true
     */
    bool isRightStraight(void);
};

#endif // _TYTHON_RIGHT_STRAIGHT_TRIGGER_DETECTOR_H_
