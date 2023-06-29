#include "include/maze.h"
/**
 * ray - Creates a vector2D with the given x and y coordinates.
 * @x: The x-coordinate.
 * @y: The y-coordinate.
 *
 * Return: void.
 */
vector2D* ray(int x, int y,int dx,int dy)
{
    vector2D pos, dir;
    vector2D* rayc = malloc(2 * sizeof(vector2D)); // Dynamically allocate memory

    if (rayc == NULL) {
        // Handle allocation failure
        return NULL;
    }

    pos.x = x;
    pos.y = y;

    dir.x = dx;
    dir.y = dy;

    rayc[0] = pos;
    rayc[1] = dir;
    
    return rayc;
}
void raycast(SDL_Renderer* renderer, Player* player)
{
    vector2D* rayc = ray(player->pos.p1.x, player->pos.p1.y, player->pos.p2.x, player->pos.p2.y);
    int x1 = rayc[0].x;
    int y1 = rayc[0].y;
    int x2 = rayc[1].x;
    int y2 = rayc[1].y;
    wall(renderer, x1, y1, x2*10, y2*10);
    free(rayc);
}