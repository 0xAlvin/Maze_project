#include"../include/maze.h"
/**
 * move - moves the player
 * @player: player
 * @keypress: keypress
*/
void move(Player *player, SDL_Event keypress)
{
switch (keypress.key.keysym.sym)
{
case SDLK_UP:
player->pos.y -= PLAYER_SPEED;
break;
case SDLK_DOWN:
player->pos.y += PLAYER_SPEED;
break;
case SDLK_LEFT:
player->pos.x -= PLAYER_SPEED;
break;
case SDLK_RIGHT:
player->pos.x += PLAYER_SPEED;
break;
default:
break;
}
}
