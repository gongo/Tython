#include <gtest/gtest.h>
#include <stdexcept>
#include "UserFactory.h"

class UserFactoryTest : public ::testing::TestWithParam<int> {
public:
    virtual void SetUp() {
        context.Init();
        context.OpenFileRecording("./test/oni/depth_only.oni", player);
        player.SetRepeat(false);
        factory = new ty::UserFactory(&context);
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

class UserFactoryFailureTest : public UserFactoryTest {
};


TEST_P(UserFactoryTest, TestGet) {
    ASSERT_EQ(GetParam(), factory->get(GetParam())->id());
}

INSTANTIATE_TEST_CASE_P(ValidId,
                        UserFactoryTest,
                        testing::Values(1,
                                        ty::UserFactory::MAX,
                                        (1 + ty::UserFactory::MAX)/2));

TEST_P(UserFactoryFailureTest, TestGetThrowException) {
    ASSERT_THROW(factory->get(GetParam()), std::out_of_range);
}

INSTANTIATE_TEST_CASE_P(InvalidId,
                        UserFactoryFailureTest,
                        testing::Values(-1, 0, ty::UserFactory::MAX + 1, INT_MAX));
