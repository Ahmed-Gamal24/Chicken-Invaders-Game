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
    clsChicken();
    clsChicken(clsVector position, float w, float h, SDL_Texture *tex);
    void kill();
    SDL_Rect getRect();

    // Getters
    float getWidth();
    float getHeight();
    clsVector getPosition();
    SDL_Texture *getTexture();
    bool getIsAlive();

    // Setters
    void setWidth(float w);
    void setHeight(float h);
    void setPosition(clsVector pos);
    void setTexture(SDL_Texture *tex);
    void setIsAlive(bool alive);

    void update();
    void render(SDL_Renderer *renderer);
};

#endif
