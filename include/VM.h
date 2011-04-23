// -*- C++ -*-

#ifndef _TYTHON_VM_H_
#define _TYTHON_VM_H_

#include <string>
#include <vector>
#include <map>
#include "Instruction.h"

using std::string;
using std::vector;
using std::map;

class VM {
public:
    /**
     * VM インスタンスを返す
     *
     * @return  VM インスタンス
     */
    static VM* instance(void);

    /**
     * 
     * @todo 知らぬ命令がきたとき例外を投げるとか
     *
     * @param
     * @return
     */
    bool run(vector<Instruction*> insns);

    /**
     * スタックにプッシュ
     *
     * @param  arg  特に使わず
     */ 
    void push(int arg);

    /**
     * スタックトップを削除
     */
    void discard(int arg);

    /**
     * スタックトップを複製し、プッシュする
     *
     * @param  arg  特に使わず
     */ 
    void dup(int arg);

    /**
     * スタックの 0 番目と 1 番目を入れ替える
     *
     * @param  arg  特に使わず
     */ 
    void swap(int arg);

    /**
     * スタックトップの下から指定した数だけスタックから削除する
     *
     * @param  arg  削除する数
     */ 
    void slide(int arg);

    /**
     * 0 番目と 1 番目 をスタックから取り出し、加算結果([0]*[1])をプッシュする
     *
     * @param  arg  特に使わず
     */ 
    void add(int arg);

    /**
     * 0 番目と 1 番目 をスタックから取り出し、減算結果([0]-[1])をプッシュする
     *
     * @param  arg  特に使わず
     */ 
    void sub(int arg);

    /**
     * 0 番目と 1 番目 をスタックから取り出し、乗算結果([0]*[1])をプッシュする
     *
     * @param  arg  特に使わず
     */ 
    void mul(int arg);

    /**
     * 0 番目と 1 番目 をスタックから取り出し、除算結果([0]/[1])をプッシュする
     *
     * @param  arg  特に使わず
     */ 
    void div(int arg);

    /**
     * スタックトップを整数で標準出力する
     *
     * @param  arg  特に使わず
     */ 
    void num_out(int arg);

    /**
     * スタックトップを返す。
     *
     * @return  スタックトップ
     */
    int top(void);

    /**
     * スタックトップを取り出して返す。
     *
     * @return  スタックトップ
     */
    int pop(void);

    /**
     * スタックの全要素を削除
     */
    void clear(void);

    /**
     * スタックの要素数を返す
     *
     * @return  スタックの要素数
     */
    int size(void);

private:
    /**
     * コンストラクタ
     *
     * Singleton のため、private で定義
     */
    VM(void);

    /**
     * コピーコンストラクタ
     *
     * Singleton のため、private で定義
     */
    VM(const VM& obj) {}

    /**
     * VM クラスインスタンス
     */
    static VM* _instance;

    /**
     * Operation Set
     */
    typedef void (VM::*opfunc)(int arg);
    map<string, opfunc> opset;

    /**
     * プログラムカウンタ
     */
    unsigned int _pc;

    /**
     * スタック
     */
    vector<int> _stack;
};

#endif // _TYTHON_VM_H_
