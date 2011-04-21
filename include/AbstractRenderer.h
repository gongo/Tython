// -*- C++ -*-

#ifndef _TYTHON_ABSTRACT_RENDERER_H_
#define _TYTHON_ABSTRACT_RENDERER_H_

#include <XnCppWrapper.h>
#include <Glut/glut.h>
#include "User.h"
#include "Vector.h"

class AbstractRenderer {
public:
    AbstractRenderer(xn::Context *ctx, User* _user);
    virtual ~AbstractRenderer(void);
    void draw(void);
protected:
    User* user;
    xn::DepthGenerator* depthGenerator;
    xn::DepthMetaData* depthMeta;
    xn::SceneMetaData* sceneMeta;
private:
    int width;
    int height;
    int texWidth;
    int texHeight;
    GLuint texID;
    Vector* depthBuf;
    unsigned char* sceneBuf;
};

#endif // _TYTHON_ABSTRACT_RENDERER_H_
