// -*- C++ -*-

#ifndef _TYTHON_TIMER_H_
#define _TYTHON_TIMER_H_

#include <XnOS.h>

namespace ty {

class Timer {
public:
    /**
     * インスタンス取得
     *
     * @return  Timer のインスタンス
     */
    static Timer* instance(void);

    /**
     * プログラム起動から現在までの経過秒数を返す
     *
     * @return プログラム起動から現在までの経過秒数
     */
    virtual XnUInt64 current(void);

protected:
    /**
     * コンストラクタ
     *
     * Singleton だが、MockTimer のため protected で定義
     */
    Timer(void);

    /**
     * コピーコンストラクタ
     *
     * Singleton だが、 MockTimer のため protected で定義
     */
    Timer(const Timer& obj) {}

private:
    /**
     * Timer インスタンス
     */
    static Timer* _instance;

    /**
     * XnOSTimer
     */
    XnOSTimer tick;
};

} // namespace ty

#endif // _TYTHON_TIMER_H_
