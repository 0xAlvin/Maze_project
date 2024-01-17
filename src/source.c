/**
 * main - entry point
 * Return: 0 on success
 */
#include "../include/maze.h"

int main(void)
{
    init_();
    /*TTF_Font *font = TTF_OpenFont("../assets/font/font.ttf", 25);*/
    SDLResources *sdlResources = createWindow();
    Point spawn = {40, 40};
    Player *player = malloc(sizeof(Player));
    player->pos = spawn;
    player->dir.x = cos(player->Angle) * 5;
    player->dir.y = sin(player->Angle) * 5;
    /*Loop*/
    int running = true;
    SDL_Event event;

    while (running)
    {

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
            if (event.type == SDL_KEYDOWN)
            {
                move(player, event);
            }

            drawMap(sdlResources->renderer);
            drawRays(player, sdlResources->renderer);
            drawPlayer(player, sdlResources->renderer);

            /*Clear screen*/
            clear(sdlResources->renderer);
        }
    }

    /*On Exit*/
    free(player);
    cleanUp(sdlResources->renderer, sdlResources->window);
    // free(sdlResources);
    return (0);
}
