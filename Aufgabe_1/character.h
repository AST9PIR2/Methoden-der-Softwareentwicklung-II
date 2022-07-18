//
// Created by Pirmin on 25.02.2022.
//

#ifndef METHODEN_DER_SOFTWAREENTWICKLUNG_II_CHARACTER_H
#define METHODEN_DER_SOFTWAREENTWICKLUNG_II_CHARACTER_H

#include <string>
#include "item.h"

struct Hero_t;


struct Character_t{
    std::string name;
    int health = 100;
    int gold = 0;
    Item_t index[10];
};

void initCharacter(Character_t* character, char* name, int health, int gold);

void attack(Character_t* character, Hero_t* hero);

#endif //METHODEN_DER_SOFTWAREENTWICKLUNG_II_CHARACTER_H
