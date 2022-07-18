//
// Created by Pirmin on 27.03.2022.
//

#ifndef INC_4_AUFGABE_SORCERER_H
#define INC_4_AUFGABE_SORCERER_H

#include <iostream>
#include "character.h"
#include "npc.h"
#include <map>

class Sorcerer : public NPC{

private:

    int MagicPower = rand(10,20);

public:
    Sorcerer(std::string name) : NPC(name){
        std::cout << "Der Böse Zauberer " << this->getCharacterName() << " ist erschienen und verbreitet Angst und schrecken!" << std::endl;
    };

    void attack(std::shared_ptr<Character> enemy);

};

#endif //INC_4_AUFGABE_SORCERER_H
