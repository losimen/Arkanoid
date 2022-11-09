//
// Created by Павло Коваль on 09.11.2022.
//

#include "Platform.h"

void Platform::render()
{
    if (isRight)
    {
        x_coordinate = (0.6 + x_coordinate);
    }

    if (isLeft)
    {
        x_coordinate = (x_coordinate - 0.6);
    }

    drawSprite(sprite, x_coordinate, 450 - (450 * 15) / 100);
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

Platform::Platform()
{
    if (sprite == nullptr)
    {
        sprite = createSprite("data/50-Breakout-Tiles.png");
        setSpriteSize(sprite, 90, 25);
    }
}


Platform::~Platform()
{
    if (sprite != nullptr)
    {
        destroySprite(sprite);
    }
}
