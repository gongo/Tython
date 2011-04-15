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
     * 制限時間やポーズなど、トリガーに関する設定を行う
     *
     * @param  _timeLimit   this->timeLimit
     * @param  _triggerNum  this->triggerNum
     * @param ...
     */
    void setTrigger(int _timeLimit, int _triggerNum, ...);

    /**
     * Trigger となるポーズを検出するメソッドの typename
     */
    typedef bool (TriggerDetector::*Trigger)(void);

    /**
     * Trigger となるポーズを検出するメソッドのリスト
     */
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

    /**
     * 最初のポーズ検出後からの経過時間
     */
    int currentTime;
private:
    void resetTrigger(void);
    bool withinTimeLimit(void);
};

#endif // _TYTHON_TRIGGER_DETECTOR_H_
