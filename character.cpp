//
// Created by Pirmin on 25.02.2022.
//
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "character.h"
#include "hero.h"

void initCharacter(Character_t *character, char *name, int health, int gold) {
    character->name = name;
    character->health = health;
    character->gold = gold;

    for (int i = 0; i <10; i++) {
        initItem(&character->index[i]);
    }
}

void attack(Character_t *character, Hero_t *hero) {

    int damage = 0;

    damage =  (std::rand() % 10)+5 ;
    hero->health =hero->health - damage;

    std::cout << character->name << " trifft " << hero->name << " für " << damage << " Lebenspunkte" << std::endl;

}
