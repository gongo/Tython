#include <gmock/gmock.h>
#include "UserContext.h"
#include "WorldContext.h"
#include "util.h"

using ::testing::Return;
using ::testing::Invoke;
using ::testing::_;

class MockUserContext : public ty::UserContext {
public:
    MockUserContext(xn::Context *context) : ty::UserContext(context) {}

    MOCK_METHOD1(onNewUser, void(XnUserID));
    MOCK_METHOD1(onPoseStart, void(XnUserID));
    MOCK_METHOD1(onCalibrationStart, void(XnUserID));
    MOCK_METHOD2(onCalibrationEnd, void(XnUserID, bool));

    void fakeOnNewUser(XnUserID uid) {
        ty::UserContext::onNewUser(uid);
    }
    void fakeOnPoseStart(XnUserID uid) {
        ty::UserContext::onPoseStart(uid);
    }
    void fakeOnCalibrationStart(XnUserID uid) {
        ty::UserContext::onCalibrationStart(uid);
    }
    void fakeOnCalibrationEnd(XnUserID uid, bool isCalibration) {
        ty::UserContext::onCalibrationEnd(uid, isCalibration);
    }
};

class UserContextTest : public testing::Test {
public:
    virtual void SetUp() {
        context.Init();
    }    

    virtual void TearDown() {
        context.Release();
    }

protected:
    xn::Context context;
    xn::Player player;
};

#define SET_ONIFILE(file) do {                                          \
        context.OpenFileRecording(file, player);                        \
        player.SetRepeat(false);                                        \
    } while (0)

#define EXEC_ONIFILE() do {                     \
        context.StartGeneratingAll();           \
        while (!player.IsEOF()) {               \
            context.WaitAndUpdateAll();         \
        }                                       \
    } while (0)

#define FINISH_ONIFILE() do {                   \
        context.StopGeneratingAll();            \
    } while (0)


TEST_F(UserContextTest, NoNewUser) {
    SET_ONIFILE("./test/oni/depth_only.oni");
    MockUserContext object(&context);
    int userId = 1;

    EXPECT_CALL(object, onNewUser(userId)).Times(0);

    EXEC_ONIFILE();

    ASSERT_FALSE(object.isAvailable(userId));
    ASSERT_FALSE(object.isCalibrated(userId));
    ASSERT_FALSE(object.isTracking(userId));

    FINISH_ONIFILE();
}

TEST_F(UserContextTest, NewUserAndNoPoseUser) {
    SET_ONIFILE("./test/oni/user_new.oni");
    MockUserContext object(&context);
    int userId = 1;

    ON_CALL(object, onNewUser(_))
        .WillByDefault(Invoke(&object, &MockUserContext::fakeOnNewUser));
    
    EXPECT_CALL(object, onNewUser(userId)).Times(1);
    EXPECT_CALL(object, onPoseStart(userId)).Times(0);

    EXEC_ONIFILE();

    ASSERT_TRUE(object.isAvailable(userId));
    ASSERT_FALSE(object.isCalibrated(userId));
    ASSERT_FALSE(object.isTracking(userId));

    FINISH_ONIFILE();
}

TEST_F(UserContextTest, NewUserAndCalibrateUser) {
    SET_ONIFILE("./test/oni/user_calibrate.oni");
    MockUserContext object(&context);
    int userId = 1;

    ON_CALL(object, onNewUser(_))
        .WillByDefault(Invoke(&object, &MockUserContext::fakeOnNewUser));
    ON_CALL(object, onPoseStart(_))
        .WillByDefault(Invoke(&object, &MockUserContext::fakeOnPoseStart));
    ON_CALL(object, onCalibrationStart(_))
        .WillByDefault(Invoke(&object, &MockUserContext::fakeOnCalibrationStart));
    ON_CALL(object, onCalibrationEnd(_, _))
        .WillByDefault(Invoke(&object, &MockUserContext::fakeOnCalibrationEnd));
    
    EXPECT_CALL(object, onNewUser(userId)).Times(1);
    EXPECT_CALL(object, onPoseStart(userId)).Times(1);
    EXPECT_CALL(object, onCalibrationStart(userId)).Times(1);
    EXPECT_CALL(object, onCalibrationEnd(userId, true)).Times(1);

    EXEC_ONIFILE();

    ASSERT_TRUE(object.isAvailable(userId));
    ASSERT_TRUE(object.isCalibrated(userId));
    ASSERT_TRUE(object.isTracking(userId));

    FINISH_ONIFILE();
}

TEST_F(UserContextTest, NewUserAndCalibrateUserFailure) {
    SET_ONIFILE("./test/oni/user_calibrate_failure.oni");
    MockUserContext object(&context);
    int userId = 1;

    ON_CALL(object, onNewUser(_))
        .WillByDefault(Invoke(&object, &MockUserContext::fakeOnNewUser));
    ON_CALL(object, onPoseStart(_))
        .WillByDefault(Invoke(&object, &MockUserContext::fakeOnPoseStart));
    ON_CALL(object, onCalibrationStart(_))
        .WillByDefault(Invoke(&object, &MockUserContext::fakeOnCalibrationStart));
    ON_CALL(object, onCalibrationEnd(_, _))
        .WillByDefault(Invoke(&object, &MockUserContext::fakeOnCalibrationEnd));
    
    EXPECT_CALL(object, onNewUser(userId)).Times(1);
    EXPECT_CALL(object, onPoseStart(userId)).Times(1);
    EXPECT_CALL(object, onCalibrationStart(userId)).Times(1);
    EXPECT_CALL(object, onCalibrationEnd(userId, false)).Times(1);

    EXEC_ONIFILE();

    ASSERT_TRUE(object.isAvailable(userId));
    ASSERT_FALSE(object.isTracking(userId));
    ASSERT_FALSE(object.isCalibrated(userId));

    FINISH_ONIFILE();
}

