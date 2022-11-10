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

    int windowWidth;
    int windowHeight;

public:
    IObject(int x, int y, int width, int height, int windowWidth, int windowHeight);
    ~IObject();

    virtual void render() = 0;

    Sprite *getSprite() const;

    int getX() const;
    int getY() const;

    int getWidth() const;
    int getHeight() const;
};


#endif //ARKANOID_IOBJECT_H
