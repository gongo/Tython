// -*- C++ -*-

#ifndef _TYTHON_ABSTRACT_RENDERER_H_
#define _TYTHON_ABSTRACT_RENDERER_H_

#include <XnCppWrapper.h>
#include <Glut/glut.h>
#include "User.h"
#include "WorldContext.h"
#include "Vector.h"

class AbstractRenderer {
public:
    AbstractRenderer(ty::WorldContext *ctx, ty::User* _user);
    virtual ~AbstractRenderer(void);
    void draw(void);
protected:
    ty::User* user;
    ty::WorldContext* ctx;
    xn::SceneMetaData* sceneMeta;
private:
    int width;
    int height;
    int texWidth;
    int texHeight;
    GLuint texID;
    unsigned char* sceneBuf;
};

#endif // _TYTHON_ABSTRACT_RENDERER_H_
