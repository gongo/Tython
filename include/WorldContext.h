// -*- C++ -*-

#ifndef _TYTHON_WORLD_CONTEXT_H_
#define _TYTHON_WORLD_CONTEXT_H_

#include <XnCppWrapper.h>

namespace ty {

class WorldContext {
public:
    /**
     * @brief コンストラクタ
     *
     * nodeType で生成する Generator を選択する
     *
     * @code 
     * WorldContext *world = new WorldContext(ctx, NODE_USE_DEPTH | NODE_USE_IMAGE);
     * @endcode
     * 
     * @param  _ctx      Init 済みの xn::Context のインスタンス
     * @param  nodeType  生成するノード
     */
    WorldContext(xn::Context* _ctx, const int nodeType);

    /**
     * @brief デストラクタ
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
     * @brief Image の横ピクセル数を返す
     *
     * Image が登録されていない場合は 0 を返す
     *
     * @return Image の横ピクセル数
     */
    XnUInt32 imageWidth(void) const;    

    /**
     * @brief Image の縦ピクセル数を返す
     *
     * Image が登録されていない場合は 0 を返す
     *
     * @return Image の縦ピクセル数
     */
    XnUInt32 imageHeight(void) const;    

    /**
     * @brief Depth の横ピクセル数を返す
     *
     * Depth が登録されていない場合は 0 を返す
     *
     * @return Depth の横ピクセル数
     */
    XnUInt32 depthWidth(void) const;    

    /**
     * @brief Depth の縦ピクセル数を返す
     *
     * Depth が登録されていない場合は 0 を返す
     *
     * @return Depth の縦ピクセル数
     */
    XnUInt32 depthHeight(void) const;    

    /**
     * @brief Depth Meta Data の更新
     */
    void updateDepth(void);

    /**
     * @brief Image Meta Data の更新
     */
    void updateImage(void);

    /**
     * @brief Recorder を有効化する
     *
     * ImageNode が有効であれば、圧縮形式をノードのデフォルト設定として保存する
     * DepthNode が有効であれば、圧縮形式をノードのデフォルト設定として保存する
     *
     * @param  recordFileName  記録するファイル名
     */
    void enableRecord(const XnChar* recordFileName);

    /**
     * Depth Node を使うフラグ値
     */
    static const int NODE_USE_DEPTH = (1 << 0);

    /**
     * Image Node を使うフラグ値
     */
    static const int NODE_USE_IMAGE = (1 << 1);

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
     * xn::Recorder インスタンス
     */
    xn::Recorder ctxRecorder;

    /**
     * xn::DepthMetaData インスタンス
     */
    xn::DepthMetaData metaDepth;

    /**
     * xn::DepthMetaData インスタンス
     */
    xn::ImageMetaData metaImage;
};

} // namespace ty

#endif // _TYTHON_WORLD_CONTEXT_H_
