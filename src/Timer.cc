#include "Timer.h"

Timer* Timer::_instance = new Timer;

Timer::Timer(void)
{
    xnOSStartTimer(&tick);
}

Timer* Timer::instance(void)
{
    return _instance;
}

XnUInt64 Timer::current(void)
{
    XnUInt64 now;
    xnOSQueryTimer(tick, &now);

    return now / 1000000;
}
