//
// Created by Павло Коваль on 10.11.2022.
//

#include "Ball.h"


void Ball::render()
{
    if (isReleased)
    {
//        x += speed * cos(direction);
//        y += speed * sin(direction);
    }
    else
    {
        x = platformX + (platformWidth-width) / 2;
        y = platformY - height;
    }

    drawSprite(sprite, x, y);
}


Ball::Ball(int x, int y, int width, int height, int windowWidth, int windowHeight) :
                                                IObject(x, y, width, height, windowWidth, windowHeight)
{
    sprite = createSprite("data/62-Breakout-Tiles.png");
    isReleased = false;

    platformX = 0;
    platformY = 0;

    platformWidth = 0;
    platformHeight = 0;

    setSpriteSize(sprite, width, height);
}


void Ball::setPlatformPosition(int x, int y)
{
    platformX = x;
    platformY = y;
}

void Ball::setPlatformSize(int width, int height)
{
    platformWidth = width;
    platformHeight = height;
}
