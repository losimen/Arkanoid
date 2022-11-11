//
// Created by Павло Коваль on 10.11.2022.
//

#ifndef ARKANOID_BALL_H
#define ARKANOID_BALL_H

#include "IObject.h"

#include <cmath>


#define PI 3.14159265
#define DEGREES_TO_RADIANS(angle) ((angle) * PI / 180.0)


class Ball : public IObject
{
private:
    bool isReleased;

    int platformX;
    int platformY;

    int platformWidth;
    int platformHeight;

    double stepX;
    double stepY;

    int dirX;
    int dirY;

    void isBallHitPlatform();
    void isBallHitBorder();

public:
    Ball(int x, int y, int width, int height, int speed, int direction);
    ~Ball();

    void setPlatformPosition(int x, int y);
    void setPlatformSize(int width, int height);
    void setIsReleased(bool isReleased);
    void setBallDestination(int x, int y);

    void render() override;

    bool getIsReleased() const;

};


#endif //ARKANOID_BALL_H
