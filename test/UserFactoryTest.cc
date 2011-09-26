#include <gtest/gtest.h>
#include <stdexcept>
#include "UserFactory.h"

TEST(UserFactoryTest, TestSetAndDeleteContext) {
    xn::Context context;
    xn::Player player;
    ty::User *user;

    // Init
    context.Init();
    context.OpenFileRecording("./test/oni/depth_only.oni", player);
    player.SetRepeat(false);
    ty::UserFactory::setContext(&context);

    // Play
    context.StartGeneratingAll();
    while (!player.IsEOF()) { context.WaitAndUpdateAll(); }

    user = ty::UserFactory::get(1);
    ASSERT_EQ(1, user->id());

    // Stop
    context.StopGeneratingAll();
    
    // Release
    ty::UserFactory::deleteContext();
    player.Release();
    context.Release();
}

TEST(UserFactoryTest, TestGetThrowException) {
    ASSERT_THROW(ty::UserFactory::get(0), std::out_of_range);
    ASSERT_THROW(ty::UserFactory::get(ty::UserFactory::MAX + 1), std::out_of_range);

    ASSERT_NO_THROW(ty::UserFactory::get(1));
    ASSERT_NO_THROW(ty::UserFactory::get(ty::UserFactory::MAX));
}
