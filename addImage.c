#include "include/maze.h"

/**
 * loadTexture - Loads an image from the specified path and creates a texture from it.
 * @renderer: The SDL renderer to create the texture on.
 * @path: The path of the image file to load.
 *
 * This function loads an image from the specified path, creates a texture from the loaded image surface,
 * and returns the created texture. It returns NULL on failure.
 */
SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* path)
{
    SDL_Surface* imageSurface = IMG_Load(path);
    if (imageSurface == NULL) {
        SDL_Log("Failed to load image: %s", IMG_GetError());
        return NULL;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
    if (texture == NULL) {
        SDL_Log("Failed to create texture: %s", SDL_GetError());
        return NULL;
    }

    return texture;
}
SDL_Surface* createPlusTexture(int width, int height)//creates a plus brown texture
{
    // Create an SDL_Surface with the desired dimensions
    SDL_Surface* plusSurface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);

    // Set the color to draw the plus pattern
    Uint32 plusColor = SDL_MapRGB(plusSurface->format, 165, 129, 79);

    // Calculate the center coordinates of the surface
    int centerX = width / 2;
    int centerY = height / 2;

    // Draw the plus pattern on the surface
    for (int x = centerX - 2; x <= centerX + 1; x++)
    {
        // Draw horizontal lines
        for (int y = 0; y < height; y++)
        {
            Uint32* pixel = (Uint32*)((Uint8*)plusSurface->pixels + y * plusSurface->pitch + x * sizeof(Uint32));
            *pixel = plusColor;
        }
    }

    for (int y = centerY - 2; y <= centerY + 1; y++)
    {
        // Draw vertical lines
        for (int x = 0; x < width; x++)
        {
            Uint32* pixel = (Uint32*)((Uint8*)plusSurface->pixels + y * plusSurface->pitch + x * sizeof(Uint32));
            *pixel = plusColor;
        }
    }

    return plusSurface;
}
