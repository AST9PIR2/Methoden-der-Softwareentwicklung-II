//
// Created by Pirmin on 25.02.2022.
//

#ifndef METHODEN_DER_SOFTWAREENTWICKLUNG_II_HERO_H
#define METHODEN_DER_SOFTWAREENTWICKLUNG_II_HERO_H

#include <string>
#include "item.h"
#include "character.h"


class Hero {

private:

    std::string name;

    int health = 100;
    int gold = 0;
    Inventar inventarItem[10];
    Inventar inventarGear[2];

public:

    void initHero(const std::string& name, int health, int gold);

    void attack(Character* enemy);

    void sellItem(int index);

    int addInventarItem(const Inventar& item);

    int addEquipmentItem(const Inventar& gear);

    Inventar removeInventarItem(int slot);

    Inventar getInventory(int index);

    Inventar removeEquipmentItem(int slot);

    //Getter & Setter

    std::string getHeroName() const;

    int getHeroHealth() const;

    int getHeroGold() const;

    void setHeroHealth(int health);

    void setHeroGold(int gold);
};


#endif //METHODEN_DER_SOFTWAREENTWICKLUNG_II_HERO_H
