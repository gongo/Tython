// -*- C++ -*-

#ifndef _TYTHON_LEFT_JAB_TRIGGER_DETECTOR_H_
#define _TYTHON_LEFT_JAB_TRIGGER_DETECTOR_H_

#include "TriggerDetector.h"

class LeftJabTriggerDetector : public TriggerDetector {
public:
    LeftJabTriggerDetector(User* _user);
    virtual ~LeftJabTriggerDetector(void);

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

private:
    /**
     * 
     */
    bool isStand(void);

    /**
     * 
     */
    bool isLeftJab(void);
};

#endif // _TYTHON_LEFT_JAB_TRIGGER_DETECTOR_H_
