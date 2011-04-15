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
    static Timer* getInstance(void);

    double current(void);

    /**
     * インスタンス生成時の time
     */
    timeval start;

    /**
     * 
     */
    timeval currentTime;

private:
    /**
     * コンストラクタ
     *
     * Singleton のため、private で定義
     */
    Timer(void);
    Timer(const Timer& obj) {}
    /**
     * Time クラスインスタンス
     */
    static Timer* instance;
};

#endif // _TYTHON_TIMER_H_
