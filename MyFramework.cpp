//
// Created by Павло Коваль on 09.11.2022.
//

#include "MyFramework.h"

Sprite *sprite = nullptr;

float x_coordinate = 0;

bool isRight = false;
bool isLeft = false;

int kRight = 1;
int kLeft = 1;


const char *MyFramework::GetTitle()
{
    return "Arcanoid";
}


void MyFramework::onKeyReleased(FRKey k)
{
    if (k == FRKey::LEFT)
    {
        isLeft = false;
    }
    if (k == FRKey::RIGHT)
    {
        isRight = false;
    }
}


void MyFramework::onKeyPressed(FRKey k)
{
    if (k == FRKey::RIGHT)
    {
        isRight = true;
    }
    if (k == FRKey::LEFT)
    {
        isLeft = true;
    }
}


void MyFramework::onMouseButtonClick(FRMouseButton button, bool isReleased)
{

}


void MyFramework::onMouseMove(int x, int y, int xrelative, int yrelative)
{

}


bool MyFramework::Tick()
{
    if (sprite == nullptr)
    {
        sprite = createSprite("data/50-Breakout-Tiles.png");
        setSpriteSize(sprite, 90, 25);
    }

    if (isRight)
    {
        x_coordinate = (0.6 + x_coordinate) * kRight;
    }

    if (isLeft)
    {
        x_coordinate = (x_coordinate - 0.6) * kLeft;
    }

    drawSprite(sprite, x_coordinate, 450 - (450 * 15) / 100);
    return false;
}


void MyFramework::Close()
{

}


bool MyFramework::Init()
{
    return true;
}


void MyFramework::PreInit(int &width, int &height, bool &fullscreen)
{
    width = 530;
    height = 450;
    fullscreen = false;
}
