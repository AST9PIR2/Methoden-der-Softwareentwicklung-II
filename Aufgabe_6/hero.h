//
// Created by Pirmin on 27.03.2022.
//

#ifndef INC_4_AUFGABE_HERO_H
#define INC_4_AUFGABE_HERO_H


#include <iostream>
#include "character.h"
#include "item.h"
#include "npc.h"
#include <map>


class Hero : public Character{

private:

    //[[maybe_unused]] Inventar inventarGear[2]{};

public:
    //Constructor Hero
    Hero(std::string name) : Character(name,rand(200,300),0,rand(10,15),rand(10,15)){
    std::cout << "Der Held " << this->getCharacterName() << " taucht auf um die Welt zu retten." << std::endl;
    };

    void attack(const std::shared_ptr<Character> enemy);

    //Destructor
    ~Hero() {
        std::cout << "Destructor: Heldin Annina verabschiedet sich und reitet in den Sonnenuntergang" << std::endl;
    }

};

#endif //INC_4_AUFGABE_HERO_H
