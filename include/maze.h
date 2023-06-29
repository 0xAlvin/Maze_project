#ifndef _MAZE_H_
#define _MAZE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define windowH 600
#define windowW 800

typedef struct {
    int x;
    int y;
} vector2D;
typedef struct {
    int centerX;
    int centerY;
    int radius;
} Circle;
typedef struct{
    vector2D p1;
    vector2D p2;
}Point;
typedef struct{
    Point startP;
    Point endP;
}Wall;
typedef struct{
    Point pos;
}Player;
// Function prototypes
vector2D* ray(int x, int y);
void wall(SDL_Renderer* renderer, int x1, int y1, int x2, int y2);
void raycast(SDL_Renderer* renderer, int* pos);
SDL_Rect drawRect(SDL_Renderer *renderer, const char *colorname, int x, int y, int w, int h);
SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* path);
void drawCircle(SDL_Renderer *renderer, const char *colorname, int x, int y, int r);
void drawPlayer(SDL_Renderer* renderer,Player* player);
int* playerPosition(int x, int y,Player player);
void sendFrame(SDL_Renderer *renderer);
void eventHandler(SDL_Event *event, int *isRunning, Player *player);
#endif //_MAZE_H_
