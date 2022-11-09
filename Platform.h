//
// Created by Павло Коваль on 09.11.2022.
//

#ifndef ARKANOID_PLATFORM_H
#define ARKANOID_PLATFORM_H

#include "IObject.h"


class Platform: public IObject
{
private:
    int windowWidth;
    int windowHeight;

    Sprite *sprite = nullptr;

    float x_coordinate = 0;

    bool isRight = false;
    bool isLeft = false;

public:
    Platform(int width, int height);
    ~Platform();

    void render() override;

    void onKeyPressed(FRKey k);
    void onKeyReleased(FRKey k);
};


#endif //ARKANOID_PLATFORM_H
