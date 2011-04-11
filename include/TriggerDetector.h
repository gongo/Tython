// -*- C++ -*-

#ifndef _TYTHON_TRIGGER_DETECTOR_H_
#define _TYTHON_TRIGGER_DETECTOR_H_

#include "AbstractDetector.h"

class TriggerDetector : public AbstractDetector {
public:
    TriggerDetector(User* _user);
    virtual ~TriggerDetector(void);

    /**
     * ポーズをとっているか判定
     * 
     * 定められた時間内に指定された順番の Pose をしたかを確認する
     *
     * @see triggetList()
     * @return ポーズを検出できれば true
     */
    bool isPosing(void);

protected:
    /**
     * Function list to detect trigger
     *
     * @see triggerIndex()
     */
    bool (TriggerDetector::*triggerList[])(void);

    /**
     * Current index of traceList[]
     *
     * @see triggerList()
     */
    int triggerIndex;

private:
};

#endif // _TYTHON_TRIGGER_DETECTOR_H_
