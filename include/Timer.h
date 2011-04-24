// -*- C++ -*-

#ifndef _TYTHON_TIMER_H_
#define _TYTHON_TIMER_H_

#include <sys/time.h>

class Timer {
public:
    /**
     * インスタンス取得
     *
     * @return  Timer のインスタンス
     */
    static Timer* instance(void);

    virtual int current(void);

    /**
     * インスタンス生成時の time
     */
    timeval start;

    /**
     * 
     */
    timeval currentTime;

protected:
    /**
     * コンストラクタ
     *
     * Singleton だが MockTimer のため、protected で定義
     */
    Timer(void);

    /**
     * コンストラクタ
     *
     * Singleton だが MockTimer のため、protected で定義
     */
    Timer(const Timer& obj) {}

private:
    /**
     * Time クラスインスタンス
     */
    static Timer* _instance;
};

#endif // _TYTHON_TIMER_H_
