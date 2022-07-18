//
// Created by Pirmin on 25.02.2022.
//

#include "item.h"

//Initializing randomly an item from list with random stats
void Inventar::initRandomItem() {
    std::string name_array[10] = {"Schwert", "Trank", "Kräuter", "Pilz", "Stein", "Fisch", "Blume", "Fleisch", "Salz", "Pelz" };
    int i = std::rand() % 10;
    this->name = name_array[i];
    this->gold = (std::rand() % 300) + 10;
    this->isValid = true;
}

//Initializing of Item, to make sure there is no garbage in memory
void Inventar::initItem() {
    this->name = "";
    this->gold = 0;
    this->isValid = false;
}
/*#############
Getter
#############*/

const std::string &Inventar::getItemName() {
    return name;
}

int Inventar::getItemGold() const {
    return gold;
}

int Inventar::getItemIsValid() const{
    return isValid;
}

