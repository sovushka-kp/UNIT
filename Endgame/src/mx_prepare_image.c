#include "../inc/virus.h"


void CreateRectangle(SDL_Rect* object, int x, int y, int w, int h){
    object->x = x;
    object->y = y;
    object->w = w;
    object->h = h;
}

void CreateTextureImage(const char *file, SDL_Surface **surface, SDL_Renderer *render, SDL_Texture **texture){
    *surface = IMG_Load(file);
    if (!*surface)
        printf("error creating surface\n%s\n", file);
    *texture = SDL_CreateTextureFromSurface(render, *surface);
    if (!*texture)
        printf("error creating texture: %s\n", SDL_GetError());
    SDL_FreeSurface(*surface);
}

void CreateTextureText(TTF_Font **font, const char *file, int size, SDL_Surface **surface, const char *text, 
                        SDL_Color color, SDL_Texture **texture, SDL_Renderer *render){
    
    *font = TTF_OpenFont(file, size);
    if (!*font)
        printf("error opening the .ttf file: %s\n", TTF_GetError());
    
    *surface = TTF_RenderText_Solid(*font, text, color);
    if (!*surface)
        printf("error creating surface from: %s\n", text);
    
    *texture = SDL_CreateTextureFromSurface(render, *surface);
    if (!*texture)
        printf("error creating texture: %s\n", SDL_GetError());

    TTF_CloseFont(*font);
    SDL_FreeSurface(*surface);
}
