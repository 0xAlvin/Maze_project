#include"../include/maze.h"
/**
 * drawRays - draw rays
 * @player: player
 * @renderer: renderer
*/
void drawRays(Player *player, SDL_Renderer *renderer)
{
int r, mx, my, mp, rayLength;
float rayX, rayY, rayAngle, xoffset, yoffset;
rayAngle = player->Angle - FOV / 2;
for (r = 0; r < NUM_RAYS; r++)
{
rayX = player->pos.x;
rayY = player->pos.y;
while (1)
{
mx = (int)rayX / TILE_SIZE;
my = (int)rayY / TILE_SIZE;
mp = (my *MAP_NUM_COLS) + mx;
if (mp > 0 && mp < MAP_NUM_COLS * MAP_NUM_ROWS && map[mp] == 1)
{
break;
}
rayX += cos(rayAngle) * 5;
rayY += sin(rayAngle) * 5;
}
SDL_SetRenderDrawColor(renderer, COLOR_RED.r, COLOR_RED.g,
COLOR_RED.b, COLOR_RED.a);
xoffset = rayX - player->pos.x;
yoffset = rayY - player->pos.y;
rayLength = sqrt(xoffset *xoffset + yoffset *yoffset);
SDL_RenderDrawLine(renderer, player->pos.x, player->pos.y,
player->pos.x + cos(rayAngle) * rayLength,
player->pos.y + sin(rayAngle) * rayLength);
rayAngle += FOV / NUM_RAYS;
}
}
