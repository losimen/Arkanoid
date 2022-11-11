//
// Created by Павло Коваль on 11.11.2022.
//

#include "InfoTablo.h"

InfoTablo::InfoTablo(int x, int y, int width, int height, int windowWidth, int windowHeight, const char *path)
        : IObject(x, y, width, height, windowWidth, windowHeight)
{
    sprite = createSprite(path);
    setSpriteSize(sprite, width, height);
}


InfoTablo::~InfoTablo()
{

}


void InfoTablo::render()
{
    drawSprite(sprite, x, y);
}
