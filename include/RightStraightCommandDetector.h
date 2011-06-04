// -*- C++ -*-

#ifndef _TYTHON_RIGHT_STRAIGHT_COMMAND_DETECTOR_H_
#define _TYTHON_RIGHT_STRAIGHT_COMMAND_DETECTOR_H_

#include "CommandDetector.h"

class RightStraightCommandDetector : public CommandDetector {
public:
    RightStraightCommandDetector(User* _user);
    virtual ~RightStraightCommandDetector(void);

    /**
     * 構え状態かチェックする
     *
     * @return  構え状態であれば true
     */
    bool isStand(void) const;

    /**
     * 左ジャブ状態かチェックする
     *
     * @return  左ジャブ状態であれば true
     */
    bool isRightStraight(void) const;
};

#endif // _TYTHON_RIGHT_STRAIGHT_COMMAND_DETECTOR_H_
