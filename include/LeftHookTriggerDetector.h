// -*- C++ -*-

#ifndef _TYTHON_LEFT_HOOK_TRIGGER_DETECTOR_H_
#define _TYTHON_LEFT_HOOK_TRIGGER_DETECTOR_H_

#include "TriggerDetector.h"

class LeftHookTriggerDetector : public TriggerDetector {
public:
    LeftHookTriggerDetector(User* _user);
    virtual ~LeftHookTriggerDetector(void);

protected:

private:
    /**
     * 構え状態かチェックする
     *
     * @return  構え状態であれば true
     */
    bool isStand(void);

    /**
     * フックを撃つ前の体勢かどうかチェックする
     *
     * 左腕が身体の外にある感じ
     *
     * @return  構え状態であれば true
     */
    bool isLeftHookBefore(void);

    /**
     * フックを撃った後の体勢かどうかチェックする
     *
     * 左腕が身体の右側にある感じ
     *
     * @return  構え状態であれば true
     */
    bool isLeftHookAfter(void);
};

#endif // _TYTHON_LEFT_HOOK_TRIGGER_DETECTOR_H_
