//
// Created by Pirmin on 27.03.2022.
//

#include <iostream>
#include "hero.h"
#include "sorcerer.h"
#include "fighter.h"
#include <exception>

int fight(Hero *hero, const std::shared_ptr<NPC>& enemy){
    while(1) {
        hero->attack(enemy);
        enemy->attack(hero);
        if (enemy->getCharacterHealth() <= 0) {
            std::cout << enemy->getCharacterName() << " fiel in Ohnmacht! " << hero->getCharacterName()
                      << " hat noch " << hero->getCharacterHealth() << " Lebenspunkte uebrig!" << std::endl;
            hero->addInventarItem( enemy->retrieveRandomLoot());
            return 1;
        } else if (hero->getCharacterHealth() <= 0) {
            std::cout << hero->getCharacterName() << " fiel in Ohnmacht! \n\nGAME OVER!" << std::endl;
            return 0;
        }

    }
}

int main() {
    srand((unsigned)time(0));
    Hero *hero = new Hero("Annina");
    //hero->setCharacterGold(-200);

    if(!fight(hero, std::shared_ptr<NPC> (new Fighter("Haudrauf")))){
        return 0;
    }

    if(!fight(hero, std::shared_ptr<NPC> (new Sorcerer("Haudrauf")))){
        return 0;
    }

    for (int i = 0; i < MAX_SLOT_SIZE; i++) {
        hero->sellItem(i);
    }

    std::cout << "Es wurden alle Gegner besiegt! Du hast gewonnen!" << std::endl;
    delete hero;

    return 0;
}
