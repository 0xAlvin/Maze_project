#include "../include/maze.h"
/**
 * drawPlayer - draw player
 * @player: player
 * @renderer: renderer
 */
void drawPlayer(Player *player, SDL_Renderer *renderer)
{
    player->size.x = PLAYER_SIZE;
    player->size.y = PLAYER_SIZE;
    player->height = 32;
    SDL_Rect playerRect = {
        (int)player->pos.x - (int)player->size.x / 2,
        (int)player->pos.y - (int)player->size.y / 2,
        (int)player->size.x,
        (int)player->size.y};
    SDL_SetRenderDrawColor(renderer, COLOR_GREEN.r, COLOR_GREEN.g,
                           COLOR_GREEN.b, COLOR_GREEN.a);
    SDL_RenderFillRect(renderer, &playerRect);
    int linewidth = 3;
    for (int i = 0; i < linewidth; i++)
    {
        drawLine(renderer, player->pos.x, player->pos.y + i,
                 player->pos.x + player->dir.x * 5,
                 player->pos.y + player->dir.y * 5 + i);
    }
}
