#include "../include/gameField.h"

clsGameField::clsGameField(SDL_Renderer *renderer)
{
    SDL_Texture *cannonTex = IMG_LoadTexture(renderer, "img/canon.jpg");

    canon = new clsCanon(120, 160, cannonTex);
    chickenFac = new clsChickenFactory(renderer);
    shotFac = new clsShotFactory(renderer);
}

void clsGameField::update(float mouseX, float mouseY)
{
    canon->update(mouseX, mouseY);
    chickenFac->update();
    shotFac->update();

    // handle the collision
    auto &shots = shotFac->shots();
    auto &chickens = chickenFac->chickens();

    SDL_Rect shotRect;
    SDL_Rect chickenRect;
    for (auto itShot = shots.begin(); itShot != shots.end(); )
    {
        bool shotHit = false;
        shotRect = (*itShot)->getRect();
        for (auto itChicken = chickens.begin(); itChicken != chickens.end();)
        {
            chickenRect = (*itChicken)->getRect();
            if (SDL_HasIntersection(&shotRect, &chickenRect))
            {
                shotHit = true;
                chickenFac->increaseKillsNum();
                delete *itChicken;
                itChicken = chickens.erase(itChicken);          
                chickenFac->setChickenCount(chickenFac->getChickenCount() - 1);
                break;
            }else{
                itChicken ++;
            }
        }

        if(shotHit){
            delete *itShot;
            itShot = shots.erase(itShot);
        }else {
            itShot++;
        }
    }
}

void clsGameField::render(SDL_Renderer *renderer)
{
    canon->render(renderer);
    chickenFac->render();
    shotFac->render();
}

clsGameField::~clsGameField()
{
    delete canon;
    delete chickenFac;
    delete shotFac;
}
