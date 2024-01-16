#include "../include/maze.h"

/**
 * init_ - initialize SDL
 * Return: 0 on success
*/

int init_(void)
{
/*Initialize SDL*/
if (SDL_Init(SDL_INIT_VIDEO) != 0)
{
fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
return (1);
}
return (0);
}

/**
 * createWindow - create window
 * Return: renderer
*/
SDLResources *createWindow(void)
{
/*Create window & renderer*/
SDL_Window *window = SDL_CreateWindow("Maze",
SDL_WINDOWPOS_UNDEFINED,
SDL_WINDOWPOS_UNDEFINED,
SCREEN_WIDTH,
SCREEN_HEIGHT,
SDL_WINDOW_SHOWN);
SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
SDL_RENDERER_ACCELERATED);
SDLResources *resources = malloc(sizeof(SDLResources));
resources->window = window;
resources->renderer = renderer;

return (resources);
}
