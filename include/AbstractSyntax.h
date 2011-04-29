// -*- C++ -*-

#ifndef _TYTHON_ABSTRACT_SYNTAX_H_
#define _TYTHON_ABSTRACT_SYNTAX_H_

#include <map>
#include <vector>
#include <string>
#include "AbstractDetector.h"

using std::map;
using std::vector;
using std::string;

typedef map<string, AbstractDetector*> SyntaxInput;
typedef vector<AbstractDetector*> SyntaxQuit;

class AbstractSyntax {
public:
    AbstractSyntax(void);
    virtual ~AbstractSyntax(void);

    /**
     * ソースコード入力する Detector と対応するソースコードの map を返す
     */
    map<string, AbstractDetector*> input(void);

    /**
     * ソースコード入力を終了する Detector  のリスト
     */
    SyntaxQuit quit(void);

protected:
    /**
     * ソースコード入力する Detector と対応するソースコードの map
     */
    map<string, AbstractDetector*> inputList;

    /**
     * ソースコード入力を終了する Detector  のリスト
     */
    SyntaxQuit quitList;
};

#endif // _TYTHON_ABSTRACT_SYNTAX_H_
