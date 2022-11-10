//
// Created by Павло Коваль on 09.11.2022.
//

#include "Mouse.h"

void Mouse::render()
{
    drawSprite(sprite, x - width / 2, y - height / 2);
}

void Mouse::onMouseMove(int _x, int _y, int xRelative, int yRelative)
{
    x = _x;
    y = _y;
}

Mouse::Mouse(): IObject(0, 0, 24, 24)
{
    sprite = createSprite("data/59-Breakout-Tiles.png");

    setSpriteSize(sprite, width, height);

    x = 0;
    y = 0;
}


Mouse::~Mouse()
{
    destroySprite(sprite);
}
