//
// Created by Павло Коваль on 10.11.2022.
//

#include "Ball.h"

void Ball::render()
{

}

Ball::Ball(): IObject(0, 0, 24, 24)
{
    sprite = createSprite("data/59-Breakout-Tiles.png");

    setSpriteSize(sprite, width, height);

    x = 0;
    y = 0;
}
