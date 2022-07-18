//
// Created by Pirmin on 27.03.2022.
//

#ifndef INC_4_AUFGABE_FIGHTER_H
#define INC_4_AUFGABE_FIGHTER_H

#include <iostream>
#include "character.h"
#include "npc.h"

class Fighter : public NPC{

private:

    int Strength = rand(10,20);


public:
    Fighter(std::string name) : NPC(name){
        std::cout << "Der Unbarmherziger Kämpfer " << this->getCharacterName() << " stürmt auch die freie Welt! Rette sich wer kann!" << std::endl;
    };

    void attack(Character *enemy);

};

#endif //INC_4_AUFGABE_FIGHTER_H
