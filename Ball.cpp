//
// Created by Павло Коваль on 10.11.2022.
//

#include "Ball.h"
#include <iostream>


void Ball::render()
{
    if (isReleased)
    {

//        isReleased = true;
//        x = x - 0.1;
//        y = k*x + b;
        x -= 1;
        y -= 1;
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
    // Modifying formula:
    //      a) x1, y1 |=> x, y
    //      b) x2, y2 |=> fX, fY
    //      c) x,  y  |=> this->x, this->y
    //      d) (y2-y1)/(x2-x1) |=> fCof1
    // y = fCof1 * (x - x1) + y1
    // y = fCof1 * x - fCof1*x1 + y1
    // y = fCof1 * x + fK

//    double k = (y2 - y1)/(x2 - x1);
//    double b = (x2*y1 - x1*y2)/(x2 - x1);
//    std::cout << "x: " << x << " y: " << y << std::endl;
//    std::cout << "this->x: " << this->x << " this->y: " << this->y << std::endl;
//
//    double y2 = this->y;
//    double y1 = y;
//
//    double x2 = this->x;
//    double x1 = x;
//
//    k = (y2 - y1)/(x2 - x1);
//    b = (x2*y1 - x1*y2)/(x2 - x1);
//
//    std::cout << "y = " << k << " * x" << " + " << b << std::endl;
//    fCof1 = (y-this->y)/(x-this->x);
//    fK = -fCof1*x + y;


}
