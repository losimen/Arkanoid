//
// Created by Павло Коваль on 10.11.2022.
//

#ifndef ARKANOID_BALL_H
#define ARKANOID_BALL_H

#include "IObject.h"


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

public:
    Ball(int x, int y, int width, int height, int speed, int direction);

    void setPlatformPosition(int x, int y);
    void setPlatformSize(int width, int height);

    void render() override;
};


#endif //ARKANOID_BALL_H
