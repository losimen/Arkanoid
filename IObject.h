//
// Created by Павло Коваль on 09.11.2022.
//

#ifndef ARKANOID_IOBJECT_H
#define ARKANOID_IOBJECT_H

#include "Framework.h"


class IObject
{
protected:
    Sprite *sprite;

    int x;
    int y;

    int width;
    int height;

public:
    IObject(int _x, int _y, int _width, int _height);

    virtual void render() = 0;
};


#endif //ARKANOID_IOBJECT_H
