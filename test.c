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
// #include <SDL2/SDL.h>
// #include <SDL2/SDL_image.h>
// #include <math.h>
// int attilleryInvoke;

// #define PI 3.14159265358979323846

// int main(int argc, char* argv[]) {
//     // Initialize SDL
//     SDL_Init(SDL_INIT_VIDEO);

//     // Create a window
//     SDL_Window* window = SDL_CreateWindow("SDL Rotation Movement", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

//     // Create a renderer
//     SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

//     // Load image
//     SDL_Surface* surface = IMG_Load("pics/thirdg.png");
//     SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
//     SDL_FreeSurface(surface);

//     // Get image dimensions
//     int imgWidth, imgHeight;
//     SDL_QueryTexture(texture, NULL, NULL, &imgWidth, &imgHeight);

//     // Set the rotation point of origin
//     int rotationOriginX = imgWidth / 2;    // Center X coordinate of the image
//     int rotationOriginY = imgHeight / 2;   // Center Y coordinate of the image

//     // Set the initial rotation angle and distance from the origin
//     double rotationAngle = 0.0;
//     double rotationDistance = 100.0;

//     // Clear the renderer
//     SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
//     SDL_RenderClear(renderer);

//     // Event loop flag
//     int quit = 0;

//     // Event object
//     SDL_Event event;

//     // Event loop
//     while (!quit) {
//         // Poll for events
//         while (SDL_PollEvent(&event)) {
//             // Check the type of event
//             if (event.type == SDL_QUIT) {
//                 // User closed the window
//                 quit = 1;
//             }
//             else if (event.type == SDL_KEYDOWN) {
//                 // Check for rotation movement keys
//                 switch (event.key.keysym.sym) {
//                     case SDLK_LEFT:
//                         rotationAngle -= 5.0;    // Decrease the rotation angle
//                         break;
//                     case SDLK_RIGHT:
//                         rotationAngle += 5.0;    // Increase the rotation angle
//                         break;
//                     case SDLK_UP:
//                         rotationDistance += 5.0;  // Increase the distance from the origin
//                         break;
//                     case SDLK_DOWN:
//                         rotationDistance -= 5.0;  // Decrease the distance from the origin
//                         if (rotationDistance < 0.0) {
//                             rotationDistance = 0.0;  // Clamp the distance to a minimum of 0
//                         }
//                         break;
//                     default:
//                         break;
//                 }
//             }
//         }

//         // Calculate the new position based on rotation angle and distance
//         double angleRadians = rotationAngle * PI / 180.0;
//         int posX = rotationOriginX + (int)(rotationDistance * cos(angleRadians));
//         int posY = rotationOriginY + (int)(rotationDistance * sin(angleRadians));

//         // Clear the renderer
//         SDL_RenderClear(renderer);

//         // Set the rendering destination rectangle
//         SDL_Rect destRect;
//         destRect.x = posX - rotationOriginX;     // X coordinate of the destination rectangle
//         destRect.y = posY - rotationOriginY;     // Y coordinate of the destination rectangle
//         destRect.w = imgWidth;                   // Width of the destination rectangle
//         destRect.h = imgHeight;                  // Height of the destination rectangle

//         // Render the image
//         SDL_RenderCopy(renderer, texture, NULL, &destRect);

//         // Update the screen
//         SDL_RenderPresent(renderer);
//     }

//     // Clean up resources
//     SDL_DestroyTexture(texture);
//     SDL_DestroyRenderer(renderer);
//     SDL_DestroyWindow(window);
//     SDL_Quit();

//     return 0;
// }
