//
// Created by Павло Коваль on 11.11.2022.
//

#include "ScoreTab.h"

ScoreTab::ScoreTab(int x, int y, int width, int height, int windowWidth, int windowHeight) : IObject(x, y, width, height, windowWidth, windowHeight)
{
    sprite = createSprite("data/score-black.png");
    setSpriteSize(sprite, 100, 75);

    score = 0;
    blocksDestroyedROW = 0;

    for (int i = 0; i < 10; i++)
    {
        spritesNum[i] = createSprite(std::string("data/num_" + std::to_string(i) + ".png").c_str());
        setSpriteSize(spritesNum[i], 40, 40);
    }

    for (int i = 0; i < 10; i++)
    {
        spritesNumBonus[i] = createSprite(std::string("data/numS_" + std::to_string(i) + ".png").c_str());
        setSpriteSize(spritesNumBonus[i], 40, 40);
    }

}


ScoreTab::~ScoreTab()
{

}


void ScoreTab::render()
{
    std::vector<int> nums;
    int scoreCopy = score;
    int num = 0;

    // Divide score to digits
    for (int i = 0; i < 4; i++)
    {
        num = scoreCopy % 10;
        scoreCopy /= 10;
        nums.push_back(num);
    }

    // display score (in reverse order)
    int space = 170;
    std::reverse(nums.begin(), nums.end());
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (blocksDestroyedROW >= 3)
        {
            drawSprite(spritesNumBonus[nums[i]], 600 + space, y);
        }
        else
        {
            drawSprite(spritesNum[nums[i]], 600 + space, y);
        }
        space -= 40;
    }
}


void ScoreTab::setScore(int score)
{
    this->score = score;
}


void ScoreTab::addScore(int score)
{
    if (blocksDestroyedROW > 3)
    {
        this->score += score * 3;
    }
    else
    {
        this->score += score;
    }
}


void ScoreTab::setBlocksDestroyedROW(int blocksDestroyedROW)
{
    this->blocksDestroyedROW = blocksDestroyedROW;
}


void ScoreTab::addBlocksDestroyedROW(int value)
{
    this->blocksDestroyedROW += value;
}
