#include "../inc/virus.h"

int map[25][40] = {	// карта
	{7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7},
    	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{2,1,1,1,1,2,1,1,1,1,1,1,1,2,2,2,1,1,2,5,2,1,1,1,1,1,1,2,2,1,1,2,2,1,1,2,2,1,1,2},
	{2,2,2,2,1,1,1,2,2,2,2,2,1,1,1,1,1,1,2,2,2,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,2,1,1,2,2,1,1,1,1,2,2,1,1,1,2},
	{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,2,2,1,1,2,1,1,1,1,1,1,1,1,1,1,1,2,1,2},
	{2,2,1,1,2,2,2,2,1,1,1,2,2,2,2,1,1,1,2,1,1,1,1,1,1,1,1,4,1,1,2,1,2,2,1,1,1,2,1,2},
	{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,2,2,2,2,2,2,2,1,2,1,1,1,1,2,1,2,1,2},
	{2,1,1,2,2,2,2,2,2,2,2,1,1,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1,2,1,1,1,2},
	{2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{2,2,1,1,1,2,1,1,2,2,1,1,2,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,2,2,2,2,2,2},
	{2,2,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,2,1,1,2,2,2,1,1,1,2,1,1,1,1,2,1,1,1,1,1,1,1,2},
	{2,1,1,2,1,2,1,1,1,1,1,1,2,1,1,1,1,2,1,1,1,1,1,1,1,1,2,1,1,1,1,2,1,1,1,1,2,2,2,2},
	{2,1,1,2,1,1,1,1,2,2,2,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,2,1,1,2,1,1,1,1,2},
	{2,1,1,2,1,2,1,1,1,1,1,1,2,2,2,1,2,1,1,1,1,1,1,1,1,1,2,2,2,1,1,1,1,1,2,1,1,1,2,2},
	{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,2,2,1,1,1,1,1,1,1,1,1,2,2,1,1,2,1,1,1,2,2},
	{2,1,1,2,2,2,2,1,2,2,1,1,2,1,1,1,1,1,1,1,1,1,2,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,2,2},
	{2,1,1,2,1,1,2,1,1,1,1,1,2,1,1,2,1,1,2,1,2,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,2},
	{2,1,1,2,1,1,2,2,2,2,1,1,2,1,1,2,1,1,2,1,2,1,1,1,2,1,2,2,2,1,1,1,1,1,1,1,2,1,1,2},
	{2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,2,1,1,1,2,1,1,1,1,1,1,1,2,1,2,1,2,1,1,2},
	{2,1,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,1,2,1,2,1,1,1,2,1,2,1,2,2,2,1,2,1,2,1,2,1,1,2},
	{2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,2,1,2,1,1,1,1,2},
	{2,1,1,1,1,1,2,2,2,1,1,1,2,2,2,2,1,1,2,2,2,2,2,2,1,1,1,1,2,2,2,1,1,1,1,1,2,1,1,2},
	{2,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,2},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}};

void default_position_topi(t_topiman *topiman) //место спавна topi
{
	topiman->topi = (t_pos){21, 21};
	topiman->topiMove = (t_pos){-1, 0};
	topiman->virus = (t_pos){3, 2};
	topiman->sdl.font = TTF_OpenFont("resource/17848.ttf", 19);
}

static void initDefault(t_topiman *topiman, int *stop)
{	
	*stop = 0;
	topiman->score = 0;
	
	default_position_topi(topiman);

	topiman->antiImage1 = IMG_Load("resource/anti1.png");
	topiman->antiTexture = SDL_CreateTextureFromSurface(topiman->sdl.renderer, topiman->antiImage1);
	
	topiman->coinImage = IMG_Load("resource/money.png");
	topiman->coinTexture = SDL_CreateTextureFromSurface(topiman->sdl.renderer, topiman->coinImage);



	topiman->topiImage = IMG_Load("resource/Topi1.png"); //подключение картинок
	topiman->topiImageDown1 = IMG_Load("resource/Topi2.png");
	topiman->topiImageDown2 = IMG_Load("resource/Topi3.png");
	topiman->topiImageUp1 = IMG_Load("resource/Topi_S1.png");
	topiman->topiImageUp2 = IMG_Load("resource/Topi_S2.png");
	topiman->topiImageUp3 = IMG_Load("resource/Topi_S3.png");
	topiman->topiImageLeft1 = IMG_Load("resource/Topi_L1.png");
	topiman->topiImageLeft2 = IMG_Load("resource/Topi_L2.png");
	topiman->topiImageLeft3 = IMG_Load("resource/Topi_L3.png");
	topiman->topiImageRight1 = IMG_Load("resource/Topi_P1.png");
	topiman->topiImageRight2 = IMG_Load("resource/Topi_P2.png");
	topiman->topiImageRight3 = IMG_Load("resource/Topi_P3.png");

	topiman->virusImage = IMG_Load("resource/ViruS.png");
	topiman->WINTOPI1 = IMG_Load("resource/WIN1.bmp");
	topiman->WINTOPI2 = IMG_Load("resource/WIN2.bmp");
	topiman->gameover1 = IMG_Load("resource/game_over_1.bmp");
	topiman->gameover2 = IMG_Load("resource/game_over_2.bmp");

	topiman->topiTexture = SDL_CreateTextureFromSurface(topiman->sdl.renderer, topiman->topiImageLeft1); //cоздание текстуры
	topiman->antisept = 0;
	topiman->virusTexture = SDL_CreateTextureFromSurface(topiman->sdl.renderer, topiman->virusImage);  //cоздание текстуры

}

int main(void)
{
	int			stop;
	t_topiman	*topiman;

	topiman = (t_topiman *)malloc(sizeof(t_topiman));
	initSDL(topiman); //инициализации SDL
	initDefault(topiman, &stop);
	int b = 0;
	 b = mx_menu(topiman->sdl.renderer);
	
	if (b == 1){
		while (!stop)
		{
			while (SDL_PollEvent(&(topiman->sdl.e))) //опрос события
			{
				if (topiman->sdl.e.type == SDL_QUIT || topiman->sdl.e.key.keysym.sym == SDLK_ESCAPE) //выйти из игры
					stop = 1;
				else if (topiman->sdl.e.type == SDL_KEYUP)
				{
					if (topiman->sdl.e.key.keysym.sym == SDLK_DOWN) //главное управление
						topiman->topiMove = (t_pos){0, 1};
					else if (topiman->sdl.e.key.keysym.sym == SDLK_UP)
						topiman->topiMove = (t_pos){0, -1};
					else if (topiman->sdl.e.key.keysym.sym == SDLK_RIGHT)
						topiman->topiMove = (t_pos){1, 0};
					else if (topiman->sdl.e.key.keysym.sym == SDLK_LEFT)
						topiman->topiMove = (t_pos){-1, 0};
				}
			}
			if (mx_topi_virus(topiman) == 1) {
				continue;
			}
			render_clearSDL(topiman); //очистка цели рендеринга
			mx_topi(topiman); //поведение topi
			mx_virus(topiman); //поведение virusa
			mx_map(topiman); //обращение к карте

			SDL_RenderPresent(topiman->sdl.renderer); //рендеринг
			SDL_Delay(230); //скорость передвижения
		}
	}
	destroySDL(topiman); //закрывает окно
	return 0;
}
