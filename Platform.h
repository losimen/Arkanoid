//
// Created by Павло Коваль on 09.11.2022.
//

#ifndef ARKANOID_PLATFORM_H
#define ARKANOID_PLATFORM_H

#include "IObject.h"


class Platform: public IObject
{
private:
    const int windowLeftBorder;
    const int windowRightBorder;

    int windowWidth;
    int windowHeight;

    // animation
    Sprite *sprite1;
    Sprite *sprite2;
    Sprite *sprite3;

    bool isSprite1;
    bool isSprite2;
    bool isSprite3;

    // current sprite
    Sprite *sprite = nullptr;

    float xCoordinate = 0;

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
