//
// Created by Павло Коваль on 11.11.2022.
//

#ifndef ARKANOID_BLOCK_H
#define ARKANOID_BLOCK_H

#include "IObject.h"


enum class BlockColor
{
    BLUE,
    GREEN,
    PURPLE,
    RED,
    ORANGE,
    YELLOW,
};


class Block: public IObject
{
private:
    BlockColor blockColor;
    int health;
    int score;

public:
    Block(int x, int y, int width, int height, int windowWidth, int windowHeight, int health, int score, BlockColor color);
    ~Block();

    void render() override;
};

#endif //ARKANOID_BLOCK_H
