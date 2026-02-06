#include "../include/chicken.h"

clsChicken::clsChicken(clsVector position, float w, float h, SDL_Texture *tex)
{
    this->position = position;
    width = w;
    height = h;
    texture = tex;
    isAlive = true;
}

clsChicken::clsChicken(){
    isAlive = false;
    w = 
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

float clsChicken::getWidth()
{
    return width;
}

float clsChicken::getHeight()
{
    return height;
}

clsVector clsChicken::getPosition()
{
    return position;
}

SDL_Texture *clsChicken::getTexture()
{
    return texture;
}

bool clsChicken::getIsAlive()
{
    return isAlive;
}

void clsChicken::setWidth(float w)
{
    width = w;
}

void clsChicken::setHeight(float h)
{
    height = h;
}

void clsChicken::setPosition(clsVector pos)
{
    position = pos;
}

void clsChicken::setTexture(SDL_Texture *tex)
{
    texture = tex;
}

void clsChicken::setIsAlive(bool alive)
{
    isAlive = alive;
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
