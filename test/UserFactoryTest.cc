#include <gtest/gtest.h>
#include <stdexcept>
#include <limits.h>
#include "UserFactory.h"

class UserFactoryTest : public ::testing::Test {
public:
    virtual void SetUp() {
        context.Init();
        context.OpenFileRecording("./test/oni/depth_only.oni", player);
        player.SetRepeat(false);
        factory = new ty::UserFactory(context);
        context.StartGeneratingAll();
        while (!player.IsEOF()) { context.WaitAndUpdateAll(); }
    }

    virtual void TearDown() {
        context.StopGeneratingAll();
        delete factory;
        player.Release();
        context.Release();
    }

protected:
    ty::UserFactory *factory;
    xn::Context context;
    xn::Player player;
};

TEST_F(UserFactoryTest, TestGet) {
    int id;

    id = 1;
    ASSERT_EQ(id, factory->get(id)->id());

    id = ty::UserFactory::MAX;
    ASSERT_EQ(id, factory->get(id)->id());

    id = (1 + ty::UserFactory::MAX)/2;
    ASSERT_EQ(id, factory->get(id)->id());
}

TEST_F(UserFactoryTest, TestGetThrowException) {
    ASSERT_THROW(factory->get(-1), std::out_of_range);
    ASSERT_THROW(factory->get(0), std::out_of_range);
    ASSERT_THROW(factory->get(ty::UserFactory::MAX + 1), std::out_of_range);
    ASSERT_THROW(factory->get(INT_MAX), std::out_of_range);
}
