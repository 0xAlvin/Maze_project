#include "include/maze.h"
#include "include/colors.h"

/**
 * drawRays - Draws the rays on the screen
 * @param renderer - The renderer to draw to
 * @param player - The player to draw the rays from
 * @param walls - The walls to draw the rays to
 * @param wallCount - The number of walls
 * @return void
 */

void drawRays(SDL_Renderer *renderer, SDL_Renderer *renderer2, Player *player, SDL_Point walls[200][2], int wallCount)
{
    SDL_Point target;
    SDL_Point closest;
    SDL_Rect rect;
    SDL_Surface *surface = createPlusTexture(0, 0);
    SDL_Texture *t = SDL_CreateTextureFromSurface(renderer2, surface); // creates brown texture

    // The thickness the bars can be based on the window width
    int rayPreviewrenstep = windowW * 1.15 / fov;
    int rayCount = 0;
    int closestDistance;
    rect.w = rayPreviewrenstep; // We can pre calculate the width as this is a constant

    // Loop for each ray in fov at 1 degree step
    for (int a = player->angle - fov / 2; a < player->angle + fov / 2; a++)
    {
        rayCount++;
        target = CreateTarget(player->pos.p1.x, player->pos.p1.y, a, viewRange); // Find the point at wich the ray is out of view distance
        closest = target;
        closestDistance = viewRange;

        // Loop over each wall
        for (int i = 0; i < wallCount; i++)
        {
            // Find the intersection point
            float a1 = target.y - player->pos.p1.y;
            float b1 = player->pos.p1.x - target.x;
            float c1 = a1 * player->pos.p1.x + b1 * player->pos.p1.y;

            float a2 = walls[i][1].y - walls[i][0].y;
            float b2 = walls[i][0].x - walls[i][1].x;
            float c2 = a2 * walls[i][0].x + b2 * walls[i][0].y;

            float det = a1 * b2 - a2 * b1;

            // If its not parallel
            if (det != 0)
            {
                int x = (b2 * c1 - b1 * c2) / det;
                int y = (a1 * c2 - a2 * c1) / det;

                // If the point falls inside the wall and the ray
                if (PointOnLine(player->pos.p1.x, player->pos.p1.y, target.x, target.y, x, y) &&
                    PointOnLine(walls[i][0].x, walls[i][0].y, walls[i][1].x, walls[i][1].y, x, y))
                {
                    // Calculate the distance to the point
                    int dist = PointDistance(player->pos.p1.x, player->pos.p1.y, x, y);

                    // If its the closest wall, store it
                    if (dist < closestDistance)
                    {
                        closest.x = x;
                        closest.y = y;
                        closestDistance = dist;
                    }
                }
            }
        }

        // If the ray hit something
        if (closestDistance != viewRange)
        {
            // Draw the ray
            SDL_SetRenderDrawColor(renderer, COLOR_DARK_GRAY.r, COLOR_DARK_GRAY.g, COLOR_DARK_GRAY.b, COLOR_DARK_GRAY.a);
            SDL_RenderDrawLine(renderer, player->pos.p1.x, player->pos.p1.y, closest.x, closest.y);

            // Draw the 3d preview
            // correct vision

            rect.x = rayPreviewrenstep * rayCount + (windowW - 900) / 3;
            rect.y = closestDistance / 2;
            rect.h = windowH - rect.y * 2;

            int brightness = 255 - closestDistance / 2;
            SDL_SetRenderDrawColor(renderer2, brightness, brightness, brightness, 255);
            SDL_RenderFillRect(renderer2, &rect);
            // SDL_RenderCopy(renderer2, t, NULL, &rect);
            SDL_SetRenderDrawColor(renderer2, COLOR_BLACK.r, COLOR_BLACK.g, COLOR_BLACK.b, COLOR_BLACK.a);
        }
    }
}

/**
 * CreateTarget - Creates a point dist pixels away in dir direction from x and y
 * @param x - The x coordinate to start from
 * @param y - The y coordinate to start from
 * @param dir - The direction to go in
 * @param dist - The distance to go
 * @return SDL_Point - The point dist pixels away in dir direction from x and y
 */
SDL_Point CreateTarget(int x, int y, int dir, int dist)
{
    // Create a point dist pixels away in dir direction from x and y
    SDL_Point target;

    double translated = DEG2RAD(dir); // Convert to radians
    target.x = round(x + dist * cos(translated));
    target.y = round(y + dist * sin(translated));

    return target;
}

/**
 * PointOnLine - Checks if a point is on a line segment
 * @param x1 - The x coordinate of the first point of the line
 * @param y1 - The y coordinate of the first point of the line
 * @param x2 - The x coordinate of the second point of the line
 * @param y2 - The y coordinate of the second point of the line
 * @param tx - The x coordinate of the point to check
 * @param ty - The y coordinate of the point to check
 * @return int - 1 if the point is on the line, 0 if not
 */
int PointOnLine(int x1, int y1, int x2, int y2, int tx, int ty)
{
    // Check if a point is on a line segment
    if (fmin(x1, x2) <= tx && tx <= fmax(x1, x2) && fmin(y1, y2) <= ty && ty <= fmax(y1, y2))
    {
        return true;
    }

    return false;
}

/**
 * PointDistance - Finds the distance between two points
 * @param x1 - The x coordinate of the first point
 * @param y1 - The y coordinate of the first point
 * @param x2 - The x coordinate of the second point
 * @param y2 - The y coordinate of the second point
 * @return int - The distance between the two points
 */
int PointDistance(int x1, int y1, int x2, int y2)
{
    // Find the distance between two points
    int out = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return out;
}
