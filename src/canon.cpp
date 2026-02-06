#include "../include/canon.h"

clsCanon::clsCanon(float w, float h, SDL_Texture *tex)
{
    width = w;
    height = h;
    texture = tex;

    // Bottom-center of your 2000x1000 world
    position.setX(1000);
    position.setY(1000);
    angle = 0;
}

void clsCanon::update(float targetX, float targetY)
{
    float dx = targetX - position.getX();
    float dy = targetY - position.getY();

    angle = (atan2(dy, dx) * 180.0 / M_PI) + 90.0;
}

void clsCanon::render(SDL_Renderer *renderer)
{
    SDL_Rect destRect = {
        (int)(position.getX() - width / 2),
        (int)(position.getY() - height),
        (int)width,
        (int)height};

    SDL_Point pivot;
    pivot.x = width / 2;
    pivot.y = height; // The very bottom of the texture

    SDL_RenderCopyEx(renderer, texture, NULL, &destRect, angle, &pivot, SDL_FLIP_NONE);
}
