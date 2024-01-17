#include"../include/maze.h"
/**
 * btnDown - button down
 * @keypress: keypress
 *
*/
void btnDown(SDL_Event *event,keys *keypress)
{
    const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
    if (event->key.state == SDL_PRESSED)
    {
        keyboardState[SDL_SCANCODE_UP] ? keypress->up = 1 : 0;
        keyboardState[SDL_SCANCODE_DOWN] ? keypress->down = 1 : 0;
        keyboardState[SDL_SCANCODE_RIGHT] ? keypress->right = 1 : 0;
        keyboardState[SDL_SCANCODE_LEFT] ? keypress->left = 1 : 0;
        keyboardState[SDL_SCANCODE_A] ? keypress->a = 1 : 0;
        keyboardState[SDL_SCANCODE_D] ? keypress->d = 1 : 0;
    }
}