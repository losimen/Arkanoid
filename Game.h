//
// Created by Павло Коваль on 09.11.2022.
//

#ifndef SDL_MYFRAMEWORK_H
#define SDL_MYFRAMEWORK_H

#include "Framework.h"
#include "Platform.h"
#include "Mouse.h"
#include "Ball.h"
#include "Block.h"


class Game : public Framework
{
private:
    Platform *platform;
    Mouse *mouse;
    Ball *ball;
    std::vector<Block*> blocks;

    int width;
    int height;

    enum class HitType
    {
        NONE,
        TOP,
        BOTTOM,
        LEFT,
        RIGHT
    };

public:
    Game(int width, int height);

    void PreInit(int& _width, int& _height, bool& fullscreen) override;
    bool Init() override;

    void Close() override;
    bool Tick() override;

    void onMouseMove(int x, int y, int xRelative, int yRelative) override;
    void onMouseButtonClick(FRMouseButton button, bool isReleased) override;

    void onKeyPressed(FRKey k) override;
    void onKeyReleased(FRKey k) override;

    HitType isCollide(IObject *a, IObject *b);
    void changeBallDirection(HitType hitType);

    const char* GetTitle() override;
};


#endif //SDL_MYFRAMEWORK_H
