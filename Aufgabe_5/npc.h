//
// Created by Pirmin on 27.03.2022.
//

#ifndef INC_4_AUFGABE_NPC_H
#define INC_4_AUFGABE_NPC_H

#include <memory>
#include "character.h"
#include "item.h"


class NPC : public Character {

public:

    //Constructor NPC with random amount of items
    NPC(std::string name) : Character(name, rand(100, 150), rand(200, 400), rand(5, 10), rand(5, 10)) {
        //Initialization of random amount of items
        srand((unsigned) time(0));
        int a = (std::rand() % 9) + 1;

        for (int i = 0; i < a; i++) {
            /*std::shared_ptr<Character> ptr (new NPC("test"));
            ptr->*/
            inventarItem[i] = new Inventar;
        }
    }

    //Destructor
    ~NPC() {
       std::cout << "Destructor: Ein Übeltäter weniger" << std::endl;
    }
};
#endif //INC_4_AUFGABE_NPC_H
