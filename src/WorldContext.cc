#include "WorldContext.h"
#include "util.h"

namespace ty {

WorldContext::WorldContext(xn::Context *_ctx, const int nodeType) : ctxGlobal(_ctx)
{
    if (nodeType & NODE_USE_IMAGE) {
        xnRuntimeCheck(ctxGlobal->FindExistingNode(XN_NODE_TYPE_IMAGE, ctxImage));
    }

    if (nodeType & NODE_USE_DEPTH) {
        xnRuntimeCheck(ctxGlobal->FindExistingNode(XN_NODE_TYPE_DEPTH, ctxDepth));
    }
    
    if (ctxImage.IsValid() && ctxDepth.IsValid()) {
        xnRuntimeCheck(ctxDepth.GetAlternativeViewPointCap().SetViewPoint(ctxImage));
    }

    updateDepth();
}

WorldContext::~WorldContext(void)
{
}

void WorldContext::updateDepth(void)
{
    if (ctxDepth.IsValid()) {
        ctxDepth.GetMetaData(metaDepth);
    }
}

void WorldContext::updateImage(void)
{
    if (ctxImage.IsValid()) {
        ctxImage.GetMetaData(metaImage);
    }
}

xn::DepthGenerator* WorldContext::depthGenerator(void)
{
    return &ctxDepth;
}

xn::ImageGenerator* WorldContext::imageGenerator(void)
{
    return &ctxImage;
}

XnUInt32 WorldContext::imageWidth(void) const
{
    return metaImage.XRes();
}

XnUInt32 WorldContext::imageHeight(void) const
{
    return metaImage.YRes();
}

XnUInt32 WorldContext::depthWidth(void) const
{
    return metaDepth.XRes();
}

XnUInt32 WorldContext::depthHeight(void) const
{
    return metaDepth.YRes();
}

const XnDepthPixel* WorldContext::depthData(void) const
{
    return metaDepth.Data();
}

void WorldContext::enableRecord(const XnChar* recordFileName)
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
