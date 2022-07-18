//
// Created by Pirmin on 27.03.2022.
//

#include "sorcerer.h"

void Sorcerer::attack(std::shared_ptr<Character> enemy) {
    int damage;
    damage = rand(5, 10) + MagicPower - enemy->getCharacterMagicResistance();
    enemy->setCharacterHealth(enemy->getCharacterHealth() - damage);
    std::cout << *this << " trifft " << *enemy << " für " << damage << " Lebenspunkte" << std::endl;
}



