// -*- C++ -*-

#ifndef _TYTHON_LEFT_JAB_COMMAND_DETECTOR_H_
#define _TYTHON_LEFT_JAB_COMMAND_DETECTOR_H_

#include "CommandDetector.h"

namespace ty {

class LeftJabCommandDetector : public CommandDetector {
public:
    LeftJabCommandDetector(User* _user);
    virtual ~LeftJabCommandDetector(void);

    /**
     * 構え状態かチェックする
     *
     * @return  構え状態であれば true
     */
    bool isStand(void) const;

    /**
     * ジャブ構え状態かチェックする
     *
     * @return  ジャブ構え状態であれば true
     */
    bool isLeftJab(void) const;
};

} // namespace ty

#endif // _TYTHON_LEFT_JAB_COMMAND_DETECTOR_H_
