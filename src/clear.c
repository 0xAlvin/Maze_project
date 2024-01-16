#include "../include/maze.h"

/**
 * clear - clear screen
 * @renderer: renderer
 */

void clear(SDL_Renderer *renderer)
{
SDL_SetRenderDrawColor(renderer, COLOR_GRAY.r, COLOR_GRAY.g,
COLOR_GRAY.b, COLOR_GRAY.a);
SDL_RenderPresent(renderer);
SDL_RenderClear(renderer);
}

/**
 * cleanUp - clean up
 * @renderer: renderer
 * @window: window
*/

void cleanUp(SDL_Renderer *renderer, SDL_Window *window)
{
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
TTF_Quit();
SDL_Quit();
}
