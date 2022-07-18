//
// Created by Pirmin on 01.05.2022.
//

#include <thread>
#include <chrono>
#include <map>
#include "game.h"
#include "fighter.h"


int Game::play(std::shared_ptr<Character> hero, std::shared_ptr<Character> enemy) {


    while (1) {
        hero->attack(enemy);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        enemy->attack(hero);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (enemy->getCharacterHealth() <= 0) {
            std::cout << enemy->getCharacterName() << " fiel in Ohnmacht! " << hero->getCharacterName()
                      << " hat noch " << hero->getCharacterHealth() << " Lebenspunkte uebrig!" << std::endl;
            hero->addInventarItem(enemy->retrieveRandomLoot());
            std::this_thread::sleep_for(std::chrono::seconds(2));
            hero->addInventarItem(enemy->retrieveRandomLoot());
            return 1;
        } else if (hero->getCharacterHealth() <= 0) {
            std::cout << hero->getCharacterName() << " fiel in Ohnmacht! \n\nGAME OVER!" << std::endl;
            return 0;
        }
    }
}


