#include "../include/maze.h"
/**
 * move - moves the player
 * @player: player
 * @keypress: keypress
 */
void move(Player *player, SDL_Event keypress)
{
    const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
    if (keypress.type == SDL_QUIT)
    {
        // if it is quit the program
        return;
    }
    if (keyboardState[SDL_SCANCODE_UP])
    {
        player->pos.x += player->dir.x * PLAYER_SPEED;
        player->pos.y += player->dir.y * PLAYER_SPEED;
    }
    if (keyboardState[SDL_SCANCODE_DOWN])
    {
        player->pos.x -= player->dir.x * PLAYER_SPEED;
        player->pos.y -= player->dir.y * PLAYER_SPEED;
    }
    if (keyboardState[SDL_SCANCODE_RIGHT])
    {
        player->Angle += PLAYER_TURN_SPEED;
        if(player->Angle >= 2 * PI)
        {
            player->Angle -= 2 * PI; // Keep the angle within the range [0, 2*pi)
        }
        player->dir.x = cos(player->Angle) * 5;
        player->dir.y = sin(player->Angle) * 5;
    }
    if (keyboardState[SDL_SCANCODE_LEFT])
    {
        player->Angle -= PLAYER_TURN_SPEED;
        if(player->Angle < 0)
        {
            player->Angle += 2 * PI; // Keep the angle within the range [0, 2*pi)
        }
        player->dir.x = cos(player->Angle) * 5;
        player->dir.y = sin(player->Angle) * 5;
    }
    if (keyboardState[SDL_SCANCODE_A])
    {
        // based on the player angle, move the player left
        player->pos.x -= player->dir.y * PLAYER_SPEED;
        player->pos.y += player->dir.x * PLAYER_SPEED;
    }
    if (keyboardState[SDL_SCANCODE_D])
    {
        // based on the player angle, move the player right
        player->pos.x += player->dir.y * PLAYER_SPEED;
        player->pos.y -= player->dir.x * PLAYER_SPEED;
    }
    if (keyboardState[SDL_SCANCODE_LEFT] && keyboardState[SDL_SCANCODE_UP])
    {
        player->Angle -= PLAYER_TURN_SPEED;
        if (player->Angle < 0)
        {
            player->Angle += 2 * PI; // Keep the angle within the range [0, 2*pi)
        }
        player->dir.x = cos(player->Angle) * 5;
        player->dir.y = sin(player->Angle) * 5;
        player->pos.x += player->dir.x * PLAYER_SPEED;
        player->pos.y += player->dir.y * PLAYER_SPEED;
    }
    if (keyboardState[SDL_SCANCODE_RIGHT] && keyboardState[SDL_SCANCODE_UP])
    {
        player->Angle += PLAYER_TURN_SPEED;
        if (player->Angle >= 2 * PI)
        {
            player->Angle -= 2 * PI; // Keep the angle within the range [0, 2*pi)
        }
        player->dir.x = cos(player->Angle) * 5;
        player->dir.y = sin(player->Angle) * 5;
        player->pos.x += player->dir.x * PLAYER_SPEED;
        player->pos.y += player->dir.y * PLAYER_SPEED;
    }
    if (keyboardState[SDL_SCANCODE_DOWN])
    {
        player->pos.x -= player->dir.x * PLAYER_SPEED;
        player->pos.y -= player->dir.y * PLAYER_SPEED;
    }
}
