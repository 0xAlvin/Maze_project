#ifndef _WINDOWS_H_
#define _WINDOWS_H_

#include <SDL2/SDL.h>
//windows
extern SDL_Window *window; 
extern SDL_Renderer *renderer;
extern SDL_Window* window2;
extern SDL_Renderer* renderer2;

//window prototypes
void createWindows(void);
void cleanUp(void);

#endif