// -*- C++ -*-

#ifndef _TYTHON_CONTROLLER_H_
#define _TYTHON_CONTROLLER_H_

#include <XnCppWrapper.h>
#include "User.h"

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
};

#endif // _TYTHON_CONTROLLER_H_
