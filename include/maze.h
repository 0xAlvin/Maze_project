#ifndef __MAZE_H__
#define __MAZE_H__

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<math.h>
#include<string.h>

/*defined headers*/
#include"structs.h"
#include "windows.h"
#include "colors.h"
#include "proto.h"
#include "globals.h"


#define PLAYER_SIZE 20
#define PLAYER_SPEED 10

#define PI 3.14159265358979323846
#define P2 PI / 2
#define P3 3 * PI / 2
#define DEG2RAD(deg) (deg * PI / 180)
#define RAD2DEG(rad) (rad * 180 / PI)
#define FOV 60
#define RAY_NUM 300
#define NUM_RAYS 300
#define TILE_SIZE 64
#define MAP_NUM_ROWS 13
#define MAP_NUM_COLS 20
#define MINIMAP_SCALE_FACTOR 0.3


#define true 1
#define false 0

#endif /* __MAZE_H__ */
