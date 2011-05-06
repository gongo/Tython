// -*- C++ -*-

#ifndef _TYTHON_TYPHON_SYNTAX_H_
#define _TYTHON_TYPHON_SYNTAX_H_

#include "AbstractSyntax.h"

class TyphonSyntax : public AbstractSyntax {
public:
    TyphonSyntax(void);
    TyphonSyntax(User* _user);
};

#endif // _TYTHON_TYPHON_SYNTAX_H_
