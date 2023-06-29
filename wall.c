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
void wall(SDL_Renderer* renderer, int x1, int y1, int x2, int y2)
{
    SDL_SetRenderDrawColor(renderer,COLOR_WHITE.r,COLOR_WHITE.g,COLOR_WHITE.b,COLOR_WHITE.a);
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}