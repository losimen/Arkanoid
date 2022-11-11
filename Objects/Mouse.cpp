//
// Created by Павло Коваль on 09.11.2022.
//

#include "Mouse.h"

void Mouse::render()
{
    if (!isVisible)
        return;
    drawSprite(sprite, x - width / 2, y - height / 2);
}

void Mouse::onMouseMove(int _x, int _y, int xRelative, int yRelative)
{
    x = _x;
    y = _y;
}


Mouse::~Mouse()
{
}

Mouse::Mouse(int x, int y, int width, int height, int windowWidth, int windowHeight) : IObject(x, y, width, height,
                                                                                               windowWidth,
                                                                                               windowHeight)
{
    sprite = createSprite("data/59-Breakout-Tiles.png");
    setSpriteSize(sprite, width, height);
}
