#include <gmock/gmock.h>
#include "ThanksCommandDetector.h"
#include "MockUser.h"
#include "MockVector.h"

using ::testing::Return;

class ThanksCommandDetectorTest : public testing::Test {
public:
    virtual void SetUp() {
        mock = new MockUser;
        object = new ThanksCommandDetector(mock);
    }    

    virtual void TearDown() {
        delete object;
        delete mock;
    }
protected:
    ThanksCommandDetector* object;
    MockUser* mock;
};

TEST_F(ThanksCommandDetectorTest, TestIsPosing) {
    EXPECT_CALL(*mock, positionNeck())
        .WillRepeatedly(Return(Vector(0.0f, 1.0f, 0.0f)));
    EXPECT_CALL(*mock, positionWaist())
        .WillRepeatedly(Return(Vector(0.0f, -1.0f, 0.0f)));
    EXPECT_CALL(*mock, positionRightHand())
        .WillOnce(Return(Vector(-1.0f, 0.5f, 0.0f)))
        .WillOnce(Return(Vector(1.0f, -1.5f, 0.0f)));
    EXPECT_CALL(*mock, positionLeftHand())
        .WillOnce(Return(Vector(1.0f, 0.5f, 0.0f)))
        .WillOnce(Return(Vector(-1.0f, -1.5f, 0.0f)));

    EXPECT_CALL(*mock, skeletonRightUpperArm())
        .WillOnce(Return(MockVector::v45*-1));
    EXPECT_CALL(*mock, skeletonLeftUpperArm())
        .WillOnce(Return(MockVector::v135*-1));
    EXPECT_CALL(*mock, skeletonRightForearm())
        .WillOnce(Return(MockVector::v45))
        .WillOnce(Return(MockVector::v45*-1));
    EXPECT_CALL(*mock, skeletonLeftForearm())
        .WillOnce(Return(MockVector::v135))
        .WillOnce(Return(MockVector::v135*-1));

    ASSERT_FALSE(object->isPosing());
    ASSERT_TRUE(object->isPosing());
}

TEST_F(ThanksCommandDetectorTest, TestIsPosingError) {
    EXPECT_CALL(*mock, positionNeck()).WillRepeatedly(Return(Vector()));
    EXPECT_CALL(*mock, positionWaist()).WillRepeatedly(Return(Vector()));
    EXPECT_CALL(*mock, positionRightHand()).WillRepeatedly(Return(Vector()));
    EXPECT_CALL(*mock, positionLeftHand()).WillRepeatedly(Return(Vector()));
    EXPECT_CALL(*mock, skeletonRightForearm()).WillRepeatedly(Return(Vector()));
    EXPECT_CALL(*mock, skeletonLeftForearm()).WillRepeatedly(Return(Vector()));
    
    ASSERT_FALSE(object->isPosing());
    ASSERT_FALSE(object->isPosing());
}
