//
// Created by Павло Коваль on 10.11.2022.
//

#include "Ball.h"


void Ball::render(unsigned int timeDelta)
{
    if (isReleased)
    {
        isBallHitBorder();

        switch(currentSprite)
        {
            case BallSprite::SPRITE1:
                sprite = sprite1;
                currentSprite = BallSprite::SPRITE2;
                break;
            case BallSprite::SPRITE2:
                sprite = sprite2;
                currentSprite = BallSprite::SPRITE3;
                break;
            case BallSprite::SPRITE3:
                sprite = sprite3;
                currentSprite = BallSprite::SPRITE1;
                break;
        }

        // std::cout << "x: " << x << " y: " << y << std::endl;
        // TODO: optimize this
//        x = x - stepX * dirX * speed *  timeDelta;
//        y = y - stepY * dirY * speed * timeDelta;

        x = x - stepX * dirX * speed;
        y = y - stepY * dirY * speed;
    }
    else
    {
        // put in the top middle of platform
        x = (platformX + (platformWidth-width) / 2);
        y = (platformY - height)-5;
    }

    //std::cout << "ball|| " << "x: " << x << " y: " << y << std::endl;
    drawSprite( sprite, x, y);
}


Ball::Ball(int x, int y, int width, int height, int windowWidth, int windowHeight) :
                                                IObject(x, y, width, height, windowWidth, windowHeight)
{
    isReleased = false;

    platformX = 0;
    platformY = 0;

    platformWidth = 0;
    platformHeight = 0;

    speed = 2;

    sprite1 = createSprite("data/90.png");
    setSpriteSize(sprite1, width, height);

    sprite2 = createSprite("data/45.png");
    setSpriteSize(sprite2, width, height);

    sprite3 = createSprite("data/-45.png");
    setSpriteSize(sprite3, width, height);

    currentSprite = BallSprite::SPRITE1;
    sprite = sprite1;

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
          look up in file INFO/Ball.pdf
    */
    dirY = 1;
    dirX = 1;

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
