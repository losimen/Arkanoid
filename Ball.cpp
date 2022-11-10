//
// Created by Павло Коваль on 10.11.2022.
//

#include "Ball.h"


void Ball::render()
{
    drawSprite(sprite, x, y);
}

Ball::Ball(int x, int y, int width, int height, int windowWidth, int windowHeight) :
                                                IObject(x, y, width, height, windowWidth, windowHeight)
{
    sprite = createSprite("data/62-Breakout-Tiles.png");
    setSpriteSize(sprite, width, height);
}
