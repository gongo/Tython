// -*- C++ -*-

#ifndef _TYTHON_WORLD_CONTEXT_H_
#define _TYTHON_WORLD_CONTEXT_H_

#include <XnCppWrapper.h>

namespace ty {

class WorldContext {
public:
    /**
     * コンストラクタ
     */
    WorldContext(xn::Context* _ctx);

    /**
     * デストラクタ
     */
    virtual ~WorldContext(void);

    /**
     * xn::DepthGenerator インスタンスを返す
     *
     * @return xn::DepthGenerator インスタンスポインタ
     */
    xn::DepthGenerator* depthGenerator(void);

    /**
     * xn::ImageGenerator インスタンスを返す
     *
     * @return xn::ImageGenerator インスタンスポインタ
     */
    xn::ImageGenerator* imageGenerator(void);

    /**
     * 深度データを返す
     */
    const XnDepthPixel* depthData(void) const;

    /**
     * 画面の横ピクセル数を返す
     *
     * @return 画面の横ピクセル数
     */
    XnUInt32 screenWidth(void) const;    

    /**
     * 画面の縦ピクセル数を返す
     *
     * @return 画面の縦ピクセル数
     */
    XnUInt32 screenHeight(void) const;    

    /**
     * @brief 画面周りの初期化
     *
     * xn::Context, xn::DepthGenerator, xn::ImageGenerator の初期化
     */
    void updateDepth(void);

protected:
    /**
     * @brief OpenNI 初期化
     *
     * xn::Context, xn::DepthGenerator, xn::ImageGenerator の初期化
     */
    void initXN(void);

private:
    /**
     * xn::Context インスタンス
     */
    xn::Context* ctxGlobal;

    /**
     * xn::DepthGenerator インスタンス
     */
    xn::DepthGenerator ctxDepth;

    /**
     * xn::ImageGenerator インスタンス
     */
    xn::ImageGenerator ctxImage;

    /**
     * xn::DepthMetaData インスタンス
     */
    xn::DepthMetaData metaDepth;
};

} // namespace ty

#endif // _TYTHON_WORLD_CONTEXT_H_
