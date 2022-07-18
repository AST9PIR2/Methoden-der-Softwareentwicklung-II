//
// Created by Pirmin on 27.03.2022.
//

#include "hero.h"


void Hero::attack(Character *enemy) {
    int damage;
    damage = rand(15, 25) - enemy->getCharacterArmor();
    enemy->setCharacterHealth(enemy->getCharacterHealth() - damage);

    std::cout << *this << " trifft " << *enemy << " für " << damage << " Lebenspunkte" << std::endl;
}
