#include "include/maze.h"
#include "include/colors.h"

int main()
{
    SDL_Init(SDL_INIT_VIDEO);

    createWindows();
    // create player
    Player *player = createPlayer();
    int wallsCount = 0;
    SDL_Point walls[wallmaxCount][2];

    FILE *mapFile = fopen("map.txt", "r");
    
    if (mapFile == NULL)
    {
        SDL_Log("Failed to open map file: %s", SDL_GetError());
        exit(1);
    }
    char line[256];

    int i = 0;

    char *token;
    while (fgets(line, MAX_BUFFER_SIZE - 1, mapFile))
    {
        token = strtok(line, Separator);
        walls[wallsCount][0].x = atoi(token);
        token = strtok(NULL, Separator);
        walls[wallsCount][0].y = atoi(token);
        token = strtok(NULL, Separator);
        walls[wallsCount][1].x = atoi(token);
        token = strtok(NULL, Separator);
        walls[wallsCount][1].y = atoi(token);
        wallsCount++;
    }
    fclose(mapFile);
    // Main loop
    SDL_Event event;
    int isRunning = 1;

    while (isRunning)
    {
        // Handle events
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                if (event.window.windowID == SDL_GetWindowID(window) || event.window.windowID == SDL_GetWindowID(window2)) {
                    isRunning = 0;
                }
            }else if (event.type == SDL_WINDOWEVENT) 
            {
                 if (event.window.event == SDL_WINDOWEVENT_CLOSE) 
                 {
                     if (event.window.windowID == SDL_GetWindowID(window2)) 
                     {
                         isRunning = 0;
                     }
                }
            }
            eventHandler(&event, &isRunning, player, walls, wallsCount);
        }

        // Game logic and rendering
        SDL_Texture* textureFloor = loadTexture(renderer2,"pics/greystone.png");
        SDL_Texture* textureCeil = loadTexture(renderer2,"pics/wood.png");
        //draw floor and ceiling
        drawCeilFloor(renderer2,NULL,NULL);

        // render player
        drawPlayer(renderer, player);

        // draw walls
        drawWalls(renderer, walls, wallsCount);
        drawRays(renderer,renderer2, player, walls, wallsCount);
        drawPlayer(renderer, player);

        SDL_Delay(1000 / 60);
        // infiniteRay(renderer,player);
        // raycast(renderer,player,wall1);
        // SDL_RenderDrawLine(renderer, 50, 100, 100, 100);

        // SDL_bool collision = SDL_HasIntersection(&rect1, &rect2);
        // if (collision) {
        //     SDL_RenderFillRect(renderer, &rect1);
        // }else{
        // SDL_RenderFillRect(renderer, &rect2);
        // }
        SDL_SetRenderDrawColor(renderer, COLOR_BLACK.r, COLOR_BLACK.g, COLOR_BLACK.b, COLOR_BLACK.a);
        // Update the renderer
        sendFrame(renderer,renderer2);
    }

    // Cleanup and exit
    cleanUp();
    return 0;
}
