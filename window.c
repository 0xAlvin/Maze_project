#include "include/maze.h"

   // Create a window1 and renderer
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Window* window2 = NULL;
    SDL_Renderer* renderer2 = NULL;


void createWindows(void){
       // Create a window1 and renderer
    window = SDL_CreateWindow("Map", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 610,700, SDL_WINDOW_HIDDEN | SDL_WINDOW_BORDERLESS | SDL_WINDOW_ALWAYS_ON_TOP);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    window2 = SDL_CreateWindow("THE MAZE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowW,windowH, 0);
    renderer2 = SDL_CreateRenderer(window2, -1, SDL_RENDERER_ACCELERATED);

}
void cleanUp(void){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window2);
    SDL_DestroyRenderer(renderer2);
    SDL_Quit();
}