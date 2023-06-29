// #include <SDL2/SDL.h>

// typedef int bool;
// #define true 1
// #define false 0

// int main(int argc, char** argv)
// {
//     // variables
//     (void)argc;
//     (void)argv;
//     bool quit = false;
//     SDL_Event event;
//     int x = 288;
//     int y = 208;

//     // init SDL

//     SDL_Init(SDL_INIT_VIDEO);
//     SDL_Window* window = SDL_CreateWindow("SDL2 Keyboard/Mouse events",
//                                           SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
//     SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

//     SDL_Surface* image = SDL_LoadBMP("pics/plane.bmp");
//     SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,
//                                                         image);
//     SDL_FreeSurface(image);

//     SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

//     // handle events

//     while (!quit)
//     {
//         SDL_PollEvent(&event);

//         switch (event.type)
//         {
//         case SDL_QUIT:
//             quit = true;
//             break;
//         case SDL_KEYDOWN:
//             // Handle key down event
//             switch (event.key.keysym.sym)
//             {
//             case SDLK_UP:
//                 y -= 10;
//                 break;
//             case SDLK_DOWN:
//                 y += 10;
//                 break;
//             case SDLK_LEFT:
//                 x -= 10;
//                 break;
//             case SDLK_RIGHT:
//                 x += 10;
//                 break;
//             }
//             break;
//         }

//         SDL_Rect dstrect = { x, y, 64, 64 };

//         SDL_RenderClear(renderer);
//         SDL_RenderCopy(renderer, texture, NULL, &dstrect);
//         SDL_RenderPresent(renderer);
//     }

//     // cleanup SDL

//     SDL_DestroyTexture(texture);
//     SDL_DestroyRenderer(renderer);
//     SDL_DestroyWindow(window);
//     SDL_Quit();

//     return 0;
// }
