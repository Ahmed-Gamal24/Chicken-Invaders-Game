#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "canon.h"
#include "chickenFactory.h"
#include "shotFactory.h"

class clsGameField
{
private:
    clsCanon *canon;
    clsChickenFactory *chickenFac;
    clsShotFactory *shotFac;

public:
    clsGameField(SDL_Renderer *renderer);
    void update(float mouseX, float mouseY);
    void render(SDL_Renderer *renderer);
    ~clsGameField();
};

#endif
