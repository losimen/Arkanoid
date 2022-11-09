//
// Created by Павло Коваль on 09.11.2022.
//

#include "MyFramework.h"


const char *MyFramework::GetTitle()
{
    return "Arcanoid";
}


void MyFramework::onKeyReleased(FRKey k)
{
    platform->onKeyReleased(k);
}


void MyFramework::onKeyPressed(FRKey k)
{
    platform->onKeyPressed(k);
}


void MyFramework::onMouseButtonClick(FRMouseButton button, bool isReleased)
{

}


void MyFramework::onMouseMove(int x, int y, int xrelative, int yrelative)
{

}


bool MyFramework::Tick()
{
    platform->render();

    return false;
}


void MyFramework::Close()
{
    delete platform;
}


bool MyFramework::Init()
{
    platform = new Platform();
    return true;
}


void MyFramework::PreInit(int &width, int &height, bool &fullscreen)
{
    width = 530;
    height = 450;
    fullscreen = false;
}
