#include "../inc/virus.h"

void mx_topi(t_topiman *topiman) //перемещение
{
	extern int map[H][W];
	
	if (map[topiman->topi.y + topiman->topiMove.y][topiman->topi.x + topiman->topiMove.x] != 2)
	{
		map[topiman->topi.y][topiman->topi.x] = 0;

		topiman->topi.x = topiman->topi.x + topiman->topiMove.x;
		topiman->topi.y = topiman->topi.y + topiman->topiMove.y;

		if (map[topiman->topi.y][topiman->topi.x] == 1) {
			topiman->score += 10;
		}
		else if (map[topiman->topi.y][topiman->topi.x] == 4) {
			//if (topiman->score >= 5650)	{
				topiman->score += 1000;
				topiman->antisept = 1;
			//}
		}
		map[topiman->topi.y][topiman->topi.x] = 3;
	}
}

void	putScore(t_topiman *topiman)
{
	char buf[50] = "CASH: ";
	
	sprintf(buf + 6, "%d", topiman->score);
	topiman->sdl.surfaceScore = TTF_RenderText_Solid(topiman->sdl.font, buf, (SDL_Color){255, 0, 0, 255});
	topiman->sdl.textureScore = SDL_CreateTextureFromSurface(topiman->sdl.renderer, topiman->sdl.surfaceScore);
	topiman->sdl.rectScore.x = 470;
	topiman->sdl.rectScore.y = 0;
	topiman->sdl.rectScore.w = 250;
	topiman->sdl.rectScore.h = 37;
	SDL_RenderCopy(topiman->sdl.renderer, topiman->sdl.textureScore, NULL, &(topiman->sdl.rectScore));
	SDL_FreeSurface(topiman->sdl.surfaceScore);
	SDL_DestroyTexture(topiman->sdl.textureScore);
}

