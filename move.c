#include "include/maze.h"

/**
 * forward - Moves the player forward.
 * @param player - The player
 * return void
 */

void forward(Player *player)
{
    char *cPoint = cardinalDirection(player);
    switch (cPoint[0])
    {
    case 'N':
        player->pos.p1.x += playerStep;
        player->pos.p2.x += playerStep;
        break;
    case 'E':
        player->pos.p1.y += playerStep;
        player->pos.p2.y += playerStep;
        break;
    case 'S':

        player->pos.p1.x -= playerStep;
        player->pos.p2.x -= playerStep;
        break;
    case 'W':

        player->pos.p1.y -= playerStep;
        player->pos.p2.y -= playerStep;
        break;
    default:
        break;
    }
}
/**
 * backward - Moves the player backward.
 * @param player - The player
 * return void
 *
*/

void backward(Player *player)
{
    char *cPoint = cardinalDirection(player);
    switch (cPoint[0])
    {
    case 'N':
        player->pos.p1.x -= playerStep;
        player->pos.p2.x -= playerStep;
        break;
    case 'E':
        player->pos.p1.y -= playerStep;
        player->pos.p2.y -= playerStep;
        break;
    case 'S':

        player->pos.p1.x += playerStep;
        player->pos.p2.x += playerStep;
        break;
    case 'W':

        player->pos.p1.y += playerStep;
        player->pos.p2.y += playerStep;
        break;
    default:
        break;
    }
}
/**
 * left - Moves the player left.
 * @param player - The player
 * return void
 *
*/

void left(Player *player)
{
    char *cPoint = cardinalDirection(player);
    switch (cPoint[0])
    {
    case 'N':
        player->pos.p1.y -= playerStep;
        player->pos.p2.y -= playerStep;
        break;
    case 'E':
        player->pos.p1.x += playerStep;
        player->pos.p2.x += playerStep;
        break;
    case 'S':

        player->pos.p1.y += playerStep;
        player->pos.p2.y += playerStep;
        break;
    case 'W':

        player->pos.p1.x -= playerStep;
        player->pos.p2.x -= playerStep;
        break;
    default:
        break;
    }
}
/**
 * right - Moves the player right.
 * @param player - The player
 * return void
 *
*/

void right(Player *player)
{
    char *cPoint = cardinalDirection(player);
    switch (cPoint[0])
    {
    case 'N':
        player->pos.p1.y += playerStep;
        player->pos.p2.y += playerStep;
        break;
    case 'E':
        player->pos.p1.x -= playerStep;
        player->pos.p2.x -= playerStep;
        break;
    case 'S':

        player->pos.p1.y -= playerStep;
        player->pos.p2.y -= playerStep;
        break;
    case 'W':

        player->pos.p1.x += playerStep;
        player->pos.p2.x += playerStep;
        break;
    default:
        break;
    }
}