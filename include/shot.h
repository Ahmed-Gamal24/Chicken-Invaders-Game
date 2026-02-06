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
    bool isActive;

public:
    clsShot(clsVector sPos, clsVector tPos, float w, float h, SDL_Texture *tex);
    clsShot();
    SDL_Rect getRect();
    bool IsActive();
    void setActivity(bool active);

    // Getters
    float getWidth();
    float getHeight();
    clsVector getStartPosition();
    clsVector getTargetPosition();
    SDL_Texture *getTexture();

    // Setters
    void setWidth(float w);
    void setHeight(float h);
    void setStartPosition(clsVector pos);
    void setTargetPosition(clsVector pos);
    void setTexture(SDL_Texture *tex);

    void update();
    void render(SDL_Renderer *renderer);
};

#endif
