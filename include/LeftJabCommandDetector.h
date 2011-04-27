// -*- C++ -*-

#ifndef _TYTHON_LEFT_JAB_COMMAND_DETECTOR_H_
#define _TYTHON_LEFT_JAB_COMMAND_DETECTOR_H_

#include "CommandDetector.h"

class LeftJabCommandDetector : public CommandDetector {
public:
    LeftJabCommandDetector(User* _user);
    virtual ~LeftJabCommandDetector(void);

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

#endif // _TYTHON_LEFT_JAB_COMMAND_DETECTOR_H_
