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
SDL_Rect playerRect = {
(int)player->pos.x,
(int)player->pos.y,
(int)player->size.x,
(int)player->size.y
};
SDL_SetRenderDrawColor(renderer, COLOR_GREEN.r, COLOR_GREEN.g,
COLOR_GREEN.b, COLOR_GREEN.a);
SDL_RenderFillRect(renderer, &playerRect);
/*SDL_RenderPresent(renderer);*/
}
