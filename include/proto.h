#ifndef __PROTO_H__
#define __PROTO_H__
#include "maze.h"
int init_(void);
void drawPlayer(Player *player, SDL_Renderer *renderer);
SDLResources *createWindow(void);
void clear(SDL_Renderer *renderer);
void cleanUp(SDL_Renderer *renderer, SDL_Window *window);
void move(Player *player, SDL_Event keypress);
void drawMap(SDL_Renderer *renderer);
void drawRays(Player *player, SDL_Renderer *renderer);
void drawLine(SDL_Renderer *renderer, int x1, int y1, int x2, int y2);

#endif /* __PROTO_H__ */
