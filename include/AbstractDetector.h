// -*- C++ -*-

#ifndef _TYTHON_ABSTRACT_DETECTOR_H_
#define _TYTHON_ABSTRACT_DETECTOR_H_

#include "User.h"
#include "Timer.h"

namespace ty {

class AbstractDetector {
public:
    /**
     * @brief コンストラクタ
     *
     * Timer のインスタンスを取得する
     * 
     * @param _user User インスタンス
     */
    AbstractDetector(User* _user);

    /**
     * @brief デストラクタ
     */
    virtual ~AbstractDetector(void);

    /**
     * @brief ポーズをとっているか判定
     * 
     * @return ポーズを検出できれば true
     */
    virtual bool isPosing(void) = 0;

    /**
     * @brief キャリブレーション済みのユーザがポーズを取っているか判定
     *
     * @return 条件を満たしていれば true
     */
    bool detect(void);
protected:
    /**
     * User インスタンス
     */
    User* user;

    /**
     * Timer インスタンス
     */
    Timer* timer;
private:
};

} // namespace ty

#endif // _TYTHON_ABSTRACT_DETECTOR_H_
