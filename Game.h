//
// Created by Павло Коваль on 09.11.2022.
//

#ifndef SDL_MYFRAMEWORK_H
#define SDL_MYFRAMEWORK_H

#include "Framework.h"
#include "Platform.h"
#include "Mouse.h"
#include "Ball.h"


class Game : public Framework
{
private:
    Platform *platform;
    Mouse *mouse;

    int width;
    int height;

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

    const char* GetTitle() override;
};


#endif //SDL_MYFRAMEWORK_H
