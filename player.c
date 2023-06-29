#include "include/maze.h"
#include "include/colors.h"

vector2D spwan = {70, 70};


Player createPlayer(void)
{
    Player player;
    player.pos.p1.x = spwan.x;
    player.pos.p1.y = spwan.y;
    player.pos.p2.x = 0;//x-direction
    player.pos.p2.y = 0;//y-direction
    return player;
}

int* playerPosition(int x, int y,Player player)
{
    int* pos = malloc(2 * sizeof(int)); // Dynamically allocate memory
    pos[0] = player.pos.p1.x;
    pos[1] = player.pos.p1.y;
    return pos;
}
void drawPlayer(SDL_Renderer* renderer,Player* player)
{
    drawCircle(renderer, "GREEN", player->pos.p1.x, player->pos.p1.y, 10);
}