#ifndef CANON_H
#define CANON_H

#include "vector.h"
#include <SDL2/SDL.h>
#include <cmath>

class clsCanon
{
private:
    float width, height;
    double angle;
    clsVector position;
    SDL_Texture *texture;

public:
    clsCanon(float w, float h, SDL_Texture *tex);
    void update(float targetX, float targetY);
    void render(SDL_Renderer *renderer);
};

#endif
