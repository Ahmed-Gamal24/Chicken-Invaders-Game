#ifndef SHOT_H
#define SHOT_H

#include <vector>
#include "vector.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cmath>

class clsShot
{
private:
    float width, height;
    double angleInRad;
    double angleInDeg;
    clsVector startPosition;
    clsVector targetPosition;
    SDL_Texture *texture;
    float speed;
    clsVector velocity;

public:
    clsShot(clsVector sPos, clsVector tPos, float w, float h, SDL_Texture *tex);
    clsVector getPos();
    SDL_Rect getRect();
    void update();
    void render(SDL_Renderer *renderer);
};

#endif
