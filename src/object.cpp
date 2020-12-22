#include <object.hpp>

Object::Object(SDL_Texture *tex,SDL_Renderer *ren, Object_typ typ,SDL_Rect dst)
{
    this->tex = tex;
    this->ren = ren;
    this->typ = typ;
    this->dst = dst;

    setRectSrc();
}

void Object::update()
 {
    SDL_RenderCopy(ren,tex,&src,&dst);
}

void Object::setPos(int x,int y)
{
    dst.x = x;
    dst.y = y;
}
int Object::getPosX()
{
    return dst.x;
}
int Object::getPosY()
{
    return dst.y;
}

void Object::setRectSrc()
{
    switch (typ)
    {
    case Apfel:
        src.x = 0;
	    src.y = 430;
	    src.w = 46;
	    src.h = 67;
        break;
    case Banane:
        src.x = 46;
	    src.y = 430;
	    src.w = 51;
	    src.h = 67;
        break;
    case Limette:
        src.x = 97;
	    src.y = 430;
	    src.w = 52;
	    src.h = 67;
        break;
    case Traube:
        src.x = 149;
	    src.y = 430;
	    src.w = 64;
	    src.h = 67;
        break;
    case Zitrone:
        src.x = 212;
	    src.y = 430;
	    src.w = 52;
	    src.h = 67;
        break;
    case Melone:
        src.x = 160;
	    src.y = 390;
	    src.w = 70;
	    src.h = 40;
        break;
    
    case Bombe:
        src.x = 249;
	    src.y = 324;
	    src.w = 56;
	    src.h = 65;
        break;
    default:
        break;
    }

}
