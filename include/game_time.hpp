#ifndef TIME_HPP
#define TIME_HPP
#include <includes.hpp>

class Time
{
public:
    Time();
    void start();
    uint32_t getTime();
    void reset();
private:
    uint32_t time;
};

#endif /*TIME_HPP*/
