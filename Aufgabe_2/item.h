//
// Created by Pirmin on 25.02.2022.
//

#ifndef METHODEN_DER_SOFTWAREENTWICKLUNG_II_ITEM_H
#define METHODEN_DER_SOFTWAREENTWICKLUNG_II_ITEM_H

#include <string>

struct Item_t {
    std::string name;
    int gold = 0;
    bool isValid;
};

void initItem(Item_t* ITEM, char* name, int gold);
void initItem(Item_t* gegenstand);

#endif //METHODEN_DER_SOFTWAREENTWICKLUNG_II_ITEM_H
