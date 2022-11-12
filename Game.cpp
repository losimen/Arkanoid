//
// Created by Павло Коваль on 09.11.2022.
//

#include "Game.h"
#include <iostream>


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
    // if I do click one time this event will be called twice
    // to prevent this I will do next:
    static int count = 1;

    count++;
    if (count % 2 != 0)
    {
        return;
    }

    if (isLost || isWon)
    {
        startGame();
        return;
    }

    if (!ball->getIsReleased())
    {
        ball->setIsReleased(true);
        ball->setBallDestination(mouse->getX(), mouse->getY());

        mouse->setIsVisible(false);
    }

   // std::cout << "Click " << count << std::endl;
}


void Game::onMouseMove(int x, int y, int xRelative, int yRelative)
{
    if (mouse->getIsVisible())
    {
        mouse->onMouseMove(x, y, xRelative, yRelative);
    }
   //  std::cout << "mouse|| " << "x: " << x << " y: " << y << std::endl;
}


bool Game::Tick()
{
    // TODO: use tick for object movement
    tickStart = getTickCount();
    drawTestBackground();

    if (!isLost  && !isWon)
    {
        playGame();
    }
    if (isLost)
    {
        loseTab->render(tickDelta);
        mouse->render(tickDelta);
    }
    if (isWon)
    {
        winTab->render(tickDelta);
        mouse->render(tickDelta);
    }

    tickDelta = getTickCount() - tickStart;
    return false;
}


void Game::Close()
{

}


bool Game::Init()
{
    showCursor(false);

    platform = new Platform(0, 0, 90, 25, width, height);
    mouse = new Mouse(0, 0, 24, 24, width, height);
    ball = new Ball(0, 0, 24, 24, width, height);
    scoreTab = new ScoreTab(width-200, 0, 100, 75, width, height);

    winTab = new InfoTablo(width/2-250, height/2-100, 500, 200, width, height, "data/winTablo.png");
    loseTab = new InfoTablo(width/2-250, height/2-100, 500, 200, width, height, "data/loseTablo.png");

    // TODO: random blocks generator
    blocks.push_back(new Block(0, 0, 100, 50, width, height, 1, 10, BlockColor::RED));
    blocks.push_back(new Block(100, 0, 100, 50, width, height, 1, 10, BlockColor::RED));
    blocks.push_back(new Block(200, 0, 100, 50, width, height, 1, 10, BlockColor::GREEN));
    blocks.push_back(new Block(200, 50, 100, 50, width, height, 1, 10, BlockColor::ORANGE));
    blocks.push_back(new Block(300, 0, 100, 50, width, height, 1, 10, BlockColor::PURPLE));
    blocks.push_back(new Block(400, 0, 100, 50, width, height, 1, 10, BlockColor::GREEN));
    blocks.push_back(new Block(200, 200, 100, 50, width, height, 1, 10, BlockColor::YELLOW));
    blocks.push_back(new Block(350, 200, 100, 50, width, height, 1, 10, BlockColor::YELLOW));

    // TODO: random abilities generator
    ability50 = new Abilities(0, 0, 100, 24, width, height, AbilitiesType::PLUS_50_SCORES);
    ability100 = new Abilities(0, 0, 100, 24, width, height, AbilitiesType::PLUS_100_SCORES);
    ability250 = new Abilities(0, 0, 100, 24, width, height, AbilitiesType::PLUS_250_SCORES);
    ability500 = new Abilities(0, 0, 100, 24, width, height, AbilitiesType::PLUS_500_SCORES);
    abilitySlow = new Abilities(0, 0, 100, 24, width, height, AbilitiesType::SLOW_PLATFORM);
    abilityFast = new Abilities(0, 0, 100, 24, width, height, AbilitiesType::FAST_PLATFORM);

    ability50->setIsVisible(false);
    ability100->setIsVisible(false);
    ability250->setIsVisible(false);
    ability500->setIsVisible(false);
    abilitySlow->setIsVisible(false);
    abilityFast->setIsVisible(false);

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

    isWon = false;
    isLost = false;
}


Game::HitType Game::isCollide(IObject *a, IObject *b, unsigned int paddingB)
{
    // paddingB - make object bigger than it is
    static const int PADDING = 2;

    if (a->getRight()-PADDING > b->getLeft() - paddingB && a->getLeft()+PADDING < b->getRight() + paddingB)
    {
        if (a->getBottom() > b->getTop() - paddingB && a->getTop() < b->getTop() - paddingB)
        {
            return HitType::TOP;
        }
        else if (a->getTop() < b->getBottom() + paddingB && a->getBottom() > b->getBottom() + paddingB)
        {
            return HitType::BOTTOM;
        }
    }

    else if (a->getBottom() > b->getTop() - paddingB && a->getTop() < b->getBottom() + paddingB)
    {
        if (a->getRight() > b->getLeft() - paddingB && a->getLeft() < b->getLeft() - paddingB)
        {
            return HitType::LEFT;
        }
        else if (a->getLeft() < b->getRight() + paddingB && a->getRight() > b->getRight() + paddingB)
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


void Game::startGame()
{
    ball->setIsReleased(false);
    scoreTab->setBlocksDestroyedROW(0);
    Block::setDestroyedBlocks(0);

    for (auto block : blocks)
    {
        block->setIsVisible(true);
    }

    isLost = false;
    isWon = false;
    std::cout << "Game started" << std::endl;
}


void Game::stopGameLose()
{
    mouse->setIsVisible(true);
    isLost = true;
    scoreTab->setScore(0);

    // TODO: how to clear correctly?
    // sleep???

    std::cout << "Game over" << std::endl;
}


void Game::stopGameWin()
{
    mouse->setIsVisible(true);
    isWon = true;

    // TODO: how to clear correctly?
    // sleep???

    std::cout << "You win!" << std::endl;
}


void Game::playGame()
{
    platform->render(tickDelta);
    ball->render(tickDelta);
    scoreTab->render(tickDelta);

    spawnAbility();

    isCollidePlatformWithAbilities();
    isCollideBallWithPlatform();
    isCollideBallWithBlocks();

    isEndGame();

    for (auto block : blocks)
    {
        block->render(tickDelta);
    }

    for (auto ability : abilitiesOnScreen)
    {
        ability->render(tickDelta);
    }

    if (!ball->getIsReleased())
    {
        ball->setPlatformPosition(platform->getX(), platform->getY());
        ball->setPlatformSize(platform->getWidth(), platform->getHeight());
        mouse->render(tickDelta);
    }
}


Abilities *Game::getRandomAbility()
{
    int num = std::rand() % ( 20000 - 0 + 1 );

    switch (num)
    {
        case 0:
            return ability50;
        case 1:
            return ability100;
        case 2:
            return ability250;
        case 3:
            return ability500;
        case 4:
            return abilitySlow;
        case 5:
            return abilityFast;
        default:
            return nullptr;
    }
}


void Game::isCollideBallWithPlatform()
{
    HitType hitType;
    hitType = isCollide(platform, ball);

    if (hitType != HitType::NONE)
    {
        scoreTab->setBlocksDestroyedROW(0);
        changeBallDirection(hitType);
    }
}


void Game::isCollideBallWithBlocks()
{
    HitType hitType;

    for (int i = 0; i < blocks.size(); i++)
    {
        if (!blocks[i]->getIsVisible())
            continue;

        hitType = isCollide(blocks[i], ball);
        if (hitType != HitType::NONE)
        {
            changeBallDirection(hitType);

            blocks[i]->setIsVisible(false);
            blocks[i]->addDestroyedBlocks(1);
            scoreTab->addBlocksDestroyedROW(1);
            scoreTab->addScore(blocks[i]->getScore());

            // simulate BOOM effect
            if (blocks[i]->isOrange())
            {
                for (int j = 0; j < blocks.size(); j++)
                {
                    if (!blocks[j]->getIsVisible())
                        continue;

                    hitType = isCollide(blocks[j], blocks[i], 10);
                    if (hitType != HitType::NONE)
                    {
                        blocks[j]->setIsVisible(false);
                        blocks[j]->addDestroyedBlocks(1);
                        scoreTab->addBlocksDestroyedROW(1);
                        scoreTab->addScore(blocks[j]->getScore());
                    }
                }
            }
        }
    }
}


void Game::isCollidePlatformWithAbilities()
{
    for (int i = 0; i < abilitiesOnScreen.size(); i++)
    {
        if (abilitiesOnScreen[i]->getY() > height-50)
        {
            abilitiesOnScreen[i]->setIsVisible(false);
            abilitiesOnScreen.erase(abilitiesOnScreen.begin() + i);
        }

        if (isCollide(abilitiesOnScreen[i], platform) != HitType::NONE)
        {
            abilitiesOnScreen[i]->setIsVisible(false);

            if (abilitiesOnScreen[i]->getType() == AbilitiesType::PLUS_50_SCORES)
            {
                scoreTab->addScore(50);
            }
            else if (abilitiesOnScreen[i]->getType() == AbilitiesType::PLUS_100_SCORES)
            {
                scoreTab->addScore(100);
            }
            else if (abilitiesOnScreen[i]->getType() == AbilitiesType::PLUS_250_SCORES)
            {
                scoreTab->addScore(250);
            }
            else if (abilitiesOnScreen[i]->getType() == AbilitiesType::PLUS_500_SCORES)
            {
                scoreTab->addScore(500);
            }
            else if (abilitiesOnScreen[i]->getType() == AbilitiesType::SLOW_PLATFORM)
            {
                if (platform->getSpeed() > 1)
                {
                    platform->setSpeed(platform->getSpeed() - 2);
                }
            }
            else if (abilitiesOnScreen[i]->getType() == AbilitiesType::FAST_PLATFORM)
            {
                if (platform->getSpeed() < 10)
                {
                    platform->setSpeed(platform->getSpeed() + 1);
                }
            }

            abilitiesOnScreen.erase(abilitiesOnScreen.begin() + i);
        }
    }
}


void Game::spawnAbility()
{
    Abilities *ability = getRandomAbility();

    if (ability != nullptr)
    {
        if (!ability->getIsVisible())
        {
            ability->setIsVisible(true);
            ability->setX(std::rand() % ( width - 1 + 1 ));
            ability->setY(0);
            abilitiesOnScreen.push_back(ability);
        }
    }
}


void Game::isEndGame()
{
    if (ball->getY() > height-50)
    {
        isLost = true;
        stopGameLose();
    }

    if (blocks.size() == Block::getDestroyedBlocks())
    {
        isWon = true;
        stopGameWin();
    }
}
