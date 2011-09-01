#include <gtest/gtest.h>
#include "LeftJabCommandDetector.h"
#include "MockUser.h"
#include "MockVector.h"

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

#define SET_SKELETON_CALL() do {                                \
        EXPECT_CALL(*mock, positionLeftShoulder())              \
            .WillRepeatedly(Return(Vector(0.0f, 1.0f, 0.0f)));  \
        EXPECT_CALL(*mock, positionLeftElbow())                 \
            .WillRepeatedly(Return(Vector(0.0f, 1.0f, 0.0f)));  \
        EXPECT_CALL(*mock, positionLeftHand())                  \
            .WillRepeatedly(Return(Vector(0.0f, 3.0f, 0.0f)));  \
    } while (0)

TEST_F(LeftJabCommandDetectorTest, TestIsStand) {
    SET_SKELETON_CALL();
    EXPECT_CALL(*mock, leftArmIsBentRightAngle()).WillOnce(Return(true));    
    ASSERT_TRUE(object->isStand());
}

TEST_F(LeftJabCommandDetectorTest, TestIsStandError) {
    SET_SKELETON_CALL();
    EXPECT_CALL(*mock, leftArmIsBentRightAngle()).WillOnce(Return(false));
    ASSERT_FALSE(object->isStand());
}

TEST_F(LeftJabCommandDetectorTest, TestIsLeftJab) {
    SET_SKELETON_CALL();
    EXPECT_CALL(*mock, leftArmIsStraight()).WillOnce(Return(true));
    ASSERT_TRUE(object->isLeftJab());
}

TEST_F(LeftJabCommandDetectorTest, TestIsLeftJabError) {
    SET_SKELETON_CALL();
    EXPECT_CALL(*mock, leftArmIsStraight()).WillOnce(Return(false));
    ASSERT_FALSE(object->isLeftJab());
}
