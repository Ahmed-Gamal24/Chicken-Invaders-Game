#include "../include/shotFactory.h"

clsShotFactory::clsShotFactory(SDL_Renderer *renderer)
{
    this->renderer = renderer;
    lastShotTime = 0;
    shotDelay = 70;
    shotTex = IMG_LoadTexture(renderer, "img/shot.png");
}

list<clsShot *> &clsShotFactory::shots()
{
    return allShots;
}

void clsShotFactory::update()
{
    int x, y;
    Uint32 buttons = SDL_GetMouseState(&x, &y);

    if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
    {
        // SDL_GetTicks() returns current time in milliseconds
        if (SDL_GetTicks() > lastShotTime + shotDelay)
        {
            produceShot((float)x, (float)y);
            lastShotTime = SDL_GetTicks(); // Reset the timer
        }
    }

    for (auto itShot = allShots.begin(); itShot != allShots.end();)
    {
        (*itShot)->update();

        if ((*itShot)->getPos().getY() < 0)
        {
            delete *itShot;
            itShot = allShots.erase(itShot);
        }
        else
        {
            itShot++;
        }
    }
}

void clsShotFactory::produceShot(float mouseX, float mouseY)
{
    clsVector targetPos = {mouseX, mouseY};
    clsVector startPos = {1000, 1000};
    clsShot *newShot = new clsShot(startPos, targetPos, 30, 30, shotTex);
    allShots.push_back(newShot);
}

void clsShotFactory::render()
{
    for (auto itShot = allShots.begin(); itShot != allShots.end(); ++itShot)
    {
        (*itShot)->render(renderer);
    }
}

clsShotFactory::~clsShotFactory()
{
}
