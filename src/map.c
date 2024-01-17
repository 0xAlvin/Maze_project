#include "../include/maze.h"

int map[mapX][mapX] =
    {
        {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 4, 4, 6, 4, 4, 6, 4, 6, 4, 4, 4, 6, 4},
        {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
        {8, 0, 3, 3, 0, 0, 0, 0, 0, 8, 8, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
        {8, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
        {8, 0, 3, 3, 0, 0, 0, 0, 0, 8, 8, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
        {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 4, 0, 0, 0, 0, 0, 6, 6, 6, 0, 6, 4, 6},
        {8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 4, 6, 0, 0, 0, 0, 0, 6},
        {7, 7, 7, 7, 0, 7, 7, 7, 7, 0, 8, 0, 8, 0, 8, 0, 8, 4, 0, 4, 0, 6, 0, 6},
        {7, 7, 0, 0, 0, 0, 0, 0, 7, 8, 0, 8, 0, 8, 0, 8, 8, 6, 0, 0, 0, 0, 0, 6},
        {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 6, 0, 0, 0, 0, 0, 4},
        {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 6, 0, 6, 0, 6, 0, 6},
        {7, 7, 0, 0, 0, 0, 0, 0, 7, 8, 0, 8, 0, 8, 0, 8, 8, 6, 4, 6, 0, 6, 6, 6},
        {7, 7, 7, 7, 0, 7, 7, 7, 7, 8, 8, 4, 0, 6, 8, 4, 8, 3, 3, 3, 0, 3, 3, 3},
        {2, 2, 2, 2, 0, 2, 2, 2, 2, 4, 6, 4, 0, 0, 6, 0, 6, 3, 0, 0, 0, 0, 0, 3},
        {2, 2, 0, 0, 0, 0, 0, 2, 2, 4, 0, 0, 0, 0, 0, 0, 4, 3, 0, 0, 0, 0, 0, 3},
        {2, 0, 0, 0, 0, 0, 0, 0, 2, 4, 0, 0, 0, 0, 0, 0, 4, 3, 0, 0, 0, 0, 0, 3},
        {1, 0, 0, 0, 0, 0, 0, 0, 1, 4, 4, 4, 4, 4, 6, 0, 6, 3, 3, 0, 0, 0, 3, 3},
        {2, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 1, 2, 2, 2, 6, 6, 0, 0, 5, 0, 5, 0, 5},
        {2, 2, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 2, 2, 0, 5, 0, 5, 0, 0, 0, 5, 5},
        {2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 5, 0, 5, 0, 5, 0, 5, 0, 5},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
        {2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 5, 0, 5, 0, 5, 0, 5, 0, 5},
        {2, 2, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 2, 2, 0, 5, 0, 5, 0, 0, 0, 5, 5},
        {2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 5, 5, 5, 5, 5, 5, 5, 5, 5}};

void drawMap(SDL_Renderer *renderer)
{
    SDL_Rect rect;
    rect.w = TILE_SIZE;
    rect.h = TILE_SIZE;
    for (int i = 0; i < mapX; i++)
    {
        for (int j = 0; j < mapY; j++)
        {
            rect.x = i * TILE_SIZE;
            rect.y = j * TILE_SIZE;
            switch (map[j][i])
            {
            case 0:
                SDL_SetRenderDrawColor(renderer, COLOR_BLACK.r, COLOR_BLACK.g,
                                       COLOR_BLACK.b, COLOR_BLACK.a);
                break;
            case 1:
                SDL_SetRenderDrawColor(renderer, COLOR_RED.r, COLOR_RED.g, COLOR_RED.b,
                                       COLOR_RED.a);
                break;
            case 2:
                SDL_SetRenderDrawColor(renderer, COLOR_GREEN.r, COLOR_GREEN.g,
                                       COLOR_GREEN.b, COLOR_GREEN.a);
                break;
            case 3:
                SDL_SetRenderDrawColor(renderer, COLOR_BLUE.r, COLOR_BLUE.g,
                                       COLOR_BLUE.b, COLOR_BLUE.a);
                break;
            case 4:
                SDL_SetRenderDrawColor(renderer, COLOR_WHITE.r, COLOR_WHITE.g,
                                       COLOR_WHITE.b, COLOR_WHITE.a);
                break;
            case 5:
                SDL_SetRenderDrawColor(renderer, COLOR_YELLOW.r, COLOR_YELLOW.g,
                                       COLOR_YELLOW.b, COLOR_YELLOW.a);
                break;
            case 6:
                SDL_SetRenderDrawColor(renderer, COLOR_ORANGE.r, COLOR_ORANGE.g,
                                       COLOR_ORANGE.b, COLOR_ORANGE.a);
                break;
            case 7:
                SDL_SetRenderDrawColor(renderer, COLOR_PURPLE.r, COLOR_PURPLE.g,
                                       COLOR_PURPLE.b, COLOR_PURPLE.a);
                break;
            case 8:
                SDL_SetRenderDrawColor(renderer, COLOR_BROWN.r, COLOR_BROWN.g,
                                       COLOR_BROWN.b, COLOR_BROWN.a);
                break;
            default:
                break;
            }
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}
void drawRays(Player *player, SDL_Renderer *renderer)
{
    float rayLength = 100000;
    float ra, rx, ry, xo, yo;
    ra = player->Angle - FOV / 2; if (ra < 0) { ra += 2 * PI; } if (ra > 2 * PI) { ra -= 2 * PI; }
    rx = player->pos.x; ry = player->pos.y;
    xo = cos(ra) * rayLength; yo = sin(ra) * rayLength;
    SDL_SetRenderDrawColor(renderer, COLOR_GREEN.r, COLOR_GREEN.g, COLOR_GREEN.b, COLOR_GREEN.a);

    //draw rays
    for (int i = 0; i < 50; i++)
    {
        SDL_RenderDrawLine(renderer, rx, ry, rx + xo, ry + yo);
        ra += FOV / NUM_RAYS;
        if (ra < 0) { ra += 2 * PI; } if (ra > 2 * PI) { ra -= 2 * PI; }
        xo = cos(ra) * rayLength; yo = sin(ra) * rayLength;
    }
}