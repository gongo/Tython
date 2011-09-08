#include <gmock/gmock.h>
#include "ThanksCommandDetector.h"
#include "MockUser.h"
#include "MockVector.h"

using ::testing::Return;

class ThanksCommandDetectorTest : public testing::Test {
public:
    virtual void SetUp() {
        mock = new MockUser;
        object = new ty::ThanksCommandDetector(mock);
    }    

    virtual void TearDown() {
        delete object;
        delete mock;
    }
protected:
    ty::ThanksCommandDetector* object;
    MockUser* mock;
};

TEST_F(ThanksCommandDetectorTest, TestIsPosing) {
    EXPECT_CALL(*mock, neck())
        .WillRepeatedly(Return(ty::Vector(0.0f, 1.0f, 0.0f)));
    EXPECT_CALL(*mock, waist())
        .WillRepeatedly(Return(ty::Vector(0.0f, -1.0f, 0.0f)));
    EXPECT_CALL(*mock, rightHand())
        .WillOnce(Return(ty::Vector(-1.0f, 0.5f, 0.0f)))
        .WillOnce(Return(ty::Vector(1.0f, -1.5f, 0.0f)));
    EXPECT_CALL(*mock, leftHand())
        .WillOnce(Return(ty::Vector(1.0f, 0.5f, 0.0f)))
        .WillOnce(Return(ty::Vector(-1.0f, -1.5f, 0.0f)));

    EXPECT_CALL(*mock, vectorRightUpperArm())
        .WillOnce(Return(MockVector::v225));
    EXPECT_CALL(*mock, vectorLeftUpperArm())
        .WillOnce(Return(MockVector::v315));
    EXPECT_CALL(*mock, vectorRightForearm())
        .WillOnce(Return(MockVector::v45))
        .WillOnce(Return(MockVector::v225));
    EXPECT_CALL(*mock, vectorLeftForearm())
        .WillOnce(Return(MockVector::v135))
        .WillOnce(Return(MockVector::v315));

    ASSERT_FALSE(object->isPosing());
    ASSERT_TRUE(object->isPosing());
}

TEST_F(ThanksCommandDetectorTest, TestIsPosingError) {
    ASSERT_FALSE(object->isPosing());
    ASSERT_FALSE(object->isPosing());
}
