//
// Created by Pirmin on 26.03.2022.
//

#ifndef INC_4_AUFGABE_CHARACTER_H
#define INC_4_AUFGABE_CHARACTER_H
#define MAX_SLOT_SIZE 10


#include <iostream>
#include <string>
#include "item.h"
#include <typeinfo>
#include <memory>


class Character {

private:

    std::string Name;
    int Health;
    int Gold;
    int Armor;
    int MagicResistance;

public:
    Inventar * inventarItem[MAX_SLOT_SIZE];

    Character(const std::string Name, int Health, int Gold, int Armor, int MagicResistance)
    : Name(Name), Health(Health), Gold(Gold), Armor(Armor), MagicResistance(MagicResistance) {
        for(int i = 0; i < MAX_SLOT_SIZE; i++) {
            this->inventarItem[i] = nullptr;
        }
    }

    virtual void attack(Character *enemy);

    int rand(int x, int y);


    //Getter

    std::string getCharacterName() const;

    int getCharacterHealth() const;

    int getCharacterGold() const;

    int getCharacterArmor() const;

    int getCharacterMagicResistance() const;

    //Setter

    void setCharacterHealth(int Health);

    void setCharacterGold(int Gold);


    //Item Handler

    void sellItem(int index);

    Inventar * retrieveRandomLoot();

    int addInventarItem(Inventar *item);
};

inline std::ostream& operator<<(std::ostream& out, const Character& c) {
    out <<  c.getCharacterName() << " [Health: " << c.getCharacterHealth() << "][Armor: " << c.getCharacterArmor() << "][Magic Resistance: " << c.getCharacterMagicResistance() << "]";
    return out;
}

#endif //INC_4_AUFGABE_CHARACTER_H
