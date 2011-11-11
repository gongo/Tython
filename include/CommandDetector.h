// -*- C++ -*-

#ifndef _TYTHON_COMMAND_DETECTOR_H_
#define _TYTHON_COMMAND_DETECTOR_H_

#include "AbstractDetector.h"

namespace ty {

class CommandDetector : public AbstractDetector {
public:
    /**
     * @brief コンストラクタ
     *
     * コマンドのリストと経過時間を初期化する
     *
     * @param _user User インスタンス
     */
    CommandDetector(User* _user);

    /**
     * @brief デストラクタ
     *
     * コマンドリストがセットされていれば、delete する
     */
    virtual ~CommandDetector(void);

    /**
     * @brief ポーズをとっているか判定
     *
     * 定められた時間内に指定された順番の Pose をしたかを確認する
     *
     * @return ポーズを検出できれば true
     */
    bool isPosing(void);

protected:
    /**
     * @brief 制限時間やポーズなど、コマンドに関する設定を行う
     *
     * @param  _timeLimit   this->timeLimit
     * @param  _commandNum  this->commandNum
     * @param ...           ポーズ検出関数
     */
    void setCommand(XnUInt64 _timeLimit, int _commandNum, ...);

    /**
     * @brief コマンドとなるポーズを検出するメソッドの typename
     */
    typedef bool (CommandDetector::*Command)(void);

private:
    /**
     * @brief 検出状況をリセットする
     */
    void resetCommand(void);

    /**
     * @brief 次のポーズの検出を開始する
     */
    void nextCommand(void);

    /**
     * @brief 制限時間内かどうかを判定する
     *
     * @return  制限時間内であれば true
     */
    bool withinTimeLimit(void);

    /**
     * @brief 最初のポーズ検出後からの経過時間
     */
    XnUInt64 elapsedTime;

    /**
     * @brief 一番最後にポーズ検出したときの時間
     */
    XnUInt64 detectionTime;

    /**
     * @brief ポーズを検出するメソッドのリスト
     */
    Command *commandList;

    /**
     * @brief Current index of traceList[]
     *
     * @see commandList
     */
    int commandIndex;

    /**
     * @brief コマンド達成に必要なポーズの数
     */
    int commandNum;

    /**
     * @brief 制限時間
     */
    XnUInt64 timeLimit;
};

} // namespace

#endif // _TYTHON_COMMAND_DETECTOR_H_
