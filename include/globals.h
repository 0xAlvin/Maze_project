#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include "maze.h"

extern Point spawn;
extern Player *player;

#define mapX 24
#define mapY 24
#define mapS 24*24

extern int map[mapX][mapY];

#endif /* __GLOBALS_H__ */
