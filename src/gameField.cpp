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
    clsShot *shots = shotFac->shots();
    clsChicken *chickens = chickenFac->chickens();

    SDL_Rect shotRect;
    SDL_Rect chickenRect;
    for (int shot = 0; shot < shotFac->getMaxShots(); ++shot)
    {
        if (!shots[shot].IsActive())
            continue;

        shotRect = shots[shot].getRect();
        for (int chicken = 0; chicken < chickenFac->getMaxChickens(); ++chicken)
        {
            if (!chickens[chicken].getIsAlive())
                continue;

            chickenRect = chickens[chicken].getRect();
            if (SDL_HasIntersection(&shotRect, &chickenRect))
            {
                chickenFac->increaseKillsNum();
                chickenFac->decreaseChickenCount();
                shots[shot].setActivity(false);
                chickens[chicken].setIsAlive(false);
                break;
            }
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
