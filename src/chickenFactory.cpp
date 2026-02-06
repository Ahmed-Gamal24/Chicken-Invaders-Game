#include "../include/chickenFactory.h"

int clsChickenFactory::chickenCount = 0;
int clsChickenFactory::maxChickens = 7;

clsChickenFactory::clsChickenFactory()
{
}

clsChickenFactory::clsChickenFactory(SDL_Renderer *renderer)
{
    nextPos.setX(200);
    nextPos.setY(150);
    this->renderer = renderer;
    killsNumber = 0;
    minX = 100;
    maxX = 1900;
    minY = 100;
    maxY = 600;
    chickenTex = IMG_LoadTexture(renderer, "img/chicken.png");
}

clsChicken *clsChickenFactory::chickens()
{
    return allChickens;
}

int clsChickenFactory::getChickenCount()
{
    return chickenCount;
}

void clsChickenFactory::setChickenCount(int newCount)
{
    chickenCount = newCount;
}

void clsChickenFactory::decreaseChickenCount()
{
    chickenCount--;
}

int clsChickenFactory::getKillsNum()
{
    return killsNumber;
}

void clsChickenFactory::increaseKillsNum()
{
    killsNumber++;
}

void clsChickenFactory::update()
{
    if (chickenCount < 7)
    {
        produceChicken();
    }
}

void clsChickenFactory::produceChicken()
{
    chickenCount++;
    int randomX = minX + (rand() % (maxX - minX + 1));
    int randomY = minY + (rand() % (maxY - minY + 1));
    nextPos.setX(randomX);
    nextPos.setY(randomY);

    for (int i = 0; i < maxChickens; ++i)
    {
        if (!allChickens[i].getIsAlive())
        {
            allChickens[i].setIsAlive(true);
            allChickens[i].setPosition(nextPos);
            allChickens[i].setTexture(chickenTex);
            break;  // Only activate one chicken per update
        }
    }
}

void clsChickenFactory::render()
{
    for (int i = 0; i < maxChickens; ++i)
    {
        if (allChickens[i].getIsAlive())
        {
            allChickens[i].render(renderer);
        }
    }
}


int clsChickenFactory::getMaxChickens()
{
    return maxChickens;
}

void clsChickenFactory::setMaxChickens(int max)
{
    maxChickens = max;
}


clsChickenFactory::~clsChickenFactory()
{
}