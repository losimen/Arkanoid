//
// Created by Павло Коваль on 11.11.2022.
//

#ifndef ARKANOID_INFOTABLO_H
#define ARKANOID_INFOTABLO_H

#include "IObject.h"


class InfoTablo: public IObject
{
public:
    InfoTablo(int x, int y, int width, int height, int windowWidth, int windowHeight, const char *path);
    ~InfoTablo();

    void render() override;
};


#endif //ARKANOID_INFOTABLO_H
