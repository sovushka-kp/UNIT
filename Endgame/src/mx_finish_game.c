#include "../inc/virus.h"

void mx_finish_game(t_topiman *topiman) {
  SDL_Rect  rect;   
  
  rect = (SDL_Rect) {0, 0, 40*30, 24*30};  
  render_clearSDL(topiman);
  
  if (topiman->antisept == 1) {
    topiman->topiTexture = SDL_CreateTextureFromSurface(topiman->sdl.renderer, topiman->WINTOPI1);
  } else {
    topiman->topiTexture = SDL_CreateTextureFromSurface(topiman->sdl.renderer, topiman->gameover1);
  }
  
  SDL_RenderCopy(topiman->sdl.renderer, topiman->topiTexture, NULL, &(rect));
  SDL_RenderPresent(topiman->sdl.renderer);
  SDL_Delay(240);
  render_clearSDL(topiman);
  
  if (topiman->antisept == 1) {
    topiman->topiTexture = SDL_CreateTextureFromSurface(topiman->sdl.renderer, topiman->WINTOPI2);
  } else {
    topiman->topiTexture = SDL_CreateTextureFromSurface(topiman->sdl.renderer, topiman->gameover2);
  }
  SDL_RenderCopy(topiman->sdl.renderer, topiman->topiTexture, NULL, &(rect));
  SDL_RenderPresent(topiman->sdl.renderer);
  SDL_Delay(240);
}
