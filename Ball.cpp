//
// Created by Павло Коваль on 10.11.2022.
//

#include "Ball.h"


void Ball::render()
{
    if (isReleased)
    {
        // TODO: improve formula counting processor ticks
        int speed = 2;
        isBallHitBorder();

        // std::cout << "x: " << x << " y: " << y << std::endl;
        x = x - stepX * dirX * speed;
        y = y - stepY * dirY * speed;
    }
    else
    {
        x = (platformX + (platformWidth-width) / 2);
        y = (platformY - height)-5;
    }

    drawSprite( sprite, x, y);
}


Ball::Ball(int x, int y, int width, int height, int windowWidth, int windowHeight) :
                                                IObject(x, y, width, height, windowWidth, windowHeight)
{
    sprite = createSprite("data/watermelon.png");
    isReleased = false;

    platformX = 0;
    platformY = 0;

    platformWidth = 0;
    platformHeight = 0;

    dirX = 1;
    dirY = 1;

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


void Ball::setIsReleased(bool _isReleased)
{
    isReleased = _isReleased;
}


Ball::~Ball()
{

}


void Ball::setBallDestination(int x, int y)
{
    /*
      **********DEPRECATED**********DEPRECATED**********DEPRECATED**********DEPRECATED**********DEPRECATED
      DEPRECATED**********DEPRECATED**********DEPRECATED**********DEPRECATED**********DEPRECATED***********
     --------------------------------------------------------------------------------------------------------
      **********DEPRECATED**********DEPRECATED**********DEPRECATED**********DEPRECATED**********DEPRECATED
      DEPRECATED**********DEPRECATED**********DEPRECATED**********DEPRECATED**********DEPRECATED***********
                     Find ball route by drawing linear function
                     we have 2 points :
                        1. x, y - next position of the ball
                        2. this->x, this->y - current ball position
                     using formula y = ( (y2-y1)/(x2-x1) ) * (x - x1) + y1 (3)
                     https://www.mathros.net.ua/rivnjannja-prjamoi-jaka-prohodyt-cherez-dvi-zadani-tochky.html
                     we will get linear function and (inc/dec)rementing this->x
                     we will know this->y
      **********DEPRECATED**********DEPRECATED**********DEPRECATED**********DEPRECATED**********DEPRECATED
      DEPRECATED**********DEPRECATED**********DEPRECATED**********DEPRECATED**********DEPRECATED***********
     --------------------------------------------------------------------------------------------------------
      **********DEPRECATED**********DEPRECATED**********DEPRECATED**********DEPRECATED**********DEPRECATED
      DEPRECATED**********DEPRECATED**********DEPRECATED**********DEPRECATED**********DEPRECATED***********


     New algorithm:
          Description soon...
    */
    // TODO: add description
    double xMouse = x;
    double yMouse = y;

    if (xMouse > this->x)
    {
        dirX = -dirX;
    }

    double xOffset = std::fabs(xMouse - this->x);
    double yOffset = std::fabs(yMouse - this->y);

    double hypotensive = sqrt(pow(xOffset, 2) + pow(yOffset, 2));

    stepX = xOffset / hypotensive;
    stepY = yOffset / hypotensive;
    // std::cout << "y = " << k << "*x + " << b << std::endl;
}


void Ball::isBallHitBorder()
{
    if (x + width > windowWidth)
    {
        dirX = 1;
    }
    if (x < 0)
    {
        dirX = -1;
    }
    if (y < 0)
    {
        dirY = -1;
    }
    if (y + height > windowHeight)
    {
        dirY = 1;
    }
}


void Ball::setDirY(int _dirY)
{
    this->dirY = _dirY;
}


void Ball::setDirX(int _dirX)
{
    this->dirX = _dirX;
}
