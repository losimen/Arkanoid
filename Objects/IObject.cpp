//
// Created by Павло Коваль on 10.11.2022.
//

#include "IObject.h"


IObject::IObject(int x, int y, int width, int height, int windowWidth, int windowHeight)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;
    isVisible = true;
}


Sprite *IObject::getSprite() const {
    return sprite;
}


double IObject::getX() const
{
    return x;
}


double IObject::getY() const
{
    return y;
}


int IObject::getWidth() const
{
    return width;
}


int IObject::getHeight() const
{
    return height;
}


IObject::~IObject()
{
    // TODO: memory leak???
//    if (sprite != nullptr)
//    {
//        destroySprite(sprite);
//    }
}


int IObject::getTop() const
{
    return y;
}


int IObject::getBottom() const
{
    return y+height;
}


int IObject::getLeft() const
{
    return x;
}


int IObject::getRight() const
{
    return x+width;
}

bool IObject::getIsVisible() const
{
    return isVisible;
}

void IObject::setIsVisible(bool isVisible)
{
    this->isVisible = isVisible;
}
