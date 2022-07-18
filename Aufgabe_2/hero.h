//
// Created by Pirmin on 25.02.2022.
//

#ifndef METHODEN_DER_SOFTWAREENTWICKLUNG_II_HERO_H
#define METHODEN_DER_SOFTWAREENTWICKLUNG_II_HERO_H

#include <string>
#include "item.h"
#include "character.h"


struct Hero_t {
    std::string name;
    int health = 100;
    int gold = 0;
    Item_t index[10];
    struct {
        std::string gear;
    } gear_index[2];
};


void initHero(Hero_t* hero, char* name, int health, int gold);

void attack(Hero_t* hero, Character_t* enemy);

void sellItem(Hero_t* hero, int index);

#endif //METHODEN_DER_SOFTWAREENTWICKLUNG_II_HERO_H
