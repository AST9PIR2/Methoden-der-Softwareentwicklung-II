//
// Created by Pirmin on 25.02.2022.
//

#include "item.h"

void Inventar::initItem(const std::string &name, int gold) {
    this->name = name;
    this->gold = gold;
    this->isValid = true;

}

void Inventar::initRandomItem() {
    std::string name_array[10] = {"Schwert", "Trank", "Kräuter", "Pilz", "Stein", "Fisch", "Blume", "Fleisch", "Salz", "Pelz" };
    int i = std::rand() % 10;
    this->name = name_array[i];
    this->gold = (std::rand() % 300) + 10;
    this->isValid = true;
}

void Inventar::initItem() {
    this->name = "";
    this->gold = 0;
    this->isValid = false;
}

const std::string &Inventar::getItemName() {
    return name;
}

int Inventar::getItemGold() const {
    return gold;
}

int Inventar::getItemIsValid() const{
    return isValid;
}

