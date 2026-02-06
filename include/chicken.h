#ifndef CHICKEN_H
#define CHICKEN_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "vector.h"

class clsChicken
{
private:
    float width;
    float height;
    clsVector position;
    SDL_Texture *texture;
    bool isAlive;

public:
    clsChicken(clsVector position, float w, float h, SDL_Texture *tex);
    void kill();
    SDL_Rect getRect();
    void update();
    void render(SDL_Renderer *renderer);
};

#endif
