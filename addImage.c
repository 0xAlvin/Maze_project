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
