//
// Created by Pirmin on 26.03.2022.
//

#ifndef INC_4_AUFGABE_CHARACTER_H
#define INC_4_AUFGABE_CHARACTER_H
#define MAX_SLOT_SIZE 30


#include <iostream>
#include <string>
#include "item.h"
#include <typeinfo>
#include <memory>
#include <vector>

class Character{

private:

    std::string Name;
    int Health;
    int Gold;
    int Armor;
    int MagicResistance;


public:

    std::vector<std::shared_ptr<Inventar>> inventarItem;

    Character(const std::string Name, int Health, int Gold, int Armor, int MagicResistance)
    : Name(Name), Health(Health), Gold(Gold), Armor(Armor), MagicResistance(MagicResistance) {

    }

    virtual void attack(std::shared_ptr<Character> ptr);

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

    void sellItem();

    std::shared_ptr<Inventar> retrieveRandomLoot();

    int addInventarItem(std::shared_ptr<Inventar> item);

};

inline std::ostream& operator<<(std::ostream& out, const Character& c) {
    out <<  c.getCharacterName() << " [Health: " << c.getCharacterHealth() << "][Armor: " << c.getCharacterArmor() << "][Magic Resistance: " << c.getCharacterMagicResistance() << "]";
    return out;
}


#endif //INC_4_AUFGABE_CHARACTER_H
