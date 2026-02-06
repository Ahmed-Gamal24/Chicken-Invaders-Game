#ifndef SHOT_FACTORY_H
#define SHOT_FACTORY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <list>
using namespace std;

#include "shot.h"

class clsShotFactory
{

private:
    SDL_Renderer *renderer;
    SDL_Texture *shotTex;
    list<clsShot *> allShots;

    Uint32 lastShotTime;
    Uint32 shotDelay;

public:
    clsShotFactory(SDL_Renderer *renderer);
    list<clsShot *> &shots();
    void update();
    void produceShot(float mouseX, float mouseY);
    void render();
    ~clsShotFactory();
};

#endif
