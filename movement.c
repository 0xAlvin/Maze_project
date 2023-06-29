#include "include/maze.h"


// handle input
void eventHandler(SDL_Event *event, int *isRunning, Player *player)
{
    if (event->type == SDL_KEYDOWN)
    {
        const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);

        if (keyboardState[SDL_SCANCODE_UP] && keyboardState[SDL_SCANCODE_RIGHT])
        {
            player->pos.p1.x += 10;
            player->pos.p1.y -= 10;
        }
        else if (keyboardState[SDL_SCANCODE_DOWN] && keyboardState[SDL_SCANCODE_RIGHT])
        {
            player->pos.p1.x += 10;
            player->pos.p1.y += 10;
        }
        else if (keyboardState[SDL_SCANCODE_UP] && keyboardState[SDL_SCANCODE_LEFT])
        {
            player->pos.p1.x -= 10;
            player->pos.p1.y -= 10;
        }
        else if (keyboardState[SDL_SCANCODE_DOWN] && keyboardState[SDL_SCANCODE_LEFT])
        {
            player->pos.p1.x -= 10;
            player->pos.p1.y += 10;
        }
        else
        {
            switch (event->key.keysym.sym)
            {
            case SDLK_UP:
                player->pos.p1.y -= 10;
                break;
            case SDLK_DOWN:
                player->pos.p1.y += 10;
                break;
            case SDLK_LEFT:
                player->pos.p1.x -= 10;
                break;
            case SDLK_RIGHT:
                player->pos.p1.x += 10;
                break;
            default:
                break;
            }
        }
    }
}