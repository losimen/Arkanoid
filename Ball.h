//
// Created by Павло Коваль on 10.11.2022.
//

#ifndef ARKANOID_BALL_H
#define ARKANOID_BALL_H

#include "IObject.h"

#include <math.h>


class Ball : public IObject
{
private:
    bool isReleased;

    int speed;
    int direction;

    int platformX;
    int platformY;

    int platformWidth;
    int platformHeight;

    // calculation see setBallDestination method for description
    double fCof1;
    double fX;
    double fY;
    double fK;

    double k;
    double b;

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
