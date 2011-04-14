// -*- C++ -*-

#ifndef _TYTHON_TRIGGER_DETECTOR_H_
#define _TYTHON_TRIGGER_DETECTOR_H_

#include "AbstractDetector.h"

class TriggerDetector : public AbstractDetector {
public:
    TriggerDetector(User* _user, int triggerNum, int _timeLimit);
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
     */
    typedef bool (TriggerDetector::*Trigger)(void);
    Trigger *triggerList;

    /**
     * Current index of traceList[]
     *
     * @see triggerList()
     */
    int triggerIndex;

    /**
     * Trigger となるポーズの数
     */
    int triggerNum;

    /**
     * Trigger 検出となる制限時間
     */
    int timeLimit;
private:
    void resetTrigger(void);
    bool withinTimeLimit(void);
};

#endif // _TYTHON_TRIGGER_DETECTOR_H_
