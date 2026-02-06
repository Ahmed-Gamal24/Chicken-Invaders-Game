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

    static int maxShots;
    clsShot allShots[200];

    Uint32 lastShotTime;
    Uint32 shotDelay;

public:
    clsShotFactory(SDL_Renderer *renderer);
    clsShot *shots();
    void update();
    void produceShot(float mouseX, float mouseY);
    void render();

    // Static getters and setters for maxShots
    static int getMaxShots();
    static void setMaxShots(int max);

    ~clsShotFactory();
};

#endif
