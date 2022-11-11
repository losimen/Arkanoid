//
// Created by Павло Коваль on 09.11.2022.
//

#include "Platform.h"


void Platform::render()
{
    switch(currentSprite)
    {
        case PlatformSprite::SPRITE1:
            sprite = sprite1;
            currentSprite = PlatformSprite::SPRITE2;
            break;
        case PlatformSprite::SPRITE2:
            sprite = sprite2;
            currentSprite = PlatformSprite::SPRITE3;
            break;
        case PlatformSprite::SPRITE3:
            sprite = sprite3;
            currentSprite = PlatformSprite::SPRITE1;
            break;
    }

    if (isRight)
    {
        x = x + speed;

        if (x > windowRightBorder)
        {
            x = windowWidth - width;
        }
    }

    if (isLeft)
    {
        x = x - speed;

        if (x < windowLeftBorder)
        {
            x = 0;
        }
    }

    drawSprite(sprite, x, y);
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


Platform::Platform(int x, int y, int width, int height, int windowWidth, int windowHeight):
                                                       IObject(x, y, width, height, windowWidth, windowHeight),
                                                       windowLeftBorder(0),
                                                       windowRightBorder(windowWidth - width)

{
    speed = 2.5;

    isLeft = false;
    isRight = false;

    this->x = (windowWidth - width) / 2;
    // 15% of the window height
    this->y = windowHeight - (windowHeight * 15) / 100;

    sprite1 = createSprite("data/50-Breakout-Tiles.png");
    setSpriteSize(sprite1, width, height);

    sprite2 = createSprite("data/51-Breakout-Tiles.png");
    setSpriteSize(sprite2, width, height);

    sprite3 = createSprite("data/52-Breakout-Tiles.png");
    setSpriteSize(sprite3, width, height);

    sprite = sprite1;
    currentSprite = PlatformSprite::SPRITE1;
}


Platform::~Platform()
{
    sprite = nullptr;

    if (sprite1 != nullptr)
    {
        destroySprite(sprite1);
    }
    if (sprite2 != nullptr)
    {
        destroySprite(sprite2);
    }
    if (sprite3 != nullptr)
    {
        destroySprite(sprite3);
    }
}
