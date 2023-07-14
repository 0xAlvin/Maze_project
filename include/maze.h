#ifndef _MAZE_H_
#define _MAZE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "windows.h"

#define windowH 600
#define windowW 800
#define playerStep 10

#define true 1
#define false 0

//define vector2D
typedef struct {
    int x;
    int y;
} vector2D;

//define Circle
typedef struct {
    int centerX;
    int centerY;
    int radius;
} Circle;

//define Point
typedef struct{
    vector2D p1;
    vector2D p2;
}Point;

//define Wall
typedef struct{
    Point coordinate;
}Wall;

//define Player
typedef struct{
    Point pos;
    int angle;
}Player;

//define Rain
typedef struct
{
    int x;
    int y;
    int length;
    int speed;
} Rain;

#define PI 3.14159265
#define DEG2RAD(deg) (deg * PI / 180)
#define fov 60
#define viewRange 1000
#define TEXTURE_SCALE 2
#define TEXTURE_HEIGHT
#define wallWidth 10
#define wallmaxCount 200
#define MAX_BUFFER_SIZE 24
#define Separator ","
#define buffer = malloc(MAX_BUFFER_SIZE * sizeof(char));
#define TURN_ANGLE 5


// Function prototypes
void drawCeilFloor(SDL_Renderer *renderer,SDL_Texture* textureFloor,SDL_Texture* textureCeil);
void drawWalls(SDL_Renderer *renderer, SDL_Point walls[wallmaxCount][2], int wallCount);
void drawRays(SDL_Renderer *renderer,SDL_Renderer *renderer2, Player *player, SDL_Point walls[200][2], int wallCount);
SDL_Rect drawRect(SDL_Renderer *renderer, const char *colorname, int x, int y, int w, int h);
SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* path);
void drawCircle(SDL_Renderer *renderer, const char *colorname, int x, int y, int r);
void drawPlayer(SDL_Renderer* renderer,Player* player);
int* playerPosition(Player player);
Player* createPlayer();
void sendFrame(SDL_Renderer *renderer,SDL_Renderer *renderer2);
void eventHandler(SDL_Event *event, int *isRunning, Player *player,SDL_Point walls[wallmaxCount][2], int wallCount);
SDL_Point CreateTarget(int x, int y, int dir, int dist);
int PointOnLine(int x1, int y1, int x2, int y2, int tx, int ty);
int PointDistance(int x1, int y1, int x2, int y2);
int CheckCollision(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
SDL_Surface* createPlusTexture(int width, int height);
Player *movePlayer(Player *player,SDL_Point walls[wallmaxCount][2], int wallCount, int cmd);
char* attillery(int selectedAttillery);
void crossHair(SDL_Renderer *renderer, SDL_Window *window);
int rain(SDL_Renderer *renderer, int drops, int delay);
char *cardinalDirection(Player *player);
void forward(Player *player);
void backward(Player *player);
void left(Player *player);
void right(Player *player);

extern int attilleryInvoke;
extern int rainIng;

#endif //_MAZE_H_
