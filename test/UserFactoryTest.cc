#include <gtest/gtest.h>
#include <stdexcept>
#include "UserFactory.h"

class UserFactoryTest : public testing::Test {
public:
protected:
    virtual void SetUp() {
    }
};

TEST_F(UserFactoryTest, TestGetThrowException) {
    ASSERT_THROW(ty::UserFactory::get(0), std::out_of_range);
    ASSERT_THROW(ty::UserFactory::get(ty::UserFactory::MAX + 1), std::out_of_range);

    ASSERT_NO_THROW(ty::UserFactory::get(1));
    ASSERT_NO_THROW(ty::UserFactory::get(ty::UserFactory::MAX));
}
