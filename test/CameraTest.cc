#include <gtest/gtest.h>
#include <stdexcept>
#include "Camera.h"

#define ONI_INIT(onifile) do {                          \
        context.Init();                                 \
        context.OpenFileRecording(onifile, player);     \
        player.SetRepeat(false);                        \
    } while (0)

#define ONI_FINISH() do {   \
        player.Release();   \
        context.Release();  \
    } while (0)


TEST(CameraTest, TestDepth) {
    xn::Context context;
    xn::Player player;
    ty::Camera *camera;

    ONI_INIT("./test/oni/depth_only.oni");

    ASSERT_NO_THROW(camera = new ty::Camera(&context, ty::Camera::USE_DEPTH));
    ASSERT_EQ(640, (int)camera->depthWidth());
    ASSERT_EQ(480, (int)camera->depthHeight());

    ONI_FINISH();
}

TEST(CameraTest, TestImage) {
    xn::Context context;
    xn::Player player;
    ty::Camera *camera;

    ONI_INIT("./test/oni/image_only.oni");

    ASSERT_NO_THROW(camera = new ty::Camera(&context, ty::Camera::USE_IMAGE));
    ASSERT_EQ(640, (int)camera->imageWidth());
    ASSERT_EQ(480, (int)camera->imageHeight());

    ONI_FINISH();
}

TEST(CameraTest, TestDepthAndImage) {
    xn::Context context;
    xn::Player player;

    ONI_INIT("./test/oni/image_depth.oni");
    ASSERT_NO_THROW(ty::Camera camera(&context,
                                      ty::Camera::USE_IMAGE | ty::Camera::USE_DEPTH));
    ONI_FINISH();
}

TEST(CameraTest, TestImageFailure) {
    xn::Context context;
    xn::Player player;

    ONI_INIT("./test/oni/depth_only.oni");
    ASSERT_THROW(ty::Camera camera(&context,
                                   ty::Camera::USE_IMAGE | ty::Camera::USE_DEPTH),
                 std::runtime_error);
    ONI_FINISH();
}

TEST(CameraTest, TestDepthFailure) {
    xn::Context context;
    xn::Player player;

    ONI_INIT("./test/oni/image_only.oni");
    ASSERT_THROW(ty::Camera camera(&context,
                                   ty::Camera::USE_IMAGE | ty::Camera::USE_DEPTH),
                 std::runtime_error);
    ONI_FINISH();
}
