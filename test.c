// #include <SDL2/SDL.h>
// typedef int bool;
// #define true 1
// #define false 0
// int main() {
//     SDL_Init(SDL_INIT_VIDEO);

//     // Create the first window and renderer
//     SDL_Window* window1 = SDL_CreateWindow("Window 1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
//     SDL_Renderer* renderer1 = SDL_CreateRenderer(window1, -1, SDL_RENDERER_ACCELERATED);

//     // Create the second window and renderer
//     SDL_Window* window2 = SDL_CreateWindow("Window 2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
//     SDL_Renderer* renderer2 = SDL_CreateRenderer(window2, -1, SDL_RENDERER_ACCELERATED);

//     // Render something on window1
//     SDL_SetRenderDrawColor(renderer1, 255, 0, 0, 255);
//     SDL_RenderClear(renderer1);
//     SDL_Rect rect1 = { 100, 100, 200, 150 };
//     SDL_RenderFillRect(renderer1, &rect1);
//     SDL_RenderPresent(renderer1);

//     // Render something on window2
//     SDL_SetRenderDrawColor(renderer2, 0, 0, 255, 255);
//     SDL_RenderClear(renderer2);
//     SDL_Rect rect2 = { 50, 50, 300, 200 };
//     SDL_RenderFillRect(renderer2, &rect2);
//     SDL_RenderPresent(renderer2);

//     SDL_Event event;
//     bool quit = false;


//     while (!quit) {
//         while (SDL_PollEvent(&event)) {
//             if (event.type == SDL_QUIT) {
//                 if (event.window.windowID == SDL_GetWindowID(window1) || event.window.windowID == SDL_GetWindowID(window2)) {
//                     quit = true;
//                 }
//             }
//             else if (event.type == SDL_WINDOWEVENT) {
//                 if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
//                     if (event.window.windowID == SDL_GetWindowID(window1) || event.window.windowID == SDL_GetWindowID(window2)) {
//                         quit = true;
//                     }
//                 }
//             }
//         }
//     }

//     // Clean up resources
//     SDL_DestroyRenderer(renderer1);
//     SDL_DestroyWindow(window1);
//     SDL_DestroyRenderer(renderer2);
//     SDL_DestroyWindow(window2);
//     SDL_Quit();

//     return 0;
// }
