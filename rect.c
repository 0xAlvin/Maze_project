#include "include/maze.h"
#include "include/colors.h"

/**
 * rect - Draws a rectangle on the renderer using the specified color.
 * @renderer: The SDL renderer to draw on.
 * @colorname: The name of the color to use for drawing the rectangle.
 * @w: The width of the rectangle.
 * @h: The height of the rectangle.
 *
 * This function draws a rectangle on the specified renderer using the specified color.
 * The colorname parameter should be one of the supported color names: RED, GREEN,
 * BLUE, YELLOW, WHITE, or BLACK.
 */
SDL_Rect drawRect(SDL_Renderer *renderer, const char *colorname, int x, int y, int w, int h)
{
    char color[20];
    sprintf(color, "COLOR_%s", colorname);

    if (strcmp(colorname, "RED") == 0) {
        SDL_SetRenderDrawColor(renderer, COLOR_RED.r, COLOR_RED.g, COLOR_RED.b, COLOR_RED.a);
    } else if (strcmp(colorname, "GREEN") == 0) {
        SDL_SetRenderDrawColor(renderer, COLOR_GREEN.r, COLOR_GREEN.g, COLOR_GREEN.b, COLOR_GREEN.a);
    } else if (strcmp(colorname, "BLUE") == 0) {
        SDL_SetRenderDrawColor(renderer, COLOR_BLUE.r, COLOR_BLUE.g, COLOR_BLUE.b, COLOR_BLUE.a);
    } else if (strcmp(colorname, "YELLOW") == 0) {
        SDL_SetRenderDrawColor(renderer, COLOR_YELLOW.r, COLOR_YELLOW.g, COLOR_YELLOW.b, COLOR_YELLOW.a);
    } else if (strcmp(colorname, "WHITE") == 0) {
        SDL_SetRenderDrawColor(renderer, COLOR_WHITE.r, COLOR_WHITE.g, COLOR_WHITE.b, COLOR_WHITE.a);
    } else if (strcmp(colorname, "BLACK") == 0) {
        SDL_SetRenderDrawColor(renderer, COLOR_BLACK.r, COLOR_BLACK.g, COLOR_BLACK.b, COLOR_BLACK.a);
    } else if (strcmp(colorname, "WHITE") == 0) {
        SDL_SetRenderDrawColor(renderer, COLOR_WHITE.r, COLOR_WHITE.g, COLOR_WHITE.b, COLOR_WHITE.a);
    } else {
        SDL_SetRenderDrawColor(renderer, COLOR_CLEAR.r, COLOR_CLEAR.g, COLOR_CLEAR.b, COLOR_CLEAR.a);
    }

    // Draw a rectangle with the specified color
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_Rect rect = { x, y, w, h };
    SDL_RenderFillRect(renderer, &rect);
    return rect;
}