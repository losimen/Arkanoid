//
// Created by Павло Коваль on 11.11.2022.
//

#ifndef ARKANOID_SCORETAB_H
#define ARKANOID_SCORETAB_H

#include "IObject.h"
#include <array>

class ScoreTab : public IObject
{
private:
    // each index is decimal number from 0 to 9
    std::array<Sprite*, 10> spritesNum;
    // when user destroys 3 blocks in a row, he gets x3 bonus
    std::array<Sprite*, 10> spritesNumBonus;

    int score = 0;
    int blocksDestroyedROW;

public:
    ScoreTab(int x, int y, int width, int height, int windowWidth, int windowHeight);
    ~ScoreTab();

    void setBlocksDestroyedROW(int blocksDestroyedROW);
    void addBlocksDestroyedROW(int value);

    void setScore(int score);
    void addScore(int score);

    void render() override;
};


#endif //ARKANOID_SCORETAB_H
