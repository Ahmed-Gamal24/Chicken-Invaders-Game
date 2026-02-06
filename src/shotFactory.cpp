#include "../include/shotFactory.h"

int clsShotFactory::maxShots = 200;

clsShotFactory::clsShotFactory(SDL_Renderer *renderer)
{
    this->renderer = renderer;
    lastShotTime = 0;
    shotDelay = 70;
    shotTex = IMG_LoadTexture(renderer, "img/shot.png");
}

clsShot *clsShotFactory::shots()
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

    for (int i = 0; i < maxShots; ++i)
    {
        if (!allShots[i].IsActive())
            continue;
            
        allShots[i].update();

        if (allShots[i].getStartPosition().getY() < 0)
        {
            allShots[i].setActivity(false);
        }
    }
}

void clsShotFactory::produceShot(float mouseX, float mouseY)
{
    clsVector targetPos = {mouseX, mouseY};
    clsVector startPos = {1000, 1000};

    // look for a valid position in allShots pool
    for (int i = 0; i < maxShots; ++i)
    {
        if (!allShots[i].IsActive())
        {
            allShots[i].setActivity(true);
            allShots[i].setStartPosition(startPos);
            allShots[i].setTargetPosition(targetPos);
            allShots[i].setWidth(30);
            allShots[i].setHeight(30);
            allShots[i].setTexture(shotTex);
            break;  // Only activate one shot per click
        }
    }
}

void clsShotFactory::render()
{
    for (int i = 0; i < maxShots; ++i)
    {
        if (allShots[i].IsActive())
        {
            allShots[i].render(renderer);
        }
    }
}

clsShotFactory::~clsShotFactory()
{
}

int clsShotFactory::getMaxShots()
{
    return maxShots;
}

void clsShotFactory::setMaxShots(int max)
{
    maxShots = max;
}
