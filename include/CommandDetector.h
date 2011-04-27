// -*- C++ -*-

#ifndef _TYTHON_COMMAND_DETECTOR_H_
#define _TYTHON_COMMAND_DETECTOR_H_

#include "AbstractDetector.h"

class CommandDetector : public AbstractDetector {
public:
    CommandDetector(User* _user);
    virtual ~CommandDetector(void);

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
     * 制限時間やポーズなど、コマンドに関する設定を行う
     *
     * @param  _timeLimit   this->timeLimit
     * @param  _commandNum  this->commandNum
     * @param ...
     */
    void setCommand(int _timeLimit, int _commandNum, ...);

    /**
     * コマンドとなるポーズを検出するメソッドの typename
     */
    typedef bool (CommandDetector::*Command)(void);

private:
    /**
     * リセット
     *
     * 検出状況をリセットする
     */
    void resetCommand(void);

    /**
     * 次のポーズの検出を開始する
     */
    void nextCommand(void);

    /**
     * 制限時間内かどうかを判定する
     *
     * @see  timeLimit
     *
     * @return  制限時間内であれば true
     */
    bool withinTimeLimit(void);

    /**
     * 最初のポーズ検出後からの経過時間
     */
    int elapsedTime;

    /**
     * 一番最後にポーズ検出したときの時間
     */
    int detectionTime;

    /**
     * ポーズを検出するメソッドのリスト
     */
    Command *commandList;

    /**
     * Current index of traceList[]
     *
     * @see commandList()
     */
    int commandIndex;

    /**
     * コマンド達成に必要なポーズの数
     */
    int commandNum;

    /**
     * 制限時間
     */
    int timeLimit;
};

#endif // _TYTHON_COMMAND_DETECTOR_H_
