//
// Created by Павло Коваль on 09.11.2022.
//

#ifndef SDL_MYFRAMEWORK_H
#define SDL_MYFRAMEWORK_H

#include "Framework.h"
#include <iostream>

/* Test Framework realization */


class MyFramework : public Framework {

public:

    void PreInit(int& width, int& height, bool& fullscreen) override;
    bool Init() override;

    void Close() override;
    bool Tick() override;

    void onMouseMove(int x, int y, int xrelative, int yrelative) override;
    void onMouseButtonClick(FRMouseButton button, bool isReleased) override;

    void onKeyPressed(FRKey k) override;
    void onKeyReleased(FRKey k) override;

    const char* GetTitle() override;
};


#endif //SDL_MYFRAMEWORK_H
