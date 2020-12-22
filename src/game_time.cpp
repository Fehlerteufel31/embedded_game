#include <game_time.hpp>

Time::Time()
{
    time = 0;
}
void Time::start()
{
    time = SDL_GetTicks();
}
uint32_t Time::getTime()
{
    time = SDL_GetTicks() - time;
    return time;
}
void Time::reset()
{
    time = 0;
}
