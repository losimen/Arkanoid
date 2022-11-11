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
    int score = 0;

public:
    ScoreTab(int x, int y, int width, int height, int windowWidth, int windowHeight);
    ~ScoreTab();

    void setScore(int score);
    void addScore(int score);

    void render() override;
};


#endif //ARKANOID_SCORETAB_H
