#ifndef CHICKEN_FACTORY_H
#define CHICKEN_FACTORY_H

#include <queue>
#include "chicken.h"
#include "vector.h"
#include <cstdlib>

using namespace std;

class clsChickenFactory
{
private:
    static int chickenCount;

    clsVector nextPos;
    SDL_Texture *chickenTex;
    SDL_Renderer *renderer;

    static int maxChickens;
    clsChicken allChickens[7];

    int killsNumber;

    int minX;
    int maxX;
    int minY;
    int maxY;

public:
    clsChickenFactory(SDL_Renderer *renderer);
    clsChickenFactory();
    clsChicken *chickens();
    static int getChickenCount();
    static void setChickenCount(int newCount);
    static void decreaseChickenCount();
    static int getMaxChickens();
    static void setMaxChickens(int max);
    int getKillsNum();
    void increaseKillsNum();
    void update();
    void produceChicken();
    void render();
    ~clsChickenFactory();
};

#endif
