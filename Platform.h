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

    // animation
    Sprite *sprite1;
    Sprite *sprite2;
    Sprite *sprite3;

    enum class PlatformSprite
    {
        SPRITE1,
        SPRITE2,
        SPRITE3
    } currentSprite;

    bool isRight;
    bool isLeft;

    int speed;

public:
    Platform(int x, int y, int width, int height, int windowWidth, int windowHeight);
    ~Platform();

    void render() override;

    void onKeyPressed(FRKey k);
    void onKeyReleased(FRKey k);
};


#endif //ARKANOID_PLATFORM_H
