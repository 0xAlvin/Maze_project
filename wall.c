#include "include/maze.h"
#include "include/colors.h"

/**
 * wall - Creates a vector2D with the given x and y coordinates.
 * @x1: The x1-coordinate.
 * @y1: The y1-coordinate.
 * @x2: The x2-coordinate.
 * @y2: The y2-coordinate.
 *
 * Return: A pointer to the dynamically allocated array of vector2D.
 */
// const SDL_RenderDrawLine
void drawWalls(SDL_Renderer *renderer, SDL_Point walls[wallmaxCount][2], int wallCount)
{
    // Loop over each wall and draw it
    
    SDL_SetRenderDrawColor(renderer, COLOR_YELLOW.r, COLOR_YELLOW.g, COLOR_YELLOW.b, COLOR_YELLOW.a);
    for (int i = 0; i < wallCount; i++)
    {
        SDL_RenderDrawLine(renderer, walls[i][0].x, walls[i][0].y, walls[i][1].x, walls[i][1].y);
    }
}
