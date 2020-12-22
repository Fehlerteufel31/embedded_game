// SDL2 Hello, World!
// This should display a white screen for 2 seconds
// compile with: clang++ main.cpp -o hello_sdl2 -lSDL2
// run with: ./hello_sdl2
#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <stdint.h>
#include <game.hpp>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 480

int main(int argc, char* args[]) 
{
	const int FRAMES_PER_SECOND = 20;
	uint32_t fps;
	IMG_Init(IMG_INIT_PNG);
	uint32_t frame = 0;
	bool quit = false;
	bool cap = true;
	SDL_Event e;
	
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	SDL_Window *win = SDL_CreateWindow("Hello World!",0,0,800,480,SDL_WINDOW_SHOWN);
	
	if(win	== nullptr)
	{
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}
	
	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr)
	{
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	
	SDL_Surface *bmp = IMG_Load("sprites/spritesV2.png");
	if (bmp == nullptr)
	{
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}	

	SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
	SDL_FreeSurface(bmp);
	if (tex == nullptr)
	{
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}
	
	
	SDL_Rect src3rect;	
	SDL_Rect dst2rect;

	src3rect.x = 290;
	src3rect.y = 460;
	src3rect.w = 30;
	src3rect.h = 30;
	
	dst2rect.x = 0;
	dst2rect.y = 0;
	dst2rect.w = 60;
	dst2rect.h = 60;

	SDL_Rect src1rect;
	SDL_Rect src2rect;
	SDL_Rect dstrect;
	
	src1rect.x = 10;
	src1rect.y = 360;
	src1rect.w = 70;	
	src1rect.h = 70;

	src2rect.x = 80;
	src2rect.y = 360;
	src2rect.w = 70;	
	src2rect.h = 70;
	
	dstrect.x = 200;
	dstrect.y = 100;
	dstrect.w = 280;
	dstrect.h = 280;

	
	//A sleepy rendering loop, wait for 3 seconds and render and present the screen each time
	while(quit == false)
	{			
		fps = SDL_GetTicks();
		frame++;

		while(SDL_PollEvent(&e) != 0)
		{
			if( e.type == SDL_QUIT)
			{
				quit = true;
			}
			if(e.type == SDL_MOUSEMOTION)
			{
				if(e.motion.x <= 60 && e.motion.y <= 60 )
				{	
					std::cout << "X: " << e.motion.x << "Y: " << e.motion.y << std::endl;
					quit = true;
				}
			}
		}

		SDL_SetRenderDrawColor(ren,255,255,255,255);		
		//First clear the renderer
		SDL_RenderClear(ren);
		
		if( frame <= 10)
		{	
			//Draw the texture
			SDL_RenderCopy(ren, tex, &src1rect, &dstrect);
		}
		else if ( frame > 10)
		{
			SDL_RenderCopy(ren, tex, &src2rect,&dstrect);
		}		
		SDL_RenderCopy(ren, tex, &src3rect,&dst2rect);

		
		//Update the screen
		SDL_RenderPresent(ren);
		//Take a quick break after all that hard work
		
		if((cap == true) && ((SDL_GetTicks() - fps) < 1000 / FRAMES_PER_SECOND))
		{
			SDL_Delay((1000/FRAMES_PER_SECOND)- (SDL_GetTicks() - fps) );
		}
		if(frame >= 20)
		{
			frame = 0;
		}	
	}	
	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}
