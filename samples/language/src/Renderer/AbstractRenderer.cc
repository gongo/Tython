#include "AbstractRenderer.h"
#include "util.h"

AbstractRenderer::AbstractRenderer(ty::Camera *_ctx, ty::User* _user)
    : ctx(_ctx), user(_user)
{
    XnMapOutputMode outputMode;
    ctx->imageGenerator()->GetMapOutputMode(outputMode);
    camera = ::cvCreateImage(cvSize(outputMode.nXRes, outputMode.nYRes),
                             IPL_DEPTH_8U, 3);
    if (!camera) {
        throw std::runtime_error( "error : cvCreateImage" );
    }
}

AbstractRenderer::~AbstractRenderer(void)
{
}

void AbstractRenderer::draw(void)
{
    ctx->updateImage();
    ctx->updateDepth();

    xn::ImageMetaData imageMD;
    ctx->imageGenerator()->GetMetaData(imageMD);

    char* dest = camera->imageData;
    const xn::RGB24Map& rgb =  ctx->imageRGB24Map();
    const XnLabel* label = user->scene()->Data();

    for (int y = 0; y < ctx->imageHeight(); ++y) {
        for (int x = 0; x < ctx->imageWidth(); ++x) {
            XnRGB24Pixel pixel = rgb(x, y);

            if (label[y*ctx->imageWidth() + x]) {
                dest[0] = 255;
                dest[1] = 0;
                dest[2] = 0; 
            } else {
                dest[0] = pixel.nRed;
                dest[1] = pixel.nGreen;
                dest[2] = pixel.nBlue;
            }
            dest += 3;
        }
    }

    ::cvCvtColor(camera, camera, CV_BGR2RGB);
    ::cvShowImage("KinectImage", camera);
}
