//
// Created by Павло Коваль on 09.11.2022.
//

#include "Platform.h"
#include <iostream>

void Platform::render()
{
    if (isSprite1)
    {
        sprite = sprite1;
        isSprite1 = false;
        isSprite2 = true;
    }
    else if (isSprite2)
    {
        sprite = sprite2;
        isSprite2 = false;
        isSprite3 = true;
    }
    else if (isSprite3)
    {
        sprite = sprite3;
        isSprite3 = false;
        isSprite1 = true;
    }

    if (isRight)
    {
        xCoordinate = 0.6 + xCoordinate;

        if (xCoordinate > windowRightBorder)
        {
            xCoordinate = windowWidth - 90;
        }
    }

    if (isLeft)
    {
        xCoordinate = xCoordinate - 0.6;

        if (xCoordinate < windowLeftBorder)
        {
            xCoordinate = 0;
        }
    }

    drawSprite(sprite, xCoordinate, windowHeight - (windowHeight * 15) / 100);
}

void Platform::onKeyPressed(FRKey k)
{
    if (k == FRKey::RIGHT)
    {
        isRight = true;
    }
    if (k == FRKey::LEFT)
    {
        isLeft = true;
    }
}

void Platform::onKeyReleased(FRKey k)
{
    if (k == FRKey::LEFT)
    {
        isLeft = false;
    }
    if (k == FRKey::RIGHT)
    {
        isRight = false;
    }
}

Platform::Platform(int width, int height): windowLeftBorder(0), windowRightBorder(width - 90)
{
    this->windowWidth = width;
    this->windowHeight = height;

    sprite1 = createSprite("data/50-Breakout-Tiles.png");
    setSpriteSize(sprite1, 90, 25);

    sprite2 = createSprite("data/51-Breakout-Tiles.png");
    setSpriteSize(sprite2, 90, 25);

    sprite3 = createSprite("data/52-Breakout-Tiles.png");
    setSpriteSize(sprite3, 90, 25);

    sprite = sprite1;

    isSprite1 = true;
    isSprite2 = false;
    isSprite3 = false;
}


Platform::~Platform()
{
    destroySprite(sprite1);
    destroySprite(sprite2);
    destroySprite(sprite3);
}
