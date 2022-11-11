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
        ball->setPlatformPosition(platform->getX(), platform->getY());
        ball->setPlatformSize(platform->getWidth(), platform->getHeight());
        mouse->render();
    }

    for (auto block : blocks)
    {
        block->render();
    }

    HitType hitType = isCollide(platform, ball);
    if (hitType != HitType::NONE)
    {
        changeBallDirection(hitType);
    }

    for (int i = 0; i < blocks.size(); i++)
    {
        hitType = isCollide(blocks[i], ball);
        if (hitType != HitType::NONE)
        {
            changeBallDirection(hitType);
            blocks.erase(blocks.begin() + i);
        }
    }

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

    blocks.push_back(new Block(0, 0, 100, 50, width, height, 1, 100, BlockColor::BLUE));
    blocks.push_back(new Block(100, 0, 100, 50, width, height, 1, 100, BlockColor::RED));
    blocks.push_back(new Block(200, 0, 100, 50, width, height, 1, 100, BlockColor::GREEN));
    blocks.push_back(new Block(300, 0, 100, 50, width, height, 1, 100, BlockColor::PURPLE));
    blocks.push_back(new Block(400, 0, 100, 50, width, height, 1, 100, BlockColor::GREEN));
    blocks.push_back(new Block(200, 200, 100, 50, width, height, 1, 100, BlockColor::YELLOW));

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


Game::HitType Game::isCollide(IObject *a, IObject *b)
{
    if (a->getRight() > b->getLeft() && a->getLeft() < b->getRight())
    {
        if (a->getBottom() > b->getTop() && a->getTop() < b->getTop())
        {
            return HitType::TOP;
        }
        else if (a->getTop() < b->getBottom() && a->getBottom() > b->getBottom())
        {
            return HitType::BOTTOM;
        }
    }

    else if (a->getBottom() > b->getTop() && a->getTop() < b->getBottom())
    {
        if (a->getRight() > b->getLeft() && a->getLeft() < b->getLeft())
        {
            return HitType::LEFT;
        }
        else if (a->getLeft() < b->getRight() && a->getRight() > b->getRight())
        {
            return HitType::RIGHT;
        }
    }

    return HitType::NONE;
}

void Game::changeBallDirection(Game::HitType hitType)
{
    if (hitType == HitType::NONE)
        return;

    if (hitType == HitType::TOP)
    {
        ball->setDirY(-1);
    }
    else if (hitType == HitType::BOTTOM)
    {
        ball->setDirY(1);
    }
    else if (hitType == HitType::LEFT)
    {
        ball->setDirX(-1);
    }
    else
    {
        ball->setDirX(1);
    }
}
