// -*- C++ -*-

#ifndef _TYTHON_MOCK_TIMER_H
#define _TYTHON_MOCK_TIMER_H

#include <gmock/gmock.h>
#include "Timer.h"

class MockTimer : public Timer {
public:
    MockTimer(void) {
        ON_CALL(*this, current()).WillByDefault(::testing::Return(0));
    }
    virtual ~MockTimer(void) {}

    MOCK_METHOD0(current, XnUInt64(void));
};

#endif // _TYTHON_MOCK_TIMER_H
