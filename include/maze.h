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


#define PLAYER_SIZE 8
#define PLAYER_SPEED 5
#define PLAYER_TURN_SPEED 5 * (PI / 180)

#define PI 3.14159265358979323846
#define P2 PI / 2
#define P3 3 * PI / 2
#define DEG2RAD(deg) (deg * PI / 180)
#define RAD2DEG(rad) (rad * 180 / PI)
#define FOV 60


#define DEG 0.0174533


#define true 1
#define false 0

#endif /* __MAZE_H__ */
