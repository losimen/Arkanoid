//
// Created by Павло Коваль on 10.11.2022.
//

#ifndef ARKANOID_BALL_H
#define ARKANOID_BALL_H

#include "IObject.h"


class Ball : public IObject
{
private:
    int speed;
    int direction;

public:
    Ball();
    void render() override;
};


#endif //ARKANOID_BALL_H
