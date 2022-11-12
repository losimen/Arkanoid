//
// Created by Павло Коваль on 09.11.2022.
//

#ifndef SDL_MYFRAMEWORK_H
#define SDL_MYFRAMEWORK_H

#include "Framework.h"
#include "Platform.h"
#include "Mouse.h"
#include "Ball.h"
#include "Block.h"
#include "ScoreTab.h"
#include "InfoTablo.h"
#include "Abilities.h"

#include <random>


class Game : public Framework
{
private:
    Platform *platform;
    Mouse *mouse;
    Ball *ball;
    std::vector<Block*> blocks;
    ScoreTab *scoreTab;

    InfoTablo *winTab;
    InfoTablo *loseTab;

    // TODO: abilities random generator
    Abilities *ability50;
    Abilities *ability100;
    Abilities *ability250;
    Abilities *ability500;
    Abilities *abilitySlow;
    Abilities *abilityFast;

    std::vector<Abilities*> abilitiesOnScreen;

    int width;
    int height;

    enum class HitType
    {
        NONE,
        TOP,
        BOTTOM,
        LEFT,
        RIGHT
    };

    bool isLost;
    bool isWon;

    Abilities *getRandomAbility();

    void startGame();
    void stopGameLose();
    void stopGameWin();
    void playGame();

    void isCollideBallWithPlatform();
    void isCollideBallWithBlocks();
    void isCollidePlatformWithAbilities();
    void isEndGame();
    void spawnAbility();

    HitType isCollide(IObject *a, IObject *b, unsigned int paddingB = 0);
    void changeBallDirection(HitType hitType);

public:
    Game(int width, int height);

    void PreInit(int& _width, int& _height, bool& fullscreen) override;
    bool Init() override;

    void Close() override;
    bool Tick() override;

    void onMouseMove(int x, int y, int xRelative, int yRelative) override;
    void onMouseButtonClick(FRMouseButton button, bool isReleased) override;

    void onKeyPressed(FRKey k) override;
    void onKeyReleased(FRKey k) override;

    const char* GetTitle() override;
};


#endif //SDL_MYFRAMEWORK_H
