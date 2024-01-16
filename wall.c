#include "include/maze.h"
#include "include/colors.h"

/**
 * drawWalls - Draws the walls of the maze.
 * @param renderer: The SDL renderer to draw on.
 * @param walls: The array of walls to draw.
 * @param wallCount: The number of walls to draw.
*/
void drawWalls(SDL_Renderer *renderer, SDL_Point walls[wallmaxCount][2], int wallCount)
{
    // Loop over each wall and draw it
    
    SDL_SetRenderDrawColor(renderer, COLOR_YELLOW.r, COLOR_YELLOW.g, COLOR_YELLOW.b, COLOR_YELLOW.a);
    for (int i = 0; i < wallCount; i++)
    {
        SDL_RenderDrawLine(renderer, walls[i][0].x, walls[i][0].y, walls[i][1].x, walls[i][1].y);
    }
}
