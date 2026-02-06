#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "../include/gameField.h"

const int SCREEN_WIDTH = 2000;
const int SCREEN_HEIGHT = 1000;

int main(int argc, char *args[])
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG); // Initialize Image library

    SDL_Window *window = SDL_CreateWindow("chicken Inavders Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Create the Game Field and pass the renderer to it
    clsGameField gameField(renderer);

    bool isRunning = true;
    SDL_Event event;
    int mouseX, mouseY;

    while (isRunning)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
                isRunning = false;
        }

        // Get the current mouse position
        SDL_GetMouseState(&mouseX, &mouseY);

        // --- Update ---
        gameField.update((float)mouseX, (float)mouseY);

        // --- Render ---
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        gameField.render(renderer); // Tell the world to draw itself

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
