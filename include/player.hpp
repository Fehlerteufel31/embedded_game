#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <includes.hpp>

class Player
{
public:
    Player(SDL_Texture *tex,SDL_Renderer *ren, SDL_Rect dst);

    void update(int frame);
    void setPos(int x,int y);
    int getPosX();
    int getPosY();

private:   
    SDL_Texture *tex;
    SDL_Renderer *ren;
    SDL_Rect src1;
    SDL_Rect src2;
    SDL_Rect dst;
};

#endif /*PLAYER_HPP*/