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

double Timer::current(void)
{
    gettimeofday(&currentTime, NULL);

    return currentTime.tv_sec - start.tv_sec;
}
