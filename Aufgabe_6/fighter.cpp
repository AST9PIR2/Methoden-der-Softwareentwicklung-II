//
// Created by Pirmin on 27.03.2022.
//

#include "fighter.h"

void Fighter::attack(std::shared_ptr<Character> enemy) {
    int damage;
    damage = rand(5, 10) + Strength - enemy->getCharacterArmor();
    enemy->setCharacterHealth(enemy->getCharacterHealth() - damage);
    std::cout << *this << " trifft " << *enemy << " für " << damage << " Lebenspunkte" << std::endl;
}
