//
// Created by Pirmin on 27.03.2022.
//

#ifndef INC_4_AUFGABE_NPC_H
#define INC_4_AUFGABE_NPC_H

#include <memory>
#include "character.h"
#include "item.h"
#include "hero.h"


class NPC : public Character {

public:
    virtual void attack(std::shared_ptr<Character> hero) {

    }

    //Constructor NPC with random amount of items
    NPC(std::string name) : Character(name, rand(10, 15), rand(200, 400), rand(5, 10), rand(5, 10)) {
        //Initialization of random amount of items
        srand((unsigned) time(0));

       for (int i = 0; i < std::rand() % MAX_SLOT_SIZE + 3; i++) {
            inventarItem.push_back( std::shared_ptr<Inventar>(new Inventar));
        }
    }

    //Destructor
    ~NPC() {
       std::cout << "Destructor: Ein Übeltäter weniger" << std::endl;
    }
};
#endif //INC_4_AUFGABE_NPC_H
