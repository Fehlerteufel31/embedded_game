#include <game.hpp>

Game::Game()
{
    running = false;

}

bool Game::run()
{
    return running;
}

bool Game::init()
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}

    win = SDL_CreateWindow("Pixel Bear",0,0,800,480,SDL_WINDOW_SHOWN);	
	if(win	== nullptr)
	{
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr)
	{
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

    SDL_Surface *bmp = IMG_Load("sprites/spritesV2.png");
	if (bmp == nullptr)
	{
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

    tex = SDL_CreateTextureFromSurface(ren, bmp);
	SDL_FreeSurface(bmp);
	if (tex == nullptr)
	{
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

    SDL_Rect dstrect;
	dstrect.x = 320;
	dstrect.y = 400;
	dstrect.w = 140;
	dstrect.h = 140;


    player = new Player(tex,ren,dstrect);
    return true;
}