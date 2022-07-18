//
// Created by Pirmin on 27.03.2022.
//

#ifndef INC_4_AUFGABE_NPC_H
#define INC_4_AUFGABE_NPC_H

#include "character.h"

class NPC : public Character{

public:
    //Constructor NPC with random amount of items
    NPC(std::string name) : Character(name,rand(100,150),rand(200,400),rand(5,10),rand(5,10)){
        //Initialization of NPC backpack
        for (int i = 0; i <10; i++) {
            this->inventarItem[i].initItem();
        }
        //Initialization of random amount of items
        srand((unsigned)time(0));
        int a = (std::rand() % 9)+1;

        for (int i = 0; i < a; i++){
            this->inventarItem[i].initRandomItem();
        }
    };
    //Destructor
    ~NPC() {
        std::cout << "Einer Übeltäter weniger" << std::endl;
    }

};

#endif //INC_4_AUFGABE_NPC_H
