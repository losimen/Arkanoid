//
// Created by Павло Коваль on 11.11.2022.
//

#include "Block.h"


Block::Block(int x, int y, int width, int height, int windowWidth, int windowHeight, int health, int score, BlockColor color): IObject(x, y, width, height, windowWidth, windowHeight)
{
    this->health = health;
    this->score = score;

    switch (color)
    {
        case BlockColor::BLUE:
            sprite = createSprite("data/01-Breakout-Tiles.png");
            break;
        case BlockColor::GREEN:
            sprite = createSprite("data/03-Breakout-Tiles.png");
            break;
        case BlockColor::PURPLE:
            sprite = createSprite("data/05-Breakout-Tiles.png");
            break;
        case BlockColor::RED:
            sprite = createSprite("data/07-Breakout-Tiles.png");
            break;
        case BlockColor::ORANGE:
            sprite = createSprite("data/09-Breakout-Tiles.png");
            break;
        case BlockColor::YELLOW:
            sprite = createSprite("data/13-Breakout-Tiles.png");
            break;

    }

    setSpriteSize(sprite, width, height);
}

Block::~Block()
{

}

void Block::render()
{
    drawSprite(sprite, x, y);
}
