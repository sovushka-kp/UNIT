#include "../inc/virus.h"

void mx_map(t_topiman *topiman)
{
	extern int	map[H][W];
	SDL_Rect  rect;

	rect = (SDL_Rect) {0, 0, 30, 30}; //размер кубиков
	
	for (int y = 0; y < 25; y++)
	{
		rect.x = 0;
		for (int x = 0; x < 40; x++)
		{
			if (map[y][x] == 7)
			{
				SDL_SetRenderDrawColor(topiman->sdl.renderer, 0, 0, 0, 255);
				SDL_RenderFillRect(topiman->sdl.renderer, &rect);
			}
			if (map[y][x] == 4) {
				if (topiman->score >= 2500) { // антисептик
					topiman->antiRect = (SDL_Rect){rect.x - 5, rect.y - 5, 40, 40};
					SDL_RenderCopy(topiman->sdl.renderer, topiman->antiTexture, NULL, &(topiman->antiRect));
				}
			}
			if (map[y][x] == 2) //стенки и цвет
			{
				SDL_SetRenderDrawColor(topiman->sdl.renderer, 0, 0, 255, 255);
				SDL_RenderFillRect(topiman->sdl.renderer, &rect);
				SDL_SetRenderDrawColor(topiman->sdl.renderer, 0, 0, 139, 255);
				SDL_RenderDrawRect(topiman->sdl.renderer, &rect);
			}
			else if (map[y][x] == 1) // монетки
			{
				topiman->coinRect = (SDL_Rect){rect.x + 5, rect.y + 5, 18, 18};
				SDL_RenderCopy(topiman->sdl.renderer, topiman->coinTexture, NULL, &(topiman->coinRect));
				SDL_RenderDrawPoint(topiman->sdl.renderer, rect.x + 30/2, rect.y + 30/2);
				SDL_RenderDrawPoint(topiman->sdl.renderer, rect.x + 30/2, rect.y + 32/2);
				SDL_RenderDrawPoint(topiman->sdl.renderer, rect.x + 32/2, rect.y + 32/2);
			}
			else if (map[y][x] == 3) //создание текстур topi
			{
				topiman->topiRect = (SDL_Rect){rect.x, rect.y, 31, 31}; //размер топи

				if (topiman->topiMove.x == 0 && topiman->topiMove.y == 1) {
					topiman->topiTexture = SDL_CreateTextureFromSurface(topiman->sdl.renderer, topiman->topiImageDown1);
					topiman->topiTexture = SDL_CreateTextureFromSurface(topiman->sdl.renderer, topiman->topiImageDown2);
					if ((x % 2 && y % 2) || (x % 2 == 0 && y % 2 == 0)) {
						topiman->topiTexture = SDL_CreateTextureFromSurface(topiman->sdl.renderer, topiman->topiImage);
					}
					SDL_RenderCopy(topiman->sdl.renderer, topiman->topiTexture, NULL, &(topiman->topiRect));
				}
				else if (topiman->topiMove.x == 0 && topiman->topiMove.y == -1) {
					topiman->topiTexture = SDL_CreateTextureFromSurface(topiman->sdl.renderer, topiman->topiImageUp1);
					topiman->topiTexture = SDL_CreateTextureFromSurface(topiman->sdl.renderer, topiman->topiImageUp2);
					topiman->topiTexture = SDL_CreateTextureFromSurface(topiman->sdl.renderer, topiman->topiImageUp3);
					if ((x % 2 && y % 2) || (x % 2 == 0 && y % 2 == 0)) {
						topiman->topiTexture = SDL_CreateTextureFromSurface(topiman->sdl.renderer, topiman->topiImageUp1);
					}
					SDL_RenderCopy(topiman->sdl.renderer, topiman->topiTexture, NULL, &(topiman->topiRect));
				}
				else if (topiman->topiMove.x == 1 && topiman->topiMove.y == 0) {
					topiman->topiTexture = SDL_CreateTextureFromSurface(topiman->sdl.renderer, topiman->topiImageRight1);
					topiman->topiTexture = SDL_CreateTextureFromSurface(topiman->sdl.renderer, topiman->topiImageRight2);
					topiman->topiTexture = SDL_CreateTextureFromSurface(topiman->sdl.renderer, topiman->topiImageRight3);
					if ((x % 2 && y % 2) || (x % 2 == 0 && y % 2 == 0)) {
						topiman->topiTexture = SDL_CreateTextureFromSurface(topiman->sdl.renderer, topiman->topiImageRight1);
					}
					SDL_RenderCopy(topiman->sdl.renderer, topiman->topiTexture, NULL, &(topiman->topiRect));
				}
				else if (topiman->topiMove.x == -1 && topiman->topiMove.y == 0) {
					topiman->topiTexture = SDL_CreateTextureFromSurface(topiman->sdl.renderer, topiman->topiImageLeft1);
					topiman->topiTexture = SDL_CreateTextureFromSurface(topiman->sdl.renderer, topiman->topiImageLeft2);
					topiman->topiTexture = SDL_CreateTextureFromSurface(topiman->sdl.renderer, topiman->topiImageLeft3);
					if ((x % 2 && y % 2) || (x % 2 == 0 && y % 2 == 0)) {
						topiman->topiTexture = SDL_CreateTextureFromSurface(topiman->sdl.renderer, topiman->topiImageLeft1);
					}
					SDL_RenderCopy(topiman->sdl.renderer, topiman->topiTexture, NULL, &(topiman->topiRect));
				}
			}
			else if (map[y][x] == 5)
			{
				topiman->virusRect = (SDL_Rect){rect.x, rect.y, 32, 32};
				topiman->virusTexture = SDL_CreateTextureFromSurface(topiman->sdl.renderer, topiman->virusImage);
				SDL_RenderCopy(topiman->sdl.renderer, topiman->virusTexture, NULL, &(topiman->virusRect));
			}
			rect.x += 30;
			rect = (SDL_Rect) {rect.x, rect.y, rect.h, rect.w};
		}
		rect.y += 30;
	}
	putScore(topiman);
}
