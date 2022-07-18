//
// Created by Pirmin on 26.03.2022.
//

#include <algorithm>
#include "character.h"

void Character::attack(const std::shared_ptr<Character> ptr) {

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

void Character::sellItem() {
    std::for_each(inventarItem.begin(), inventarItem.end(), [this](const std::shared_ptr<Inventar> n) {
        setCharacterGold(getCharacterGold() + n->getItemGold());
        std::cout << "Gegenstand " << n->getItemName() << " wurde für " << n->getItemGold() << " verkauft. " << getCharacterName() << " besitzt nun " << getCharacterGold() << " Gold." << std::endl;
    });
   inventarItem.erase(inventarItem.begin(),inventarItem.end());
}

int Character::addInventarItem(std::shared_ptr<Inventar> item) {
    try{
        std::shared_ptr<Inventar> temp;
        temp.swap(item);
        item.reset();
        inventarItem.push_back(temp);
        //throw std::runtime_error("Rucksack ist voll! es können keine weiteren Gegenstände aufgenommen werden.");
    }catch (std::exception &e){
        std::cerr << "Runtime error!!! " << e.what()<< std::endl;
    }
    return 0;
}

std::shared_ptr<Inventar> Character::retrieveRandomLoot() {
    return inventarItem.at(std::rand() % inventarItem.size());
}

int Character::rand(int x, int y) {
    return (std::rand() % (y - x))+ x;
}



