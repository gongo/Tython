// -*- C++ -*-

#ifndef _TYTHON_ABSTRACT_DETECTOR_H_
#define _TYTHON_ABSTRACT_DETECTOR_H_

#include "User.h"
#include "Timer.h"

namespace ty {

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

} // namespace ty

#endif // _TYTHON_ABSTRACT_DETECTOR_H_
