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
        context.Shutdown();
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
        context.StopGeneratingAll();            \
    } while (0)
    

TEST_F(UserContextTest, NoNewUser) {
    SET_ONIFILE("./test/oni/depth_only.oni");
    MockUserContext object(&context);

    EXPECT_CALL(object, onNewUser(_)).Times(0);

    EXEC_ONIFILE();
}

TEST_F(UserContextTest, NewUserAndNoPoseUser) {
    SET_ONIFILE("./test/oni/user_new.oni");
    MockUserContext object(&context);

    ON_CALL(object, onNewUser(_))
        .WillByDefault(Invoke(&object, &MockUserContext::fakeOnNewUser));
    
    EXPECT_CALL(object, onNewUser(_)).Times(1);
    EXPECT_CALL(object, onPoseStart(_)).Times(0);

    EXEC_ONIFILE();
}

TEST_F(UserContextTest, NewUserAndCalibrateUser) {
    SET_ONIFILE("./test/oni/user_calibrate.oni");
    MockUserContext object(&context);

    ON_CALL(object, onNewUser(_))
        .WillByDefault(Invoke(&object, &MockUserContext::fakeOnNewUser));
    ON_CALL(object, onPoseStart(_))
        .WillByDefault(Invoke(&object, &MockUserContext::fakeOnPoseStart));
    ON_CALL(object, onCalibrationStart(_))
        .WillByDefault(Invoke(&object, &MockUserContext::fakeOnCalibrationStart));
    ON_CALL(object, onCalibrationEnd(_, _))
        .WillByDefault(Invoke(&object, &MockUserContext::fakeOnCalibrationEnd));
    
    EXPECT_CALL(object, onNewUser(_)).Times(1);
    EXPECT_CALL(object, onPoseStart(_)).Times(1);
    EXPECT_CALL(object, onCalibrationStart(_)).Times(1);
    EXPECT_CALL(object, onCalibrationEnd(_, true)).Times(1);

    EXEC_ONIFILE();
}

TEST_F(UserContextTest, NewUserAndCalibrateUserFailure) {
    SET_ONIFILE("./test/oni/user_calibrate_failure.oni");
    MockUserContext object(&context);

    ON_CALL(object, onNewUser(_))
        .WillByDefault(Invoke(&object, &MockUserContext::fakeOnNewUser));
    ON_CALL(object, onPoseStart(_))
        .WillByDefault(Invoke(&object, &MockUserContext::fakeOnPoseStart));
    ON_CALL(object, onCalibrationStart(_))
        .WillByDefault(Invoke(&object, &MockUserContext::fakeOnCalibrationStart));
    ON_CALL(object, onCalibrationEnd(_, _))
        .WillByDefault(Invoke(&object, &MockUserContext::fakeOnCalibrationEnd));
    
    EXPECT_CALL(object, onNewUser(_)).Times(1);
    EXPECT_CALL(object, onPoseStart(_)).Times(1);
    EXPECT_CALL(object, onCalibrationStart(_)).Times(1);
    EXPECT_CALL(object, onCalibrationEnd(_, false)).Times(1);

    EXEC_ONIFILE();
}

