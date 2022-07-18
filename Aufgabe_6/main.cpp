//
// Created by Pirmin on 27.03.2022.
//

#include <iostream>
#include "hero.h"
#include "sorcerer.h"
#include "fighter.h"
#include <exception>

#include <memory>
#include <thread>
#include <map>
#include "game.h"

int main() {
    srand((unsigned)time(0));

    static std::map<std::string,std::shared_ptr<Character>> chars;

    chars.insert({"Annina", std::shared_ptr<Hero> (new Hero("Annina"))});
    chars.insert({"Haudrauf", std::shared_ptr<NPC> (new Fighter("Haudrauf"))});
    //chars.insert( {"Fidibus",  std::shared_ptr<NPC> (new Sorcerer("Fidibus"))});

    if(!Game::play(std::shared_ptr<Character>(chars["Annina"]), std::shared_ptr<Character>(chars["Haudrauf"]))){
        return 0;
    }
    chars.erase("Haudrauf");

    chars.insert( {"Fidibus",  std::shared_ptr<NPC> (new Sorcerer("Fidibus"))});

    if(!Game::play(std::shared_ptr<Character>(chars["Annina"]), std::shared_ptr<Character>(chars["Fidibus"]))){
        return 0;
    }
    chars.erase("Fidibus");

    std::shared_ptr<Character> (chars["Annina"])->sellItem();

    std::cout << "Es wurden alle Gegner besiegt! Du hast gewonnen!" << std::endl;

    return 0;
}
