// -*- C++ -*-

#ifndef _TYTHON_MOCK_TIMER_H
#define _TYTHON_MOCK_TIMER_H

#include <gmock/gmock.h>
#include "Timer.h"

class MockTimer : public Timer {
public:
    MockTimer(void) {}
    virtual ~MockTimer(void) {}

    MOCK_METHOD0(current, int(void));
};

#endif // _TYTHON_MOCK_TIMER_H
