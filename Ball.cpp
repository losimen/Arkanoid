//
// Created by Павло Коваль on 10.11.2022.
//

#include "Ball.h"


void Ball::render()
{
    if (isReleased)
    {
       // std::cout << "x: " << x << " y: " << y << std::endl;
        xB = xB - stepX;
        yB = yB - stepY;
    }
    else
    {
        xB = platformX + (platformWidth-width) / 2;
        yB = platformY - height;
    }

    drawSprite( sprite, xB, yB);
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
    // --------------------------------------------------------------------------------------------------------
    // Find ball route by drawing linear function
    // we have 2 points :
    //    1. x, y - next position of the ball
    //    2. this->x, this->y - current ball position
    // using formula y = ( (y2-y1)/(x2-x1) ) * (x - x1) + y1 (3)
    // https://www.mathros.net.ua/rivnjannja-prjamoi-jaka-prohodyt-cherez-dvi-zadani-tochky.html
    // we will get linear function and (inc/dec)rementing this->x
    // we will know this->y
    // --------------------------------------------------------------------------------------------------------
    double xMouse = x;
    double yMouse = y;

    double xOffset = std::fabs(xMouse - xB);
    double yOffset = std::fabs(yMouse - yB);

    double hypotensive = sqrt(pow(xOffset, 2) + pow(yOffset, 2));

    stepX = xOffset / hypotensive;
    stepY = yOffset / hypotensive;
    // std::cout << "y = " << k << "*x + " << b << std::endl;
}
