// -*- C++ -*-

#ifndef _TYTHON_ABSTRACT_RENDERER_H_
#define _TYTHON_ABSTRACT_RENDERER_H_

#include <XnCppWrapper.h>
#include <opencv2/opencv.hpp>
#include "User.h"
#include "WorldContext.h"
#include "Vector.h"

class AbstractRenderer {
public:
    AbstractRenderer(ty::WorldContext *ctx, ty::User* _user);
    virtual ~AbstractRenderer(void);
    void draw(void);
protected:
    ty::WorldContext* ctx;
    ty::User* user;
private:
    cv::Ptr<IplImage> camera;
};

#endif // _TYTHON_ABSTRACT_RENDERER_H_
