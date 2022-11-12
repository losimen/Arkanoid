//
// Created by Павло Коваль on 10.11.2022.
//

#ifndef ARKANOID_BALL_H
#define ARKANOID_BALL_H

#include "IObject.h"

#include <cmath>


class Ball : public IObject
{
private:
    bool isReleased;

    int platformX;
    int platformY;

    int platformWidth;
    int platformHeight;

    Sprite *sprite1;
    Sprite *sprite2;
    Sprite *sprite3;

    enum class BallSprite
    {
        SPRITE1,
        SPRITE2,
        SPRITE3
    } currentSprite;

    double stepX;
    double stepY;

    int dirX;
    int dirY;

    void isBallHitBorder();
    int speed;

public:
    Ball(int x, int y, int width, int height, int speed, int direction);
    ~Ball();

    void setPlatformPosition(int x, int y);
    void setPlatformSize(int width, int height);
    void setIsReleased(bool isReleased);
    void setBallDestination(int x, int y);

    void setDirY(int dirY);
    void setDirX(int dirX);

    void render(unsigned int timeDelta) override;

    bool getIsReleased() const;

};


#endif //ARKANOID_BALL_H
