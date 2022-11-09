//
// Created by Павло Коваль on 09.11.2022.
//

#include "Mouse.h"

void Mouse::render()
{
    drawSprite(sprite, xCoordinate-spriteWidth/2, yCoordinate-spriteHeight/2);
}

void Mouse::onMouseMove(int x, int y, int xrelative, int yrelative)
{
    xCoordinate = x;
    yCoordinate = y;
}

Mouse::Mouse()
{
    sprite = createSprite("data/59-Breakout-Tiles.png");
    spriteHeight = 24;
    spriteWidth = 24;

    setSpriteSize(sprite, spriteWidth, spriteHeight);

    xCoordinate = 0;
    yCoordinate = 0;
}


Mouse::~Mouse()
{
    destroySprite(sprite);
}
