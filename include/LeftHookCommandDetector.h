// -*- C++ -*-

#ifndef _TYTHON_LEFT_HOOK_COMMAND_DETECTOR_H_
#define _TYTHON_LEFT_HOOK_COMMAND_DETECTOR_H_

#include "CommandDetector.h"

class LeftHookCommandDetector : public CommandDetector {
public:
    LeftHookCommandDetector(User* _user);
    virtual ~LeftHookCommandDetector(void);

    /**
     * 構え状態かチェックする
     *
     * @return  構え状態であれば true
     */
    bool isStand(void) const;

    /**
     * フックを撃つ前の体勢かどうかチェックする
     *
     * 左腕が身体の外にある感じ
     *
     * @return  構え状態であれば true
     */
    bool isLeftHookBefore(void) const;

    /**
     * フックを撃った後の体勢かどうかチェックする
     *
     * 左腕が身体の右側にある感じ
     *
     * @return  構え状態であれば true
     */
    bool isLeftHookAfter(void) const;
};

#endif // _TYTHON_LEFT_HOOK_COMMAND_DETECTOR_H_
