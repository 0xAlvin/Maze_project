#include "include/maze.h"
#include "include/colors.h"
/**
 * createPlayer - Creates a player
 * @return Player - The player
*/
vector2D spwan = {200, 200};//spwan point

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
 * @param x - The x position
 * @param y - The y position
 * @param player - The player
 * @return int* - The players position
*/
int *playerPosition(Player player)
{
    int *pos = malloc(2 * sizeof(int));
    Player *pl = &player;
    pos[0] = pl.pos.p1.x;
    pos[1] = pl.pos.p1.y;
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
Player *movePlayer(Player *player,SDL_Point walls[wallmaxCount][2], int wallCount, int cmd)
{
    Player *pl = player;

    switch (cmd)
    {
    case 1:
        player->pos.p1.x += playerStep;
        player->pos.p2.x += playerStep;
        player->pos.p1.y -= playerStep;
        player->pos.p2.y -= playerStep;

        break;
    case 2:
        player->pos.p1.x += playerStep;
        player->pos.p2.x += playerStep;
        player->pos.p1.y += playerStep;
        player->pos.p2.y += playerStep;
        break;
    case 3:
        player->pos.p1.x -= playerStep;
        player->pos.p2.x -= playerStep;
        player->pos.p1.y += playerStep;
        player->pos.p2.y += playerStep;
        break;
    case 4:
        player->pos.p1.x -= playerStep;
        player->pos.p2.x -= playerStep;
        player->pos.p1.y -= playerStep;
        player->pos.p2.y -= playerStep;
        break;
    case 5:
        player->angle -= 10;
        break;
    case 6:
        player->angle += 10;
        break;
    case 7:
        player->pos.p1.y -= playerStep;
        player->pos.p2.y -= playerStep;
        break;
    case 8:
        player->pos.p1.y += playerStep;
        player->pos.p2.y += playerStep;
        break;
    case 9:
        player->pos.p1.x -= playerStep;
        player->pos.p2.x -= playerStep;
        break;
    case 10:
        player->pos.p1.x += playerStep;
        player->pos.p2.x += playerStep;
        break;
    default:
        break;
    }
        // Check collision with walls
    for (int i = 0; i < wallCount; i++)
    {
        if (CheckCollision(pl->pos.p1.x,pl->pos.p1.y, player->pos.p1.x, player->pos.p1.y, walls[i][0].x, walls[i][0].y, walls[i][1].x, walls[i][1].y))
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