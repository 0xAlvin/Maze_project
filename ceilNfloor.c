#include "include/maze.h"
#include "include/colors.h"

/*
* drawCeilFloor - Draws the ceiling and floor of the maze.
* @renderer: The SDL renderer to draw on.
* @x: The x-coordinate of the top-left corner of the rectangle.
* @y: The y-coordinate of the top-left corner of the rectangle.
* @w: The width of the rectangle.
* @h: The height of the rectangle.

*/

void drawCeilFloor(SDL_Renderer *renderer, SDL_Texture *textureFloor, SDL_Texture *textureCeil)
{
    SDL_Rect rect;
    // floor
    if (textureFloor != NULL) // applys a image texture passed as a parameter for the floor
    {
        rect.x = 0;
        rect.y = windowH / 2;
        rect.w = windowW;
        rect.h = windowH / 2;
        SDL_RenderDrawRect(renderer2, &rect);
        SDL_RenderCopy(renderer2, textureFloor, NULL, &rect);
    }
    else // applys a image texture passed as a parameter for the ceiling
    {
        rect.x = 0;
        rect.y = windowH / 2;
        rect.w = windowW;
        rect.h = windowH / 2;
        SDL_RenderDrawRect(renderer2, &rect);
        SDL_SetRenderDrawColor(renderer2, COLOR_BROWN.r, COLOR_BROWN.g, COLOR_BROWN.b, COLOR_BROWN.a); // creates a brown floor
        SDL_RenderFillRect(renderer2, &rect);
    }

    // ceiling
    if (textureCeil != NULL) // createas a blue ceiling
    {
        rect.x = 0;
        rect.y = 0;
        rect.w = windowW;
        rect.h = windowH / 2;
        SDL_RenderDrawRect(renderer2, &rect);
        SDL_RenderCopy(renderer2, textureCeil, NULL, &rect);
    }
    else
    {
        rect.x = 0;
        rect.y = 0;
        rect.w = windowW;
        rect.h = windowH / 2;
        SDL_RenderDrawRect(renderer2, &rect);
        SDL_SetRenderDrawColor(renderer, COLOR_BLUE.r, COLOR_BLUE.g, COLOR_BLUE.b, COLOR_BLUE.a);
        SDL_RenderFillRect(renderer2, &rect);
    }
}