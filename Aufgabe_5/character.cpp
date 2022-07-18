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
    try{
        if(Gold >= 0) {
            this->Gold = Gold;
        }else{
            throw std::runtime_error ("Negative Gold value is not supported!");
        }
    }catch(std::exception &e){
        std::cerr << "Runtime error!!! " << e.what()<< std::endl;
    }
}

void Character::sellItem(int index) {

    if (inventarItem[index]) {
        std::string temp = inventarItem[index]->getItemName();
        setCharacterGold(getCharacterGold() + inventarItem[index]->getItemGold());
        std::cout << "Gegenstand " << temp << " wurde verkauft. " << getCharacterName() << " besitzt nun " << getCharacterGold() << " Gold." << std::endl;
        delete inventarItem[index];
    }
}

int Character::addInventarItem(Inventar *item) {
    try{
        for (int i = 0; i < 10; i++){
            if(!inventarItem[i]){
                inventarItem[i] = item;
                return i;
            }
        }throw std::runtime_error("Rucksack ist voll! es können keine weiteren Gegenstände aufgenommen werden.");
    }catch (std::exception &e){
        std::cerr << "Runtime error!!! " << e.what()<< std::endl;
    }
    return 0;
}

Inventar* Character::retrieveRandomLoot() {
    long i;
    while (true) {
        i = std::rand() % 10;
        if (inventarItem[i]) {
            return inventarItem[i];
        }
    }
}

int Character::rand(int x, int y) {
    return (std::rand() % (y - x))+ x;
}



