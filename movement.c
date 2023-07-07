#include "include/maze.h"
int open = false;
// handle input
void eventHandler(SDL_Event *event, int *isRunning, Player *player, SDL_Point walls[wallmaxCount][2], int wallCount)
{
    if (event->type == SDL_KEYDOWN)
    {
        const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);

        if ((keyboardState[SDL_SCANCODE_UP] && keyboardState[SDL_SCANCODE_RIGHT]) && (player->pos.p1.y) < windowH)
        {
            movePlayer(player, walls, wallCount,1);
        }
        else if (keyboardState[SDL_SCANCODE_DOWN] && keyboardState[SDL_SCANCODE_RIGHT])
        {
            movePlayer(player, walls, wallCount,2);
        }
        else if (keyboardState[SDL_SCANCODE_UP] && keyboardState[SDL_SCANCODE_LEFT])
        {
            movePlayer(player, walls, wallCount,3);
        }
        else if (keyboardState[SDL_SCANCODE_DOWN] && keyboardState[SDL_SCANCODE_LEFT])
        {
            movePlayer(player, walls, wallCount,4);
        }
        else if (keyboardState[SDL_SCANCODE_Q] || keyboardState[SDL_SCANCODE_UP] && keyboardState[SDL_SCANCODE_Q] || keyboardState[SDL_SCANCODE_DOWN] && keyboardState[SDL_SCANCODE_Q] || keyboardState[SDL_SCANCODE_LEFT] && keyboardState[SDL_SCANCODE_Q] || keyboardState[SDL_SCANCODE_RIGHT] && keyboardState[SDL_SCANCODE_Q])
        {
            movePlayer(player, walls, wallCount,5);
        }
        else if (keyboardState[SDL_SCANCODE_E] || keyboardState[SDL_SCANCODE_UP] && keyboardState[SDL_SCANCODE_E] || keyboardState[SDL_SCANCODE_DOWN] && keyboardState[SDL_SCANCODE_E] || keyboardState[SDL_SCANCODE_LEFT] && keyboardState[SDL_SCANCODE_E] || keyboardState[SDL_SCANCODE_RIGHT] && keyboardState[SDL_SCANCODE_E])
        {
            movePlayer(player, walls, wallCount,6);
        }
        else if (keyboardState[SDL_SCANCODE_M]) // map
        {
            if (open == false)
            {
                SDL_ShowWindow(window);
                open = true;
            }
            else
            {
                SDL_HideWindow(window);
                open = false;
            }
        }
        else
        {
            switch (event->key.keysym.sym)
            {
            case SDLK_UP:
                movePlayer(player, walls, wallCount,7);
                break;
            case SDLK_DOWN:
                movePlayer(player, walls, wallCount,8);
                break;
            case SDLK_LEFT:

                movePlayer(player,walls, wallCount,9);
                break;
            case SDLK_RIGHT:
                movePlayer(player,walls, wallCount,10);
                break;
            default:
                break;
            }
        }
    }
}
