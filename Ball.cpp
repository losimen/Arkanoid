//
// Created by Павло Коваль on 10.11.2022.
//

#include "Ball.h"
#include <iostream>


void Ball::render()
{
    if (isReleased)
    {
        // LEFT EDGE
        if (x < 0)
        {
            speedX = -speedX;
        }
        // TOP EDGE
        if (y < 0)
        {
            speedX = -speedX;
        }
        // RIGHT EDGE
        if (x > windowWidth - width)
        {
            speedX = -speedX;
        }
        // BOTTOM EDGE
        if (y > windowHeight - height)
        {
            speedX = -speedX;
        }

       // std::cout << "x: " << x << " y: " << y << std::endl;
        x = x - speedX;
        y = k * x + b;
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

    speed = 1;

    platformWidth = 0;
    platformHeight = 0;

    speedX = 1;
    velocityY = 1;

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


bool Ball::getIsReleased() const
{
    return isReleased;
}


void Ball::setIsReleased(bool isReleased)
{
    this->isReleased = isReleased;
}


Ball::~Ball()
{

}


void Ball::setBallDestination(int x, int y)
{
    // Find ball route by drawing linear function
    // we have 2 points :
    //    1. x, y - mouse position
    //    2. this->x, this->y - current ball position
    // using formula y = ( (y2-y1)/(x2-x1) ) * (x - x1) + y1 (3)
    // https://www.mathros.net.ua/rivnjannja-prjamoi-jaka-prohodyt-cherez-dvi-zadani-tochky.html
    // we will get linear function and (inc/dec)rementing this->x
    // we will know this->y
    // --------------------------------------------------------------------------------------------------------

    double y2 = this->y;
    double y1 = y;

    double x2 = this->x;
    double x1 = x;

    k = (y2 - y1)/(x2 - x1);
    b = (x2*y1 - x1*y2)/(x2 - x1);

    if (k < 0)
        speedX = -1;

    std::cout << "y = " << k << "*x + " << b << std::endl;

}
