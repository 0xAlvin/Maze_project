#include "include/maze.h"
#include "include/colors.h"

/**
 * main - The entry point of the program.
 * @return: Returns 0 if the program exited successfully, otherwise 1.
*/

int attilleryInvoke = 0; // how many times attillery is called
extern int rainIng;

int main()
{
    SDL_Init(SDL_INIT_VIDEO);

    createWindows();
    // create player
    Player *player = createPlayer();
    player->angle = 180; // face south
    int wallsCount = 0;
    SDL_Point walls[wallmaxCount][2];

    FILE *mapFile = fopen("map.txt", "r");

    if (mapFile == NULL)
    {
        SDL_Log("Failed to open map file: %s", SDL_GetError());
        exit(1);
    }
    char line[256];


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
                if (event.window.windowID == SDL_GetWindowID(window) || event.window.windowID == SDL_GetWindowID(window2))
                {
                    isRunning = 0;
                }
            }
            else if (event.type == SDL_WINDOWEVENT)
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
        // SDL_Texture *textureFloor = loadTexture(renderer2, "pics/greystone.png");
        // SDL_Texture *textureCeil = loadTexture(renderer2, "pics/wood.png");

        // draw floor and ceiling
        drawCeilFloor(renderer2, NULL, NULL);

        // render player
        drawPlayer(renderer, player);

        // draw walls
        drawWalls(renderer, walls, wallsCount);
        drawRays(renderer, renderer2, player, walls, wallsCount);
        drawPlayer(renderer, player);
        // attillery load
        char *attilleryPath;
        attilleryPath = attillery(attilleryInvoke);
        SDL_Rect attilleryRect = drawRect(renderer2, "NULL", (windowW/4),(windowH - (windowH/(4))-50), (windowW/2), (windowH/4)+63); // creates a rect for attillery clear
        SDL_Texture *textureAttillery = loadTexture(renderer2, attilleryPath);
        SDL_RenderCopy(renderer2, textureAttillery, NULL, &attilleryRect);

        //crosshair
        if (attilleryInvoke != 0)
        {
            crossHair(renderer2, window2);
        }
        //rain
        if (rainIng == true)
        {
            rain(renderer2,1000,10);
        }
        SDL_Delay(1000 / 60);
        SDL_SetRenderDrawColor(renderer, COLOR_CLEAR.r, COLOR_CLEAR.g, COLOR_CLEAR.b, COLOR_CLEAR.a);
        // Update the renderer
        sendFrame(renderer, renderer2);
        // attillery destroy
        SDL_DestroyTexture(textureAttillery);
    }

    // Cleanup and exit
    cleanUp();
    return 0;
}