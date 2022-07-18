//
// Created by Pirmin on 26.03.2022.
//

#include "character.h"


void Character::attack(Character *enemy) {

}

std::string Character::getCharacterName() const {
    return std::string(Name);
}

int Character::getCharacterHealth() const {
    return Health;
}

int Character::getCharacterGold() const {
    return Gold;
}

int Character::getCharacterArmor() const {
    return Armor;
}

int Character::getCharacterMagicResistance() const {
    return MagicResistance;
}

void Character::setCharacterHealth(int Health) {
    if((this->Health - Health) > 0){
        this->Health= Health;
    }
}

void Character::setCharacterGold(int Gold) {
    if(Gold >= 0) {
        this->Gold = Gold;
    }
}

void Character::sellItem(int index) {

    if (this->inventarItem[index].getItemIsValid()) {
        std::string temp = this->inventarItem[index].getItemName();
        this->setCharacterGold(this->getCharacterGold() + this->inventarItem[index].getItemGold());
        this->removeInventarItem(index);
        std::cout << "Gegenstand " << temp << " wurde verkauft. " << this->getCharacterName() << " besitzt nun " << this->getCharacterGold() << " Gold." << std::endl;
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

Inventar Character::removeInventarItem(int slot) {
    auto temp = inventarItem[slot];
    if (this->inventarItem[slot].getItemIsValid()) {
        this->inventarItem[slot].initItem();
        return temp ;
    }
    return inventarItem[slot];
}

Inventar Character::retrieveRandomLoot() {
    long i;
    while (true) {
        i = std::rand() % 10;
        if (this->inventarItem[i].getItemIsValid()) {
            return this->inventarItem[i];
        }
    }
}

int Character::rand(int x, int y) {
    return (std::rand() % (y - x))+ x;
}

