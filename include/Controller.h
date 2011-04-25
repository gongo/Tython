// -*- C++ -*-

#ifndef _TYTHON_CONTROLLER_H_
#define _TYTHON_CONTROLLER_H_

#include <XnCppWrapper.h>
#include <string>
#include "User.h"
#include "Compiler.h"
#include "VM.h"

using std::string;

class Controller {
public:
    Controller(void);
    virtual ~Controller(void);

    void main(void);
protected:

private:
    /**
     * @return void
     */
    void initXN(void);

    /**
     *
     */
    xn::Context ctxGlobal;

    /**
     *
     */
    User *ctxUser;

    /**
     *
     */
    xn::DepthGenerator ctxDepth;

    /**
     * source code
     */
    string source;

    /**
     *
     */
    Compiler *compiler;

    /**
     * VM
     */
    VM* vm;
};

#endif // _TYTHON_CONTROLLER_H_
