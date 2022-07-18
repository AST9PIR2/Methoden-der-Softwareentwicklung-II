//
// Created by Pirmin on 25.02.2022.
//

#include "item.h"

void initItem(Item_t *ITEM, char *name, int gold) {
    ITEM->name = name;
    ITEM->gold = gold;
    ITEM->isValid = true;
}

void initItem(Item_t *gegenstand) {
    gegenstand->isValid = false;

}

