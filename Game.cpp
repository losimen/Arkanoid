//
// Created by Павло Коваль on 09.11.2022.
//

#include "Game.h"


const char *Game::GetTitle()
{
    return "Arcanoid";
}


void Game::onKeyReleased(FRKey k)
{
    platform->onKeyReleased(k);
}


void Game::onKeyPressed(FRKey k)
{
    platform->onKeyPressed(k);
}


void Game::onMouseButtonClick(FRMouseButton button, bool isReleased)
{
    if (!ball->getIsReleased())
    {
        ball->setIsReleased(true);
        ball->setBallDestination(mouse->getX(), mouse->getY());
        destroySprite(mouse->getSprite());
    }
}


void Game::onMouseMove(int x, int y, int xRelative, int yRelative)
{
    if (!ball->getIsReleased())
    {
        mouse->onMouseMove(x, y, xRelative, yRelative);
    }
}


bool Game::Tick()
{
    drawTestBackground();
    platform->render();

    if (!ball->getIsReleased())
    {
        mouse->render();
    }

    ball->setPlatformPosition(platform->getX(), platform->getY());
    ball->setPlatformSize(platform->getWidth(), platform->getHeight());
    ball->render();

    return false;
}


void Game::Close()
{
    delete platform;
    delete mouse;
    delete ball;
}


bool Game::Init()
{
    platform = new Platform(0, 0, 90, 25, width, height);
    mouse = new Mouse(0, 0, 24, 24, width, height);
    ball = new Ball(0, 0, 24, 24, width, height);

    return true;
}


void Game::PreInit(int &_width, int &_height, bool &fullscreen)
{
    _width = this->width;
    _height = this->height;

    fullscreen = false;
}


Game::Game(int width, int height)
{
    this->width = width;
    this->height = height;
}
