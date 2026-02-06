#include "../include/shot.h"

clsShot::clsShot(clsVector sPos, clsVector tPos, float w, float h, SDL_Texture *tex)
{
    startPosition = sPos;
    targetPosition = tPos;
    width = w;
    height = h;
    texture = tex;
    speed = 10.0f;

    isActive = true;

    clsVector delta;
    delta.setX(targetPosition.getX() - startPosition.getX());
    delta.setY(targetPosition.getY() - startPosition.getY());

    angleInRad = atan2(delta.getY(), delta.getX());

    velocity.setX(cos(angleInRad) * speed);
    velocity.setY(sin(angleInRad) * speed);

    angleInDeg = (angleInRad * 180.0 / M_PI) + 90.0;
}

clsShot::clsShot()
{
    isActive = false;
    speed = 10.0f;
    width = 30;
    height = 30;
    texture = nullptr;
    angleInRad = 0;
    angleInDeg = 0;
    startPosition.setX(0);
    startPosition.setY(0);
    targetPosition.setX(0);
    targetPosition.setY(0);
    velocity.setX(0);
    velocity.setY(0);
}


SDL_Rect clsShot::getRect()
{
    SDL_Rect rect;
    rect.x = (int)startPosition.getX();
    rect.y = (int)startPosition.getY();
    rect.w = (int)width;
    rect.h = (int)height;

    return rect;
}

bool clsShot::IsActive()
{
    return isActive;
}

void clsShot::setActivity(bool active)
{
    isActive = active;
}

float clsShot::getWidth()
{
    return width;
}

float clsShot::getHeight()
{
    return height;
}

clsVector clsShot::getStartPosition()
{
    return startPosition;
}

clsVector clsShot::getTargetPosition()
{
    return targetPosition;
}

SDL_Texture *clsShot::getTexture()
{
    return texture;
}

void clsShot::setWidth(float w)
{
    width = w;
}

void clsShot::setHeight(float h)
{
    height = h;
}

void clsShot::setStartPosition(clsVector pos)
{
    startPosition = pos;
}

void clsShot::setTargetPosition(clsVector pos)
{
    targetPosition = pos;
    calculateTrajectory();
}

void clsShot::calculateTrajectory()
{
    clsVector delta;
    delta.setX(targetPosition.getX() - startPosition.getX());
    delta.setY(targetPosition.getY() - startPosition.getY());

    angleInRad = atan2(delta.getY(), delta.getX());

    velocity.setX(cos(angleInRad) * speed);
    velocity.setY(sin(angleInRad) * speed);

    angleInDeg = (angleInRad * 180.0 / M_PI) + 90.0;
}

void clsShot::setTexture(SDL_Texture *tex)
{
    texture = tex;
}

void clsShot::update()
{
    // Move the startPosition by the velocity step
    startPosition.setX(startPosition.getX() + velocity.getX());
    startPosition.setY(startPosition.getY() + velocity.getY());
}

void clsShot::render(SDL_Renderer *renderer)
{
    SDL_Rect destRect = {
        (int)(startPosition.getX() - width / 2),
        (int)(startPosition.getY() - height),
        (int)width,
        (int)height};

    SDL_Point pivot;
    pivot.x = width / 2;
    pivot.y = height; // The very bottom of the texture

    SDL_RenderCopyEx(renderer, texture, NULL, &destRect, angleInDeg, &pivot, SDL_FLIP_NONE);
}
