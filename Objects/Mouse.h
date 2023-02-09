//
// Created by Павло Коваль on 09.11.2022.
//

#ifndef ARKANOID_MOUSE_H
#define ARKANOID_MOUSE_H

#include "IObject.h"


class Mouse: public IObject
{
public:
    Mouse(int x, int y, int width, int height, int windowWidth, int windowHeight);
    ~Mouse() override;

    void render(unsigned int timeDelta) override;
    void onMouseMove(int x, int y, int xRelative, int yRelative);

};


#endif //ARKANOID_MOUSE_H
