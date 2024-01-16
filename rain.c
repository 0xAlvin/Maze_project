#include "include/maze.h"
#include "include/colors.h"

/**
 * rain - create a rain effect
 * @window: the window to render to
 * @renderer: the renderer to use
 * @drops: the number of drops to render
 * @delay: the delay between frames
 * @return: Returns 0 if the program exited successfully, otherwise 1.
 */

int rain(SDL_Renderer *renderer, int drops, int delay)
{
    // create rain
    Rain rain[drops];
    for (int i = 0; i < drops; i++)
    {
        rain[i].x = rand() % 800;
        rain[i].y = rand() % 600;
        rain[i].length = (rand() % 20) + 5;
        rain[i].speed = (rand() % 10) + 5;
    }
    // render rain
    for (int i = 0; i < drops; i++)
    {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, rain[i].x, rain[i].y, rain[i].x, rain[i].y + rain[i].length);
        rain[i].y += rain[i].speed;
        if (rain[i].y > 600)
        {
            rain[i].y = 0;
        }
    }

    // render
    SDL_RenderPresent(renderer);
    SDL_Delay(delay);

    return (0);
}