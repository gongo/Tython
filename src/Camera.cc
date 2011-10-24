#include "Camera.h"
#include "util.h"

namespace ty {

Camera::Camera(xn::Context *_ctx, const int nodeType) : ctxGlobal(_ctx)
{
    if (nodeType & NODE_USE_IMAGE) {
        xnRuntimeCheck(ctxGlobal->FindExistingNode(XN_NODE_TYPE_IMAGE, ctxImage));
    }

    if (nodeType & NODE_USE_DEPTH) {
        xnRuntimeCheck(ctxGlobal->FindExistingNode(XN_NODE_TYPE_DEPTH, ctxDepth));
    }

    if (ctxDepth.IsValid()
        && ctxDepth.IsCapabilitySupported(XN_CAPABILITY_ALTERNATIVE_VIEW_POINT)
        && ctxImage.IsValid()) {
        xnRuntimeCheck(ctxDepth.GetAlternativeViewPointCap().SetViewPoint(ctxImage));
    }

    updateDepth();
    updateImage();
}

Camera::~Camera(void)
{
    ctxImage.Release();
    ctxDepth.Release();
}

void Camera::updateDepth(void)
{
    if (ctxDepth.IsValid()) {
        ctxDepth.GetMetaData(metaDepth);
    }
}

void Camera::updateImage(void)
{
    if (ctxImage.IsValid()) {
        ctxImage.GetMetaData(metaImage);
    }
}

xn::DepthGenerator* Camera::depthGenerator(void)
{
    return &ctxDepth;
}

xn::ImageGenerator* Camera::imageGenerator(void)
{
    return &ctxImage;
}

XnUInt32 Camera::imageWidth(void) const
{
    return metaImage.XRes();
}

XnUInt32 Camera::imageHeight(void) const
{
    return metaImage.YRes();
}

XnUInt32 Camera::depthWidth(void) const
{
    return metaDepth.XRes();
}

XnUInt32 Camera::depthHeight(void) const
{
    return metaDepth.YRes();
}

const XnDepthPixel* Camera::depthData(void) const
{
    return metaDepth.Data();
}

const xn::RGB24Map& Camera::imageRGB24Map(void) const
{
    return metaImage.RGB24Map();
}

void Camera::enableRecord(const XnChar* recordFileName)
{
    xnRuntimeCheck(ctxRecorder.Create(*ctxGlobal));
    xnRuntimeCheck(ctxRecorder.SetDestination(XN_RECORD_MEDIUM_FILE, recordFileName));

    if (ctxImage.IsValid()) {
        xnRuntimeCheck(ctxRecorder.AddNodeToRecording(ctxImage, XN_CODEC_NULL));
    }

    if (ctxDepth.IsValid()) {
        xnRuntimeCheck(ctxRecorder.AddNodeToRecording(ctxDepth, XN_CODEC_NULL));
    }

    xnRuntimeCheck(ctxRecorder.Record());
}

} // namespace ty
