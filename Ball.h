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

    int speed;
    int direction;

    int speedX;
    int velocityY;

    int platformX;
    int platformY;

    int platformWidth;
    int platformHeight;

    // calculation see setBallDestination method for description
    double k;
    double b;

    double stepX;
    double stepY;

    double xB;
    double yB;

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
