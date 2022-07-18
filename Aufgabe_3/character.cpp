//
// Created by Pirmin on 25.02.2022.
//
#include <cstdlib>
#include <iostream>
#include "character.h"
#include "hero.h"
#include <ctime>

void Character::initCharacter(const std::string &name, int health, int gold) {
    this->name = name;
    this->health = health;
    this->gold = gold;

    Inventar test;

    for (int i = 0; i <10; i++) {
        this->inventarItem[i].initItem();
    }

    srand((unsigned)time(0));
    int a = (std::rand() % 9)+1;

    for (int i = 0; i < a; i++){
        this->inventarItem[i].initRandomItem();
    }
}

void Character::attack(Hero *hero) {

    int damage = 0;
    damage =  (std::rand() % 10)+5 ;
    hero->setHeroHealth(hero->getHeroHealth() - damage);
    std::cout << hero->getHeroHealth() << std::endl;
    std::cout << damage << std::endl;

    std::cout << this->getCharacterName() << " trifft " << hero->getHeroName() << " für " << damage << " Lebenspunkte" << std::endl;

}

std::string Character::getCharacterName() const {
    return name;
}

int Character::getCharacterHealth() const {
    return health;
}

void Character::setCharacterHealth(int health) {
    if((this->health - health) > 0){
        this->health= health;
    }
}

int Character::addInventarItem(const Inventar &item) {
    for (int i = 0; i < 10; i++){
        if(!this->inventarItem[i].getItemIsValid()){
            inventarItem[i] = item;
            return i;
        }
    }
    std::cout << "Rucksack ist voll! es können keine weiteren Gegenstände aufgenommen werden." << std::endl;
    return -1;
}

Inventar Character::getItemToLose() {
    long i = 0;
    while (1) {
        i = std::rand() % 10;
        if (this->inventarItem[i].getItemIsValid()) {
            return this->inventarItem[i];
        }
    }
}

Inventar Character::removeInventarItem(int slot) {
    auto temp = inventarItem[slot];
    if (this->inventarItem[slot].getItemIsValid()) {
        this->inventarItem[slot].initItem();
        return temp ;
    }
    return inventarItem[slot];
}
