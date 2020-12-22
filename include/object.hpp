#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <includes.hpp>

enum Object_typ {Apfel,Banane,Limette,Traube,Zitrone,Melone,Bombe};

class Object
{
public:
    
    Object(SDL_Texture *tex,SDL_Renderer *ren, Object_typ typ, SDL_Rect dst);

    void update();
    void setPos(int x,int y);
    int getPosX();
    int getPosY();
    
private:
    void setRectSrc();
    
    Object_typ typ;
    SDL_Texture *tex;
    SDL_Renderer *ren;
    SDL_Rect src;
    SDL_Rect dst;
};

#endif /*OBJECT_HPP*/