#include "../inc/virus.h"

void	initSDL(t_topiman *topiman) //активация
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	IMG_Init(IMG_INIT_JPG);
	topiman->sdl.window = SDL_CreateWindow("Topi", 544, 302, WID, HEIG,
			SDL_WINDOW_OPENGL);
	topiman->sdl.renderer = SDL_CreateRenderer(topiman->sdl.window, -1,
			SDL_RENDERER_ACCELERATED);
	SDL_RenderClear(topiman->sdl.renderer);
}

void	destroySDL(t_topiman *topiman) //освобождение
{
	SDL_DestroyRenderer(topiman->sdl.renderer);
	SDL_DestroyWindow(topiman->sdl.window);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

void	render_clearSDL(t_topiman *topiman) //очистка
{
	SDL_SetRenderDrawColor(topiman->sdl.renderer, 0, 0, 0, 255);
	SDL_RenderClear(topiman->sdl.renderer);
}
