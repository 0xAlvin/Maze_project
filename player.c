#include "include/maze.h"
#include "include/colors.h"
/**
 * createPlayer - Creates a player
 * @return Player - The player
 */

vector2D spwan = {(windowW - 250), 30}; // spwan point

Player *createPlayer()
{
    Player *player = malloc(sizeof(Player)); // Dynamically allocate memory
    player->pos.p1.x = spwan.x;
    player->pos.p1.y = spwan.y;
    player->pos.p2.x = spwan.x;        // x-direction
    player->pos.p2.y = (spwan.y) + 20; // y-direction
    return player;
}

/**
 * playerPosition - Returns the players position
 * @param player - The player
 * @return int* - The players position
 */
int *playerPosition(Player player)
{
    int *pos = malloc(2 * sizeof(int));
    Player *pl = &player;
    pos[0] = pl->pos.p1.x;
    pos[1] = pl->pos.p1.y;
    return pos;
}

/**
 * drawPlayer - Draws the player on the screen
 * @param renderer - The renderer to draw to
 * @param player - The player to draw
 * @return void
 */
void drawPlayer(SDL_Renderer *renderer, Player *player)
{
    SDL_SetRenderDrawColor(renderer, COLOR_YELLOW.r, COLOR_BLUE.g, COLOR_BLACK.b, COLOR_GREEN.a);
    SDL_Point target = CreateTarget(player->pos.p1.x, player->pos.p1.y, player->angle, 20); // Calculate the end of the line used to indicate the players direction
    drawCircle(renderer, "GREEN", player->pos.p1.x, player->pos.p1.y, 10);
    SDL_RenderDrawLine(renderer, player->pos.p1.x, player->pos.p1.y, target.x, target.y);
}

/**
 * movePlayer - Moves the player
 * @param player - The player to move
 * @param walls - The walls to check for collision
 * @param wallCount - The number of walls
 * @param cmd - The command to move the player ->int taken as parameter from events.c keypress
 */
Player *movePlayer(Player *player, SDL_Point walls[wallmaxCount][2], int wallCount, int cmd)
{
    Player *pl = player; //(PL) is a pointer to player

    switch (cmd)
    {
    case 1: // up amd right
        forward(pl);
        right(pl);
        break;
    case 2: // down and right
        backward(pl);
        right(pl);
        break;
    case 3: // up and left
        forward(pl);
        left(pl);
        break;
    case 4: // down and left
        backward(pl);
        left(pl);
        break;
    case 5: // rotate left
        player->angle -= TURN_ANGLE;
        if (player->angle < 0)
        {
            player->angle = 360;
        }
        break;
    case 6: // rotate right
        player->angle += TURN_ANGLE;
        if (player->angle > 360)
        {
            player->angle = 0;
        }
        break;
    case 7: // up
        forward(pl);
        break;
    case 8: // down
        backward(pl);
        break;
    case 9: // left
        left(pl);
        break;
    case 10: // right
        right(pl);
        break;
    default:
        break;
    }
    // Check collision with walls
    for (int i = 0; i < wallCount; i++)
    {
        if (CheckCollision(pl->pos.p1.x, pl->pos.p1.y, player->pos.p1.x, player->pos.p1.y, walls[i][0].x, walls[i][0].y, walls[i][1].x, walls[i][1].y))
        {
            // Collision detected, do not update player position
            return pl;
        }
    }
    return player;
}

/**
 * CheckCollision - Checks if two lines intersect
 * @param x1 - The start x position of the first line
 * @param y1 - The start y position of the first line
 * @param x2 - The end x position of the first line
 * @param y2 - The end y position of the first line
 * @param x3 - The start x position of the second line
 * @param y3 - The start y position of the second line
 * @param x4 - The end x position of the second line
 * @param y4 - The end y position of the second line
 * @return int - 1 if the lines intersect, 0 otherwise
 */
int CheckCollision(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    int denom = (y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1);
    int num1 = (x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3);
    int num2 = (x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3);

    if (denom == 0)
    {
        if (num1 == 0 && num2 == 0)
        {
            // Lines are coincident
            return 1;
        }
        // Lines are parallel
        return 0;
    }

    float r = (float)num1 / denom;
    float s = (float)num2 / denom;

    if (r >= 0 && r <= 1 && s >= 0 && s <= 1)
    {
        // Collision detected
        return 1;
    }

    // No collision
    return 0;
}