#include "../include/maze.h"
/**
 * drawRays - draw rays
 * @player: player
 * @renderer: renderer
 */
void drawRays(Player *player, SDL_Renderer *renderer)
{
    int r, mx, my, mp, rayLength;
    float rayX, rayY, rayAngle, xoffset, yoffset;
    rayAngle = player->Angle;
    for (r = 0; r < NUM_RAYS; r++)
    {
        rayLength = 0;
        float aTan = -1 / tan(rayAngle);
        if (rayAngle > PI)
        {
            rayY = (((int)player->pos.y >> 6) << 6) - 0.0001;
            rayX = (player->pos.y - rayY) * aTan + player->pos.x;
            yoffset = -64;
            xoffset = -yoffset * aTan;
        }
        if (rayAngle < PI)
        {
            rayY = (((int)player->pos.y >> 6) << 6) + 64;
            rayX = (player->pos.y - rayY) * aTan + player->pos.x;
            yoffset = 64;
            xoffset = -yoffset * aTan;
        }
        if (rayAngle == 0 || rayAngle == PI)
        {
            rayX = player->pos.x;
            rayY = player->pos.y;
            rayLength = 8;
        }
        while (rayLength < 8)
        {
            mx = (int)(rayX) >> 6;
            my = (int)(rayY) >> 6;
            mp = my * mapX + mx;
            int *mptr = map;
            if (mp < mapX * mapY && mp >= 0 && mptr[mp] == 1)
            {
                rayLength = 8;
            }
            else
            {
                rayX += xoffset;
                rayY += yoffset;
                rayLength += 1;
            }
            drawLine(renderer, player->pos.x, player->pos.y, rayX, rayY);
        }
    }
}
