#include "../include/chicken.h"

clsChicken::clsChicken(clsVector position, float w, float h, SDL_Texture *tex)
{
    this->position = position;
    width = w;
    height = h;
    texture = tex;
    isAlive = true;
}

void clsChicken::kill()
{
    isAlive = false;
}

SDL_Rect clsChicken::getRect()
{
    SDL_Rect rect;
    rect.x = (int)position.getX();
    rect.y = (int)position.getY();
    rect.w = (int)width;
    rect.h = (int)height;

    return rect;
}

void clsChicken::update()
{
}

void clsChicken::render(SDL_Renderer *renderer)
{
    SDL_Rect destRect;
    destRect.x = position.getX();
    destRect.y = position.getY();
    destRect.w = width;
    destRect.h = height;

    SDL_RenderCopy(renderer, texture, NULL, &destRect);
}
