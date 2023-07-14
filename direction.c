#include "include/maze.h"

/**
 * cardinalDirection - Returns the cardinal direction the player is facing (N,E,S,W).
 * @param player - The player
 * @return char* - The cardinal point
 *
*/

char *cardinalDirection(Player *player)
{
    int angle = player->angle;
    int direction = 0;
    if ((angle >= 315 && angle <= 360) || (angle >= 0 && angle < 45))
    {
        direction = 0;
    }
    else if (angle >= 45 && angle <= 135)
    {
        direction = 1;
    }
    else if (angle >= 135 && angle <= 225)
    {
        direction = 2;
    }
    else if (angle >= 225 && angle <= 315)
    {
        direction = 3;
    }

    switch (direction)
    {
    case 0:
        return "N";//north
    case 1:
        return "E";//east
    case 2:
        return "S";//south
    case 3:
        return "W";//west
    default:
        return "N";//north
    }
}
