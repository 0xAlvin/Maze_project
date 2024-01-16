#include"../include/maze.h"
/**
 * drawLine - draws a line
 * @renderer: renderer
 * @x1: x1
 * @y1: y1
 * @x2: x2
 * @y2: y2
 */
void drawLine(SDL_Renderer *renderer, int x1, int y1, int x2, int y2)
{
SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}
