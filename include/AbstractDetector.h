// -*- C++ -*-

#ifndef _TYTHON_ABSTRACT_DETECTOR_H_
#define _TYTHON_ABSTRACT_DETECTOR_H_

#include "User.h"
#include "Timer.h"

class AbstractDetector {
public:
    AbstractDetector(User* _user);
    virtual ~AbstractDetector(void);

    /**
     * ポーズをとっているか判定
     * 
     * @return ポーズを検出できれば true
     */
    virtual bool isPosing(void) = 0;
    bool detect(void);
protected:
    User* user;
    Timer* timer;
private:
};

#endif // _TYTHON_ABSTRACT_DETECTOR_H_
