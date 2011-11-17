#include "Camera.h"
#include "util.h"

namespace ty {

Camera::Camera(xn::Context& _ctx, const int nodeType) : ctxGlobal(_ctx)
{
    if (nodeType & USE_IMAGE) {
        throwRuntimeErrorIf(ctxGlobal.FindExistingNode(XN_NODE_TYPE_IMAGE, ctxImage));
    }

    if (nodeType & USE_DEPTH) {
        throwRuntimeErrorIf(ctxGlobal.FindExistingNode(XN_NODE_TYPE_DEPTH, ctxDepth));
    }

    if (ctxDepth.IsValid()
        && ctxDepth.IsCapabilitySupported(XN_CAPABILITY_ALTERNATIVE_VIEW_POINT)
        && ctxImage.IsValid()) {
        throwRuntimeErrorIf(ctxDepth.GetAlternativeViewPointCap().SetViewPoint(ctxImage));
    }

    update();
}

Camera::~Camera(void)
{
    ctxImage.Release();
    ctxDepth.Release();
}

void Camera::update(void)
{
    updateDepth();
    updateImage();
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
    throwRuntimeErrorIf({
        ctxRecorder.Create(ctxGlobal),
        ctxRecorder.SetDestination(XN_RECORD_MEDIUM_FILE, recordFileName)
    });

    if (ctxImage.IsValid()) {
        throwRuntimeErrorIf(ctxRecorder.AddNodeToRecording(ctxImage, XN_CODEC_NULL));
    }

    if (ctxDepth.IsValid()) {
        throwRuntimeErrorIf(ctxRecorder.AddNodeToRecording(ctxDepth, XN_CODEC_NULL));
    }

    throwRuntimeErrorIf(ctxRecorder.Record());
}

} // namespace ty
