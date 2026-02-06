#ifndef CHICKEN_FACTORY_H
#define CHICKEN_FACTORY_H

#include <queue>
#include "chicken.h"
#include "vector.h"
#include <cstdlib>
#include <list>
using namespace std;

class clsChickenFactory
{
private:
    static int chickenCount;
    bool isThereNewCheckin;
    clsChicken *lastChicken;
    clsVector nextPos;
    SDL_Texture *chickenTex;
    SDL_Renderer *renderer;
    list<clsChicken *> allChickens;
    int killsNumber;

    int minX;
    int maxX;
    int minY;
    int maxY;

public:
    clsChickenFactory(SDL_Renderer *renderer);
    list<clsChicken *> &chickens();
    static int getChickenCount();
    static void setChickenCount(int newCount);
    int getKillsNum();
    void increaseKillsNum();
    void update();
    void produceChicken();
    void render();
    ~clsChickenFactory();
};

#endif
