#include "Timer.h"

Timer* Timer::_instance = new Timer;

Timer::Timer(void)
{
    gettimeofday(&start, NULL);
}

Timer* Timer::instance(void)
{
    return _instance;
}

int Timer::current(void)
{
    gettimeofday(&currentTime, NULL);

    return (int)(currentTime.tv_sec - start.tv_sec);
}
