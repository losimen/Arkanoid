//
// Created by Павло Коваль on 09.11.2022.
//

#ifndef ARKANOID_MOUSE_H
#define ARKANOID_MOUSE_H

#include "IObject.h"


class Mouse: public IObject
{
private:
    Sprite *sprite;

    int xCoordinate;
    int yCoordinate;

    int spriteWidth;
    int spriteHeight;
public:
    Mouse();
    ~Mouse();

    void render() override;
    void onMouseMove(int x, int y, int xrelative, int yrelative);

};


#endif //ARKANOID_MOUSE_H
