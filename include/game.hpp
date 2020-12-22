#ifndef GAME_HPP
#define GAME_HPP
#include <includes.hpp>
#include <game_time.hpp>
#include <object.hpp>
#include <player.hpp>

class Game
{
public:
    Game();
    ~Game();
    bool run();
    bool init();

    bool startMenu();
    
    void event();
    void logic();
    void rendering();

    void close();
private:
    SDL_Window *win;
    SDL_Texture *tex;
    SDL_Renderer *ren;

    Time time;

    Player *player;
    std::vector<Object> *objects;
    
    bool running;
};

#endif /* GAME_HPP*/