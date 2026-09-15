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

#define WALL_TIE_EPSILON 3
#define PARALLEL_EPSILON 1e-9

void drawRays(SDL_Renderer *renderer, SDL_Renderer *renderer2, Player *player, SDL_Point walls[200][2], int wallCount)
{
    SDL_Rect rect;
    rect.w = 2;

    for (int screenX = 0; screenX < windowW; screenX++)
    {
        double a = player->angle - fov / 2.0 + (screenX * (double)fov) / windowW;
        double rad = DEG2RAD(a);
        double dx = cos(rad);
        double dy = sin(rad);

        double px = player->pos.p1.x;
        double py = player->pos.p1.y;

        double closestX = px + dx * viewRange;
        double closestY = py + dy * viewRange;
        double closestDistance = viewRange;
        int hit = 0;

        for (int i = 0; i < wallCount; i++)
        {
            double x1 = walls[i][0].x, y1 = walls[i][0].y;
            double x2 = walls[i][1].x, y2 = walls[i][1].y;

            double sx = x2 - x1;
            double sy = y2 - y1;

            double det = dx * sy - dy * sx;

            // Skip rays that are (near-)parallel to this wall instead of
            // dividing by a near-zero determinant, which amplifies error.
            if (fabs(det) < PARALLEL_EPSILON)
                continue;

            double ddx = x1 - px;
            double ddy = y1 - py;

            double t = (ddx * sy - ddy * sx) / det; // distance along the ray
            double u = (ddx * dy - ddy * dx) / det; // position along the wall segment [0,1]

            if (t >= 0 && t <= viewRange && u >= 0.0 && u <= 1.0)
            {
                if (t < closestDistance - WALL_TIE_EPSILON)
                {
                    closestDistance = t;
                    closestX = px + dx * t;
                    closestY = py + dy * t;
                    hit = 1;
                }
            }
        }

        if (hit)
        {
            float correctedDistance = (float)(closestDistance * fabs(cos(DEG2RAD(a - player->angle))));
            if (correctedDistance < 1.0f)
                correctedDistance = 1.0f;

            SDL_SetRenderDrawColor(renderer, COLOR_DARK_GRAY.r, COLOR_DARK_GRAY.g, COLOR_DARK_GRAY.b, COLOR_DARK_GRAY.a);
            SDL_RenderDrawLine(renderer, (int)px, (int)py, (int)closestX, (int)closestY);

            float wallHeight = (windowH * 0.9f * 50.0f) / correctedDistance;
            

            if (wallHeight > windowH)
                wallHeight = windowH;

            rect.x = screenX;
            rect.y = (windowH - wallHeight) / 2;
            rect.h = wallHeight;

            int brightness = 255 - correctedDistance / 2.5f;
            if (brightness < 0)
                brightness = 0;
            SDL_SetRenderDrawColor(renderer2, brightness, brightness, brightness, 255);
            SDL_RenderFillRect(renderer2, &rect);
            SDL_SetRenderDrawColor(renderer2, COLOR_BLACK.r, COLOR_BLACK.g, COLOR_BLACK.b, COLOR_BLACK.a);
        }
    }
}

SDL_Point CreateTarget(int x, int y, double dir, int dist)
{
    SDL_Point target;

    double translated = DEG2RAD(dir);
    target.x = round(x + dist * cos(translated));
    target.y = round(y + dist * sin(translated));

    return target;
}

int PointOnLine(int x1, int y1, int x2, int y2, int tx, int ty)
{
    if (fmin(x1, x2) <= tx && tx <= fmax(x1, x2) && fmin(y1, y2) <= ty && ty <= fmax(y1, y2))
    {
        return true;
    }

    return false;
}

int PointOnLineF(int x1, int y1, int x2, int y2, float tx, float ty)
{
    float eps = 0.5f;
    if (fmin(x1, x2) - eps <= tx && tx <= fmax(x1, x2) + eps &&
        fmin(y1, y2) - eps <= ty && ty <= fmax(y1, y2) + eps)
    {
        return true;
    }

    return false;
}

int PointDistance(int x1, int y1, int x2, int y2)
{
    int out = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return out;
}

float PointDistanceF(int x1, int y1, float x2, float y2)
{
    return sqrt(pow((float)x2 - x1, 2) + pow((float)y2 - y1, 2));
}