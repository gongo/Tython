// -*- C++ -*-

#ifndef _TYTHON_CONTROLLER_H_
#define _TYTHON_CONTROLLER_H_

#include <XnCppWrapper.h>
#include <string>
#include "User.h"
#include "WorldContext.h"
#include "Compiler.h"
#include "VM.h"
#include "AbstractInputMethod.h"

using std::string;

class Controller {
public:
    Controller(void);
    Controller(const XnChar* recordFileName);
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
    ty::UserContext *ctxUser;

    ty::User *user;

    ty::WorldContext *world;

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

    /**
     * InputMethod 
     */
    AbstractInputMethod* im;
};

#endif // _TYTHON_CONTROLLER_H_
