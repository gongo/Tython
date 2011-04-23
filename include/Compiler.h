// -*- C++ -*-

#ifndef _TYTHON_COMPILER_H_
#define _TYTHON_COMPILER_H_

#include <string>
#include <stack>
#include <vector>
#include "Instruction.h"

using std::string;
using std::stack;

class Compiler {
public:
    /**
     * Compiler インスタンスを返す
     *
     * @return  Compiler インスタンス
     */
    static Compiler* instance(void);

    /**
     * コンパイル
     *
     * @param   sourceCode  コンパイルするコード
     * @return              コンパイルに成功した場合 true / 失敗した場合 false
     */
    bool compile(string sourceCode);

    /**
     * target が str[index] から全文字含まれているか調べる
     *
     * <code>
     * Compiler object = Compiler::instance();
     * object->scan("aiueo", "aiu", 0); // -> 4
     * object->scan("aiueo", "iu",  0); // -> 0
     * object->scan("aiueo", "iu",  1); // -> 4
     * </code>
     *
     * @param   str     検索対象文字列
     * @param   target  検索する文字列
     * @param   index   検索開始する str の位置
     * @return          target が見つかった場合、target の最後の文字 + 1に位置する str のインデックス
     *                  見つからなければ index
     */
    int scan(string str, string target, int index);

    /**
     * str[index] から、指定された区切り文字までの間にある文字を
     * 2進数として認識し、その値を返す
     *
     * インデックスはこのメソッド内で更新される
     *
     * @todo 区切り文字とか、2進数変換用文字をちゃんと定義しなきゃ
     *
     * <code>
     * // a = 1, @ = 0, g = 区切り文字とする
     *
     * Compiler object = Compiler::instance();
     * object->input("a@a@g",  0); // -> (1010)2 = 10
     * object->input("a@a@g",  2); // -> (10)2 = 10
     * object->input("aag@@a", 0); // -> (11)2 = 3
     * object->input("aaaa", 0);   // -> throw "区切り文字がない"
     * </code>
     *
     * @param  str    解析対象文字列
     * @param  index  解析開始インデックス
     * @retrun        解析された値
     * @throw 
     */
    int input(string str, int &index);

    /**
     * スタックの 1 番目と 2 番目を入れ替える
     */ 
    void swap(void);

    Instruction* op(string str, int arg);

    /**
     * スタック
     */
    stack<int> _stack;

private:
    /**
     * コンストラクタ
     *
     * Singleton のため、private で定義
     */
    Compiler(void) {}

    /**
     * コピーコンストラクタ
     *
     * Singleton のため、private で定義
     */
    Compiler(const Compiler& obj) {}

    /**
     * Compiler クラスインスタンス
     */
    static Compiler* _instance;

    /**
     * コンパイラが扱える文字群
     */
    static string _treat;
};

#endif // _TYTHON_COMPILER_H_
