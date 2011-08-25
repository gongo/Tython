// -*- C++ -*-

#ifndef _TYTHON_ABSTRACT_INPUT_METHOD_H_
#define _TYTHON_ABSTRACT_INPUT_METHOD_H_

#include <map>
#include <vector>
#include "AbstractDetector.h"

using std::map;
using std::vector;

typedef map<int, AbstractDetector*> IMmap;
typedef vector<AbstractDetector*> IMquit;

class AbstractInputMethod {
public:

    AbstractInputMethod(void);
    virtual ~AbstractInputMethod(void);

    /**
     * ソースコード入力する Detector と対応するソースコードの map を返す
     */
    IMmap input(void);
    
    /**
     * ソースコード入力を終了する Detector  のリスト
     */
    IMquit quit(void);

protected:
    /**
     * ソースコード入力する Detector と対応するソースコードの map
     */
    IMmap inputList;

    /**
     * ソースコード入力を終了する Detector  のリスト
     */
    IMquit quitList;
};

#endif // _TYTHON_ABSTRACT_INPUT_METHOD_H_
