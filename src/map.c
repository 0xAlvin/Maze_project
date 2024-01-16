#include "../include/maze.h"
/**
 * map - create a map
 * @renderer: renderer
 */
void map(SDL_Renderer *renderer)
{
int mapX = 8, mapY = 8, mapS = 64;
int map[] = {
1, 1, 1, 1, 1, 1, 1, 1,
1, 0, 0, 0, 0, 0, 0, 1,
1, 0, 1, 1, 1, 1, 0, 1,
1, 0, 1, 0, 0, 0, 0, 1,
1, 0, 1, 0, 1, 1, 1, 1,
1, 0, 1, 0, 1, 0, 0, 1,
1, 0, 0, 0, 1, 0, 0, 1,
1, 1, 1, 1, 1, 1, 1, 1
};
int x, y, xoffset, yoffset;
for (y = 0; y < mapY; y++)
{
for (x = 0; x < mapX; x++)
{
if (map[y * mapX + x] == 1)
{
SDL_SetRenderDrawColor(renderer, COLOR_WHITE.r, COLOR_WHITE.g,
COLOR_WHITE.b, COLOR_WHITE.a);
}
else
{
SDL_SetRenderDrawColor(renderer, COLOR_BLACK.r, COLOR_BLACK.g,
COLOR_BLACK.b, COLOR_BLACK.a);
}
xoffset = x * mapS;
yoffset = y * mapS;
SDL_Rect mapRect = {xoffset + 1, yoffset + 1, mapS - 1, mapS - 1};
SDL_RenderFillRect(renderer, &mapRect);
}
}
}
