#ifndef __STRUCTS_H__
#define __STRUCTS_H__

/**
 * struct Point - point with x,y coordinates
 * @x: x coordinate
 * @y: y coordinate
*/
typedef struct Point
{
float x;
float y;
} Point;

/**
 * struct Player - player with x,y coordinates
 * @pos: position of player
 * @size: size of player
 * @dir: direction of player
 * @Angle: angle of player
*/
typedef struct Player
{
Point pos;
Point size;
Point dir;
float Angle;
} Player;

/**
 * struct SDLResources - SDL resources
 * @renderer: renderer
 * @window: window
*/
typedef struct SDLResources
{
SDL_Renderer *renderer;
SDL_Window *window;
} SDLResources;


#endif /* __STRUCTS_H__ */
