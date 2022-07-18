//
// Created by Pirmin on 25.02.2022.
//

#ifndef METHODEN_DER_SOFTWAREENTWICKLUNG_II_CHARACTER_H
#define METHODEN_DER_SOFTWAREENTWICKLUNG_II_CHARACTER_H

#include <string>
#include "item.h"

class Hero;


class Character{

private:
    std::string name;
    int health = 100;
    int gold = 0;
    Inventar inventarItem[10];

    public:
    void initCharacter(const std::string& name, int health, int gold);

    void attack(Hero* hero);

    int addInventarItem(const Inventar& item);


    std::string getCharacterName() const;

    int getCharacterHealth() const;

    void setCharacterHealth(int health);

    Inventar getItemToLose();

    Inventar removeInventarItem(int slot);
};


#endif //METHODEN_DER_SOFTWAREENTWICKLUNG_II_CHARACTER_H
