#include "../include/chickenFactory.h"

int clsChickenFactory::chickenCount = 0;

clsChickenFactory::clsChickenFactory(SDL_Renderer *renderer)
{
    isThereNewCheckin = false;
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

list<clsChicken *> &clsChickenFactory::chickens()
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
    clsChicken *chicken = new clsChicken(nextPos, 100, 100, chickenTex);
    allChickens.push_back(chicken);
}

void clsChickenFactory::render()
{
    for (clsChicken *chicken : allChickens)
    {
        chicken->render(renderer);
    }
}

clsChickenFactory::~clsChickenFactory()
{
    for (auto chicken : allChickens)
    {
        delete chicken;
    }
    allChickens.clear();
}
