#include "include/maze.h"
#include "include/colors.h"

void sendFrame(SDL_Renderer *renderer)
{
    // Push the frame stored in the renderer to the screen
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
}