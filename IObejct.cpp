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
}


Sprite *IObject::getSprite() const {
    return sprite;
}


int IObject::getX() const {
    return x;
}


int IObject::getY() const {
    return y;
}


int IObject::getWidth() const {
    return width;
}


int IObject::getHeight() const {
    return height;
}
