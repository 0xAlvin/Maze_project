#include "../include/maze.h"
int mapX = 8, mapY = 8, mapS = 64;

// float pdx;
// float pdy;
int map[] = {
    1, 1, 1, 1, 1, 1, 1, 1, // 1 = wall
    1, 0, 0, 0, 0, 0, 0, 1, // 0 = space
    1, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 1, 1, 1, 1, 0, 1,
    1, 0, 1, 0, 0, 0, 0, 1,
    1, 0, 1, 0, 1, 1, 0, 1,
    1, 0, 0, 0, 1, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1};
void drawMap(SDL_Renderer *renderer)
{
    int x, y, xo, yo;
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
            xo = x * mapS;
            yo = y * mapS;
            SDL_Rect rect = {xo + 1, yo + 1, mapS - 1, mapS - 1};
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}
/**
 * drawRays - draw rays
 */
void drawRays(Player *player, SDL_Renderer *renderer)
{
    int r, mx, my, mp, dof;
    float rx, ry, ra, xo, yo;
    ra = player->Angle;
    for (r = 0; r < 1; r++)
    {
        dof = 0;
        float disH = 1000000, hx = player->pos.x, hy = player->pos.y;
        float aTan = -1 / tan(ra);
        if (ra > PI)
        {
            ry = (((int)player->pos.y / 64) * 64) - 0.0001;
            rx = (player->pos.y - ry) * aTan + player->pos.x;
            yo = -64;
            xo = -yo * aTan;
        }
        if (ra < PI)
        {
            ry = (((int)player->pos.y / 64) * 64) + 64;
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
            mx = (int)(rx) / 64;
            my = (int)(ry) / 64;
            mp = my * mapX + mx;
            if (mp > 0 && mp < mapX * mapY && map[mp] == 1) // hit wall
            {
                hx = rx;
                hy = ry;
                disH = distanceBetweenPoints(player->pos.x, player->pos.y, hx, hy);
                dof = 8;
            }
            else
            {
                rx += xo;
                ry += yo;
                dof += 1;
            }
        }

        dof = 0;
        float disV = 1000000, vx = player->pos.x, vy = player->pos.y;
        float nTan = -tan(ra);
        if (ra > P2 && ra < P3)
        {
            rx = (((int)player->pos.x / 64) * 64) - 0.0001;
            ry = (player->pos.x - rx) * nTan + player->pos.y;
            xo = -64;
            yo = -xo * nTan;
        }
        if (ra < P2 || ra > P3)
        {
            rx = (((int)player->pos.x / 64) * 64) + 64;
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
            mx = (int)(rx) / 64;
            my = (int)(ry) / 64;
            mp = my * mapX + mx;
            if (mp > 0 && mp < mapX * mapY && map[mp] == 1) // hit wall
            {
                vx = rx;
                vy = ry;
                disV = distanceBetweenPoints(player->pos.x, player->pos.y, vx, vy);
                dof = 8;
            }
            else
            {
                rx += xo;
                ry += yo;
                dof += 1;
            }
        }
        if (disV < disH)
        {
            rx = vx;
            ry = vy;
        }
        if (disH < disV)
        {
            rx = hx;
            ry = hy;
        }
        SDL_SetRenderDrawColor(renderer, COLOR_ORANGE.r, COLOR_ORANGE.g,
                               COLOR_ORANGE.b, COLOR_ORANGE.a);
        SDL_RenderDrawLine(renderer, player->pos.x, player->pos.y, rx, ry);
    }
}