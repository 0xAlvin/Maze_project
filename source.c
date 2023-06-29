#include "include/maze.h"
#include "include/colors.h"

int main()
{
    SDL_Init(SDL_INIT_VIDEO);

    // Create a window and renderer
    SDL_Window *window = SDL_CreateWindow("The Maze", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowW, windowH, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    SDL_RenderClear(renderer);

    SDL_Event event;
    int isRunning = 1;
    // player spawn
    Player player = createPlayer();
    int pos[2] = {70, 70};
    while (isRunning)
    {   
        // handle events
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                isRunning = 0;
            }
            // handle input
            
            }
        }
        // Draw a rectangle with the red color
        wall(renderer, 650, 50, 650, 250);
        drawPlayer(renderer, &player);
        raycast(renderer, &player);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        // Update the renderer
        sendFrame(renderer);
    }
    // Cleanup and exit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
