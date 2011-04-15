#include "Timer.h"

Timer* Timer::instance = new Timer;

Timer::Timer(void)
{
    gettimeofday(&start, NULL);
}

Timer* Timer::getInstance(void)
{
    return instance;
}

int Timer::current(void)
{
    gettimeofday(&currentTime, NULL);

    return (int)(currentTime.tv_sec - start.tv_sec);
}
