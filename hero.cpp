//
// Created by Pirmin on 25.02.2022.
//
#include <cstdlib>
#include <iostream>
#include "hero.h"
#include "character.h"

void initHero(Hero_t *hero, char *name, int health, int gold) {
    hero->name = name;
    hero->health = health;
    hero->gold = gold;

    for (int i = 0; i <10; i++) {
        initItem(&hero->index[i]);
    }
}

void attack(Hero_t *hero, Character_t *enemy) {

    int damage = 0;

    damage =  (std::rand() % 10)+15 ;
    enemy->health = enemy->health - damage;

    std::cout << hero->name << " trifft " << enemy->name << " für " << damage << " Lebenspunkte" << std::endl;
}

void sellItem(Hero_t *hero, int index) {

    if (hero->index[index].isValid) {
        hero->gold = hero->gold + hero->index[index].gold;
        std::cout << "Gegenstand " << hero->index[index].name << " wurde verkauft. "<< hero->name << " besitzt nun " << hero->gold <<" Gold." << std::endl;
    }
}