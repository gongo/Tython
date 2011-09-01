// -*- C++ -*-

#ifndef _TYTHON_RIGHT_UPPDER_COMMAND_DETECTOR_H_
#define _TYTHON_RIGHT_UPPDER_COMMAND_DETECTOR_H_

#include "CommandDetector.h"

namespace ty {

class RightUpperCommandDetector : public CommandDetector {
public:
    RightUpperCommandDetector(User* _user);
    virtual ~RightUpperCommandDetector(void);

    /**
     * 構え状態かチェックする
     *
     * @return  構え状態であれば true
     */
    bool isStand(void) const;

    /**
     * アッパー打つ前の体勢かどうかチェックする
     *
     * @return  構え状態であれば true
     */
    bool isRightUpperBefore(void) const;

    /**
     * アッパー打った後の体勢かどうかチェックする
     *
     * @return  構え状態であれば true
     */
    bool isRightUpperAfter(void) const;
};

} // namespace ty

#endif // _TYTHON_RIGHT_UPPDER_COMMAND_DETECTOR_H_
