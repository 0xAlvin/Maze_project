// #include "include/maze.h"

// /**
//  * mapParser - Parses the map file and creates the map.
//  * @renderer: The renderer.
//  * @player: The player.
//  * 
// */
// void mapParser(SDL_Renderer *renderer){
//     FILE *mapFile = fopen("map.txt", "r");
//     SDL_Point walls[wallmaxCount][2];
//     if (mapFile == NULL)
//     {
//         SDL_Log("Failed to open map file: %s", SDL_GetError());
//         exit(1);
//     }
//     char line[256];
//     #define buffer = malloc(MAX_BUFFER_SIZE * sizeof(char));
//     int i = 0;
//     int wallsCount = 0;
    
//     char *token;
//     while (fgets(line, MAX_BUFFER_SIZE - 1, mapFile))
//     {
//         token = strtok(line, Separator);
//         walls[wallsCount][0].x = atoi(token);
//         token = strtok(NULL, Separator);
//         walls[wallsCount][0].y = atoi(token);
//         token = strtok(NULL, Separator);
//         walls[wallsCount][1].x = atoi(token);
//         token = strtok(NULL, Separator);
//         walls[wallsCount][1].y = atoi(token);
//         wallsCount++;
//     }
//     fclose(mapFile);
// }
