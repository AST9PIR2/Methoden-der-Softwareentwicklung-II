//
// Created by Pirmin on 25.02.2022.
//
#include <cstdlib>
#include <iostream>
#include "hero.h"
#include "character.h"
#include "item.h"
#include <ctime>

//create Hero and make sure his inventory is initialized
void Hero::initHero(const std::string &name, int health, int gold) {
    this->name = name;
    this->health = health;
    this->gold = gold;

    for (int i = 0; i <10; i++) {
        this->inventarItem[i].initItem();
    }

    for (int i = 0; i <2; i++) {
        this->inventarGear[i].initItem();
    }
}

void Hero::attack(Character *enemy) {

    int damage = 0;
    damage =  (std::rand() % 10)+15 ;
    enemy->setCharacterHealth(enemy->getCharacterHealth() - damage);
    std::cout << this->name << " trifft " << enemy->getCharacterName() << " für " << damage << " Lebenspunkte" << std::endl;
}

void Hero::sellItem(int index) {

    if (this->inventarItem[index].getItemIsValid()) {
        std::string temp = this->inventarItem[index].getItemName();
        this->setHeroGold(this->getHeroGold() + this->inventarItem[index].getItemGold());
        this->removeInventarItem(index);
        std::cout << "Gegenstand " << temp << " wurde verkauft. " << this->name << " besitzt nun " << this->gold << " Gold." << std::endl;
    }


}

std::string Hero::getHeroName() const {
    return name;
}

int Hero::getHeroHealth() const {
    return health;
}

int Hero::getHeroGold() const {
    return gold;
}

void Hero::setHeroHealth(int health) {
    if(health > 0){
        this->health = health;
    }
}

void Hero::setHeroGold(int gold) {
    if(gold >= 0) {
        this->gold = gold;
    }
}

int Hero::addInventarItem(const Inventar &item) {
    for (int i = 0; i < 10; i++){
        if(!this->inventarItem[i].getItemIsValid()){
            inventarItem[i] = item;
            std::cout << "Gegenstand " << this->inventarItem[i].getItemName() << " wurde zum Inventar, auf Platz " << i << ", der Heldin hinzugefügt." << std::endl;
            return i;
        }
    }
    std::cout << "Der Item Rucksack ist voll! es können keine weiteren Gegenstände aufgenommen werden." << std::endl;
    return -1;
}

int Hero::addEquipmentItem(const Inventar &gear) {
    for (int i = 0; i< 2; i++){
        if(!this->inventarGear[i].getItemIsValid()){
            inventarGear[i] = gear;
            std::cout << "Gegenstand " << this->inventarGear[i].getItemName() << " wurde zum Inventar, auf Platz " << i << ", der Heldin hinzugefügt." << std::endl;
            return i;
        }
    }
    std::cout << "Der Gear Rucksack ist voll! es können keine weiteren Gegenstände aufgenommen werden." << std::endl;
    return -1;
}

Inventar Hero::removeInventarItem(int slot) {
    if(slot >= 0 && slot <10){
        auto temp = inventarItem[slot];
        this->inventarItem[slot].initItem();
        return temp ;
    }
    return {};
}

Inventar Hero::getInventory(int index) {
    if (index >= 0 && index < 10 && this->inventarItem[index].getItemIsValid()) {
        auto temp = inventarItem[index];
        return inventarItem[index];
    }
    return {};
}


Inventar Hero::removeEquipmentItem(int slot) {
    auto temp = inventarItem[slot];
    if (this->inventarItem[slot].getItemIsValid()) {
        this->inventarItem[slot].initItem();
        return temp ;
    }
    return inventarItem[slot];
}

