//
// Created by Pirmin on 01.05.2022.
//

#ifndef INC_6_AUFGABE_GAME_H
#define INC_6_AUFGABE_GAME_H

#include "hero.h"
#include "fighter.h"
#include "sorcerer.h"


class Game {

private:

    std::map<std::string,std::shared_ptr<Character>> chars;

public:

    static int play(std::shared_ptr<Character> hero, std::shared_ptr<Character> enemy);
};

#endif //INC_6_AUFGABE_GAME_H
