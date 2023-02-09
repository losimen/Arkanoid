//
// Created by Павло Коваль on 12.11.2022.
//

#ifndef ARKANOID_ABILITIES_H
#define ARKANOID_ABILITIES_H

#include "IObject.h"


enum class AbilitiesType
{
    PLUS_50_SCORES,
    PLUS_100_SCORES,
    PLUS_250_SCORES,
    PLUS_500_SCORES,
    SLOW_PLATFORM,
    FAST_PLATFORM
};


class Abilities : public IObject
{
private:
    AbilitiesType type;
    double speed;

public:
    Abilities(int x, int y, int width, int height, int windowWidth, int windowHeight, AbilitiesType type);

    void render(unsigned int timeDelta) override;

    AbilitiesType getType() const;

    virtual ~Abilities();
};


#endif //ARKANOID_ABILITIES_H
