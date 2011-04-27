#include <gtest/gtest.h>
#include "LeftJabCommandDetector.h"
#include "MockUser.h"

using ::testing::Return;

class LeftJabCommandDetectorTest : public testing::Test {
public:
    virtual void SetUp() {
        mock = new MockUser;
        object = new LeftJabCommandDetector(mock);
    }    

    virtual void TearDown() {
        delete object;
        delete mock;
    }
protected:
    LeftJabCommandDetector* object;
    MockUser* mock;
};

TEST_F(LeftJabCommandDetectorTest, TestIsPosing) {
    EXPECT_CALL(*mock, positionLeftShoulder())
        .WillRepeatedly(Return(Vector(0.0f, 1.0f, 0.0f)));
    EXPECT_CALL(*mock, positionLeftElbow())
        .WillRepeatedly(Return(Vector(0.0f, 1.0f, 0.0f)));
    EXPECT_CALL(*mock, positionLeftHand())
        .WillRepeatedly(Return(Vector(0.0f, 3.0f, 0.0f)));
    EXPECT_CALL(*mock, skeletonLeftUpperArm())
        .Times(3)
        .WillRepeatedly(Return(Vector(1.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*mock, skeletonLeftForearm())
        .Times(3)
        .WillOnce(Return(Vector(0.0f, 1.0f, 0.0f)))
        .WillOnce(Return(Vector(0.0f, 0.0f, 0.0f)))
        .WillOnce(Return(Vector(0.0f, 1.0f, 0.0f)));
    
    ASSERT_FALSE(object->isPosing());
    ASSERT_FALSE(object->isPosing());
    ASSERT_TRUE(object->isPosing());
}

TEST_F(LeftJabCommandDetectorTest, TestIsPosingError) {
    EXPECT_CALL(*mock, positionLeftShoulder())
        .WillRepeatedly(Return(Vector(0.0f, 1.0f, 0.0f)));
    EXPECT_CALL(*mock, positionLeftElbow())
        .WillRepeatedly(Return(Vector(0.0f, 1.0f, 0.0f)));
    EXPECT_CALL(*mock, positionLeftHand())
        .WillRepeatedly(Return(Vector(0.0f, 3.0f, 0.0f)));
    EXPECT_CALL(*mock, skeletonLeftUpperArm())
        .Times(3)
        .WillRepeatedly(Return(Vector(0.0f, 1.0f, 0.0f)));
    EXPECT_CALL(*mock, skeletonLeftForearm())
        .Times(3)
        .WillOnce(Return(Vector(1.0f, 0.0f, 0.0f)))
        .WillOnce(Return(Vector(1.0f, 1.0f, 0.0f)))
        .WillOnce(Return(Vector(1.0f, 0.0f, 0.0f)));
    
    ASSERT_FALSE(object->isPosing());
    ASSERT_FALSE(object->isPosing());
    ASSERT_FALSE(object->isPosing());
}
