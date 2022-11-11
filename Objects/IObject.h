//
// Created by Павло Коваль on 09.11.2022.
//

#ifndef ARKANOID_IOBJECT_H
#define ARKANOID_IOBJECT_H

#include "Framework.h"
#include <vector>
#include <iostream>

class IObject
{
protected:
    Sprite *sprite;

    double x;
    double y;

    int width;
    int height;

    int windowWidth;
    int windowHeight;

    bool isVisible;
public:
    IObject(int x, int y, int width, int height, int windowWidth, int windowHeight);
    ~IObject();

    virtual void render() = 0;

    Sprite *getSprite() const;

    double getX() const;
    double getY() const;

    int getWidth() const;
    int getHeight() const;

    int getTop() const;
    int getBottom() const;
    int getLeft() const;
    int getRight() const;

    bool getIsVisible() const;
    void setIsVisible(bool isVisible);
};


#endif //ARKANOID_IOBJECT_H
