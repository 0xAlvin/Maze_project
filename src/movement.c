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
player->pos.x += player->dir.x * PLAYER_SPEED;
player->pos.y += player->dir.y * PLAYER_SPEED;
break;
case SDLK_DOWN:
player->pos.x -= player->dir.x * PLAYER_SPEED;
player->pos.y -= player->dir.y * PLAYER_SPEED;
break;
case SDLK_LEFT:
player->pos.x -= PLAYER_SPEED;
break;
case SDLK_RIGHT:
player->pos.x += PLAYER_SPEED;
break;
case SDLK_a:
player->Angle -= 0.1;
if (player->Angle < 0)
{
player->Angle += 2 * PI;
}
player->dir.x = cos(player->Angle) * 5;
player->dir.y = sin(player->Angle) * 5;
break;
case SDLK_d:
player->Angle += 0.1;
if (player->Angle > 2 * PI)
{
player->Angle -= 2 * PI;
}
player->dir.x = cos(player->Angle) * 5;
player->dir.y = sin(player->Angle) * 5;
break;
default:
break;
}
}
