#ifndef __PROTO_H__
#define __PROTO_H__
#include "maze.h"
int init_(void);
void drawPlayer(Player *player, SDL_Renderer *renderer);
SDLResources *createWindow(void);
void clear(SDL_Renderer *renderer);
void cleanUp(SDL_Renderer *renderer, SDL_Window *window);
void move(Player *player, SDL_Event keypress);

#endif /* __PROTO_H__ */
