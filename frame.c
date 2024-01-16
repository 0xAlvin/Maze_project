#include "include/maze.h"
#include "include/colors.h"
/**
 * sendFrame - Sends the frame to the screen.
 * @param renderer: The first SDL renderer to draw on.
 * @param renderer2: The second SDL renderer.
*/
void sendFrame(SDL_Renderer *renderer,SDL_Renderer *renderer2)
{
    // Push the frame stored in the renderer to the screen
    SDL_RenderPresent(renderer);
    SDL_RenderPresent(renderer2);
    SDL_RenderClear(renderer);
    SDL_RenderClear(renderer2);
}