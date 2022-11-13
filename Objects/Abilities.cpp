//
// Created by Павло Коваль on 12.11.2022.
//

#include "Abilities.h"

Abilities::Abilities(int x, int y, int width, int height, int windowWidth, int windowHeight, AbilitiesType type)
: IObject(x, y, width, height, windowWidth, windowHeight), type(type)
{
    switch(type)
    {
        case AbilitiesType::PLUS_50_SCORES:
            this->sprite = createSprite("data/31-Breakout-Tiles.png");
            break;
        case AbilitiesType::PLUS_100_SCORES:
            this->sprite = createSprite("data/38-Breakout-Tiles.png");
            break;
        case AbilitiesType::PLUS_250_SCORES:
            this->sprite = createSprite("data/39-Breakout-Tiles.png");
            break;
        case AbilitiesType::PLUS_500_SCORES:
            this->sprite = createSprite("data/40-Breakout-Tiles.png");
            break;
        case AbilitiesType::SLOW_PLATFORM:
            this->sprite = createSprite("data/41-Breakout-Tiles.png");
            break;
        case AbilitiesType::FAST_PLATFORM:
            this->sprite = createSprite("data/42-Breakout-Tiles.png");
            break;
    }

    setSpriteSize(sprite, width, height);
    speed = 0.3;
}


void Abilities::render(unsigned int timeDelta)
{
    if (!isVisible)
        return;

    y = y + speed;
    drawSprite(sprite, x, y);
}


AbilitiesType Abilities::getType() const
{
    return type;
}


Abilities::~Abilities()
{

}
