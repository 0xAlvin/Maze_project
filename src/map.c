#include "../include/maze.h"

int mapX = 8, mapY = 8, mapS = 64;
int map[] = {
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 1, 1, 1, 1, 0, 1,
    1, 0, 1, 0, 0, 0, 0, 1,
    1, 0, 1, 0, 1, 1, 1, 1,
    1, 0, 1, 0, 1, 0, 0, 1,
    1, 0, 0, 0, 1, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1};

/**
 * drawMap - create a map
 * @renderer: renderer
 */
void drawMap(SDL_Renderer *renderer)
{

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

/**
 * drawRays - draw rays
 * @player: player
 * @renderer: renderer
 */

void drawRays(Player *player, SDL_Renderer *renderer)
{
    int r, mx, my, mp, dof;
    float rx, ry, ra, xo, yo;
    ra = player->Angle;
    for (r = 0; r < 1; r++)
    {
        dof = 0;
        float aTan = -1 / tan(ra);
        if (ra > PI)
        {
            ry = (((int)player->pos.y >> 6) << 6) - 0.0001;
            rx = (player->pos.y - ry) * aTan + player->pos.x;
            yo = -64;
            xo = -yo * aTan;
        }
        if (ra < PI)
        {
            ry = (((int)player->pos.y >> 6) << 6) + 64;
            rx = (player->pos.y - ry) * aTan + player->pos.x;
            yo = 64;
            xo = -yo * aTan;
        }
        if (ra == 0 || ra == PI)
        {
            rx = player->pos.x;
            ry = player->pos.y;
            dof = 8;
        }
        while (dof < 8)
        {
            mx = (int)(rx) >> 6;
            my = (int)(ry) >> 6;
            mp = my * mapX + mx;

            if (mp > 0 && mp < mapX * mapY && map[mp] == 1)
            {
                dof = 8;
            }
            else
            {
                rx += xo;
                ry += yo;
                dof += 1;
            }
        }
        drawLine(renderer, player->pos.x, player->pos.y, rx, ry);

        dof = 0;
        float nTan = -1 / tan(ra);
        if (ra > P2 && ra < P3)
        {
            rx = (((int)player->pos.x >> 6) << 6) - 0.0001;
            ry = (player->pos.x - rx) * nTan + player->pos.y;
            xo = -64;
            yo = -xo * nTan;
        }
        if (ra < P2 || ra > P3)
        {
            rx = (((int)player->pos.x >> 6) << 6) + 64;
            ry = (player->pos.x - rx) * nTan + player->pos.y;
            xo = 64;
            yo = -xo * nTan;
        }
        if (ra == 0 || ra == PI)
        {
            rx = player->pos.x;
            ry = player->pos.y;
            dof = 8;
        }
        while (dof < 8)
        {
            mx = (int)(rx) >> 6;
            my = (int)(ry) >> 6;
            mp = my * mapX + mx;

            if (mp > 0 && mp < mapX * mapY && map[mp] == 1)
            {
                dof = 8;
            }
            else
            {
                rx += xo;
                ry += yo;
                dof += 1;
            }
        }
        SDL_SetRenderDrawColor(renderer, COLOR_RED.r, COLOR_RED.g,
                               COLOR_RED.b, COLOR_RED.a);
        drawLine(renderer, player->pos.x, player->pos.y, rx, ry);
    }
}