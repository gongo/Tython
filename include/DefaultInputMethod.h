// -*- C++ -*-

#ifndef _TYTHON_DEFAULT_INPUT_METHOD_H_
#define _TYTHON_DEFAULT_INPUT_METHOD_H_

#include "AbstractInputMethod.h"

class DefaultInputMethod : public AbstractInputMethod {
public:
    DefaultInputMethod(void);
    DefaultInputMethod(User* _user);
};

#endif // _TYTHON_DEFAULT_INPUT_METHOD_H_
