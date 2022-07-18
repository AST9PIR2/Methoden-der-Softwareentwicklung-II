//
// Created by Pirmin on 27.03.2022.
//

#include <iostream>
#include "character.h"
#include "item.h"
#include "npc.h"


#ifndef INC_4_AUFGABE_HERO_H
#define INC_4_AUFGABE_HERO_H

class Hero : public Character{

private:

    Inventar *inventarGear[2];

public:
    //Constructor Hero
    Hero(std::string name) : Character(name,rand(200,300),0,rand(10,15),rand(10,15)){
    std::cout << "Der Held " << this->getCharacterName() << " taucht auf um die Welt zu retten." << std::endl;
        //Initialising 2 Items while initialising Hero
        for (int i = 0; i <2; i++) {
            this->inventarGear[i]= nullptr;
        }
    };

    void attack(std::shared_ptr<NPC> enemy);

    //Destructor
    ~Hero() {
        std::cout << "Destructor: Heldin Annina verabschiedet sich und reitet in den Sonnenuntergang" << std::endl;
    }

};

#endif //INC_4_AUFGABE_HERO_H
