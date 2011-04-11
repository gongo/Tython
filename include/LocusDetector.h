// -*- C++ -*-

#ifndef _TYTHON_LOCUS_DETECTOR_H_
#define _TYTHON_LOCUS_DETECTOR_H_

#include "AbstractDetector.h"
#include "Vector.h"

class LocusDetector : public AbstractDetector {
public:
    LocusDetector(User* _user);
    virtual ~LocusDetector(void);

    /**
     * ポーズをとっているか判定
     * 
     * 定められた時間内に軌跡通りの動きをするか確認する
     *
     * @see trace()
     * @see timeLimit()
     * @see moveThreshold()
     * @return ポーズを検出できれば true
     */
    bool isPosing(void);

protected:
    /**
     * Function to detect trace
     */
    bool trace(void) const;

    /**
     * トレース開始とみなせる移動量かどうかを判定する
     *
     * @param v_st 移動前のベクトル
     * @param v_ed 移動後のベクトル
     *
     * @return しきい値を超えていれば true
     */
    bool isTraceCondition (const Vector& v_st, const Vector& v_ed) const;

    /**
     * Detection time limit (sec)
     */
    const float timeLimit;

    /**
     * Move threshold distance
     *
     * トレース開始とみなす為の、座標移動距離のしきい値
     */
    const float moveThreshold;

private:
};

#endif // _TYTHON_LOCUS_DETECTOR_H_
