// -*- C++ -*-

#ifndef _TYTHON_COMPILER_H_
#define _TYTHON_COMPILER_H_

#include <string>
#include <stack>

using std::string;

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
     * str から target を検索し、見つかった地点のインデックスを返す
     *
     * @param   str     検索対象文字列
     * @param   target  検索する文字列
     * @param   index   str から検索開始する位置
     * @return          target が見つかった場合、target の最後の文字に位置する str のインデックス
     *                  見つからなければ index
     */
    int scan(string str, string target, int index);
    
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

    /**
     * スタック
     */
    //    static std::stack<int> _stack;
};

#endif // _TYTHON_COMPILER_H_
