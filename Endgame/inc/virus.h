#ifndef VIRUS_H
#define VIRUS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "SDL_ttf.h"
#include "SDL_image.h"

#define WID 40*30
#define HEIG 24*30+30
#define W WID / 30
#define H HEIG / 30

typedef struct		s_sdl
{
	TTF_Font		*font;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Surface		*surfaceScore;
	SDL_Rect		rectScore;
	SDL_Texture		*textureScore;
	SDL_Event		e;
}					t_sdl;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;


typedef struct		s_topiman
{
	t_sdl			sdl;
	t_pos			topi;
	t_pos			virus;
	t_pos			topiMove;
	SDL_Surface		*topiImage;
	SDL_Surface		*topiImageUp1;
	SDL_Surface		*topiImageUp2;
	SDL_Surface		*topiImageUp3;
	SDL_Surface		*topiImageDown1;
	SDL_Surface		*topiImageDown2;
	SDL_Surface		*topiImageLeft1;
	SDL_Surface		*topiImageLeft2;
	SDL_Surface		*topiImageLeft3;
	SDL_Surface		*topiImageRight1;
	SDL_Surface		*topiImageRight2;
	SDL_Surface		*topiImageRight3;
	SDL_Surface		*virusImage;
	SDL_Texture		*topiTexture;
	SDL_Texture		*virusTexture;
	SDL_Rect		topiRect;
	SDL_Rect		virusRect;

	SDL_Surface		*WINTOPI1;
	SDL_Surface		*WINTOPI2;
	SDL_Surface		*gameover1;
	SDL_Surface		*gameover2;

	SDL_Surface		*antiImage1;
	SDL_Texture		*antiTexture;
	SDL_Rect		antiRect;

	SDL_Surface		*coinImage;
	SDL_Texture		*coinTexture;
	SDL_Rect		coinRect;

	int				score;
	int				stop;
	int             winFlag;
	int 			antisept;

	SDL_Surface		*messageSurface;
	SDL_Rect			messageRect;
	SDL_Texture		*mssageTexture;

}					t_topiman;



void				initSDL(t_topiman *topiman);
void				destroySDL(t_topiman *topiman);
void				render_clearSDL(t_topiman *topiman);

void				default_position_topi(t_topiman *topiman);

void				mx_map(t_topiman *topiman);
void				mx_topi(t_topiman *topiman);
void				mx_virus(t_topiman *topiman);
void				putScore(t_topiman *topiman);
int 				mx_topi_virus(t_topiman *topi);
int 				mx_menu(SDL_Renderer *render);
void 				mx_finish_game(t_topiman *topiman);

void CreateRectangle(SDL_Rect* object, int x, int y, int w, int h);
void CreateTextureImage(const char *file, SDL_Surface **surface, SDL_Renderer *render, SDL_Texture **texture);
void CreateTextureText(TTF_Font **font, const char *file, int size, SDL_Surface **surface, const char *text, 
                        SDL_Color color, SDL_Texture **texture, SDL_Renderer *render);



#endif
