#include "include/maze.h"
#include "include/colors.h"
/**
 * crossHair - Draws a crosshair on the renderer.
 * @param renderer: The SDL renderer to draw on.
 * @param window: The SDL window to draw on.
*/
void crossHair(SDL_Renderer *renderer, SDL_Window *window)
{
// Get the window size
    int windowWidth, windowHeight;
    SDL_GetWindowSize(window, &windowWidth, &windowHeight);

    // Calculate the center coordinates of the window
    int centerX = windowWidth / 2;
    int centerY = windowHeight / 2;

    // Define the size and thickness of the crosshair lines
    int crosshairSize = 15;

    // Set the draw color for the crosshair lines (red with transparency)
    SDL_SetRenderDrawColor(renderer, COLOR_RED.r, COLOR_RED.g, COLOR_RED.b, COLOR_RED.a);

    // Draw the vertical line of the crosshair
    SDL_RenderDrawLine(renderer, centerX, centerY - crosshairSize, centerX, centerY + crosshairSize);

    // Draw the horizontal line of the crosshair
    SDL_RenderDrawLine(renderer, centerX - crosshairSize, centerY, centerX + crosshairSize, centerY);
}