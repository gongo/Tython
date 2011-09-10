#include "WorldContext.h"
#include "util.h"

namespace ty {

WorldContext::WorldContext(xn::Context *_ctx) : ctxGlobal(_ctx)
{
    // create Generator
    ty::xnRuntimeCheck(ctxGlobal->FindExistingNode(XN_NODE_TYPE_IMAGE, ctxImage));
    ty::xnRuntimeCheck(ctxGlobal->FindExistingNode(XN_NODE_TYPE_DEPTH, ctxDepth));
    
    // 深度データを、RGB データに調整して取得する
    ty::xnRuntimeCheck(ctxDepth.GetAlternativeViewPointCap().SetViewPoint(ctxImage));

    updateDepth();
}

WorldContext::~WorldContext(void)
{
}

void WorldContext::updateDepth(void)
{
    ctxDepth.GetMetaData(metaDepth);
}

xn::DepthGenerator* WorldContext::depthGenerator(void)
{
    return &ctxDepth;
}

xn::ImageGenerator* WorldContext::imageGenerator(void)
{
    return &ctxImage;
}

XnUInt32 WorldContext::screenWidth(void) const
{
    return metaDepth.XRes();
}

XnUInt32 WorldContext::screenHeight(void) const
{
    return metaDepth.YRes();
}

const XnDepthPixel* WorldContext::depthData(void) const
{
    return metaDepth.Data();
}

} // namespace ty
