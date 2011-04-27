#include <gtest/gtest.h>
#include "RightStraightCommandDetector.h"
#include "MockUser.h"

using ::testing::Return;

class RightStraightCommandDetectorTest : public testing::Test {
public:
    virtual void SetUp() {
        mock = new MockUser;
        object = new RightStraightCommandDetector(mock);
    }    

    virtual void TearDown() {
        delete object;
        delete mock;
    }
protected:
    RightStraightCommandDetector* object;
    MockUser* mock;
};

TEST_F(RightStraightCommandDetectorTest, TestIsPosing) {
    EXPECT_CALL(*mock, positionRightShoulder())
        .WillRepeatedly(Return(Vector(0.0f, 1.0f, 0.0f)));
    EXPECT_CALL(*mock, positionRightElbow())
        .WillRepeatedly(Return(Vector(0.0f, 1.0f, 0.0f)));
    EXPECT_CALL(*mock, positionRightHand())
        .WillRepeatedly(Return(Vector(0.0f, 3.0f, 0.0f)));
    EXPECT_CALL(*mock, skeletonRightUpperArm())
        .Times(3)
        .WillRepeatedly(Return(Vector(1.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*mock, skeletonRightForearm())
        .Times(3)
        .WillOnce(Return(Vector(-1.0f, 1.73205081f, 0.0f)))
        .WillOnce(Return(Vector(1.0f, 0.0f, 0.0f)))
        .WillOnce(Return(Vector(-1.0f, 1.73205081f, 0.0f))); 

    ASSERT_FALSE(object->isPosing());
    ASSERT_FALSE(object->isPosing());
    ASSERT_TRUE(object->isPosing());
}

TEST_F(RightStraightCommandDetectorTest, TestIsPosingError) {
    EXPECT_CALL(*mock, positionRightShoulder())
        .WillRepeatedly(Return(Vector(0.0f, 1.0f, 0.0f)));
    EXPECT_CALL(*mock, positionRightElbow())
        .WillRepeatedly(Return(Vector(0.0f, 1.0f, 0.0f)));
    EXPECT_CALL(*mock, positionRightHand())
        .WillRepeatedly(Return(Vector(0.0f, 3.0f, 0.0f)));
    EXPECT_CALL(*mock, skeletonRightUpperArm())
        .Times(3)
        .WillRepeatedly(Return(Vector(1.0f, 0.0f, 0.0f)));
    EXPECT_CALL(*mock, skeletonRightForearm())
        .Times(3)
        .WillOnce(Return(Vector(0.34f, 0.93f, 0.0f)))
        .WillOnce(Return(Vector(1.0f, 1.0f, 0.0f)))
        .WillOnce(Return(Vector(0.34f, 0.93f, 0.0f)));
    
    ASSERT_FALSE(object->isPosing());
    ASSERT_FALSE(object->isPosing());
     ASSERT_FALSE(object->isPosing());
}


TEST_F(RightStraightCommandDetectorTest, TestIsPosingError2) {
    EXPECT_CALL(*mock, positionRightShoulder()).WillRepeatedly(Return(Vector(0.0f, 1.0f, 0.0f)));
    EXPECT_CALL(*mock, positionRightElbow()).WillRepeatedly(Return(Vector(0.0f, 1.0f, 0.0f)));
    EXPECT_CALL(*mock, positionRightHand()).WillRepeatedly(Return(Vector(0.0f, 3.0f, 0.0f)));
    EXPECT_CALL(*mock, skeletonRightUpperArm())
        .Times(3).WillRepeatedly(Return(Vector(200.953506f, 67.914108f, 141.129761f)));
    EXPECT_CALL(*mock, skeletonRightForearm())
        .Times(3).WillRepeatedly(Return(Vector(251.230759f, -81.023232f, 91.788452f)));
  
    ASSERT_FALSE(object->isPosing());
    ASSERT_FALSE(object->isPosing());
    ASSERT_FALSE(object->isPosing());
}

