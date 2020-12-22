#include <player.hpp>

Player::Player(SDL_Texture *tex,SDL_Renderer *ren, SDL_Rect dst)
{
    this->tex = tex;
    this->ren = ren;
    this->dst = dst;

	src1.x = 10;
	src1.y = 360;
	src1.w = 70;	
	src1.h = 70;

	src2.x = 80;
	src2.y = 360;
	src2.w = 70;	
	src2.h = 70;
}

void Player::update(int frame)
{
    if( frame <= 10)
    {	
        //Draw the texture
        SDL_RenderCopy(ren, tex, &src1, &dst);
    }
    else if ( frame > 10)
    {
        SDL_RenderCopy(ren, tex, &src2,&dst);
    }
}
void Player::setPos(int x,int y)
{
    dst.x = x;
    dst.y = y;
}
int Player::getPosX()
{
    return dst.x;
}
int Player::getPosY()
{
    return dst.y;
}