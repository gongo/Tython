#include <gtest/gtest.h>
#include <stdexcept>
#include "WorldContext.h"

#define ONI_INIT(onifile) do {                          \
        context.Init();                                 \
        context.OpenFileRecording(onifile, player);     \
        player.SetRepeat(false);                        \
    } while (0)

#define ONI_FINISH() do {   \
        player.Release();   \
        context.Release();  \
    } while (0)
    

TEST(WorldContextTest, TestDepth) {
    xn::Context context;
    xn::Player player;
    ty::WorldContext *world;

    ONI_INIT("./test/oni/depth_only.oni");

    ASSERT_NO_THROW(world = new ty::WorldContext(&context,
                                                 ty::WorldContext::NODE_USE_DEPTH));
    ASSERT_EQ(640, (int)world->depthWidth());
    ASSERT_EQ(480, (int)world->depthHeight());

    ONI_FINISH();
}

TEST(WorldContextTest, TestImage) {
    xn::Context context;
    xn::Player player;
    ty::WorldContext *world;

    ONI_INIT("./test/oni/image_only.oni");

    ASSERT_NO_THROW(world = new ty::WorldContext(&context,
                                                 ty::WorldContext::NODE_USE_IMAGE));
    ASSERT_EQ(640, (int)world->imageWidth());
    ASSERT_EQ(480, (int)world->imageHeight());

    ONI_FINISH();
}

TEST(WorldContextTest, TestDepthAndImage) {
    xn::Context context;
    xn::Player player;

    ONI_INIT("./test/oni/image_depth.oni");
    ASSERT_NO_THROW(ty::WorldContext world(&context,
                                           ty::WorldContext::NODE_USE_IMAGE |
                                           ty::WorldContext::NODE_USE_DEPTH));
    ONI_FINISH();
}

TEST(WorldContextTest, TestImageFailure) {
    xn::Context context;
    xn::Player player;

    ONI_INIT("./test/oni/depth_only.oni");
    ASSERT_THROW(ty::WorldContext world(&context,
                                        ty::WorldContext::NODE_USE_IMAGE |
                                        ty::WorldContext::NODE_USE_DEPTH),
                 std::runtime_error);
    ONI_FINISH();
}

TEST(WorldContextTest, TestDepthFailure) {
    xn::Context context;
    xn::Player player;

    ONI_INIT("./test/oni/image_only.oni");
    ASSERT_THROW(ty::WorldContext world(&context,
                                    ty::WorldContext::NODE_USE_IMAGE |
                                    ty::WorldContext::NODE_USE_DEPTH),
                 std::runtime_error);
    ONI_FINISH();
}

// TEST(UserFactoryTest, TestGetThrowException) {
//     ASSERT_THROW(ty::UserFactory::get(0), std::out_of_range);
//     ASSERT_THROW(ty::UserFactory::get(ty::UserFactory::MAX + 1), std::out_of_range);

//     ASSERT_NO_THROW(ty::UserFactory::get(1));
//     ASSERT_NO_THROW(ty::UserFactory::get(ty::UserFactory::MAX));
// }
