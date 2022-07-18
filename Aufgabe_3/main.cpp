#include <iostream>
#include "hero.h"
#include "character.h"
#include "item.h"

bool fight(Hero *hero, Character *enemy) {

    while (1) {
        hero->attack(enemy);
        enemy->attack(hero);
        if (enemy->getCharacterHealth() <= 0) {
            return true;
        } else if (hero->getHeroHealth() <= 0) {
            return false;
        }

    }
}

int main() {

    Hero hero;
    Character first_enemy;
    Character second_enemy;

    hero.initHero( "Annina", 300, 0);
    first_enemy.initCharacter( "Matthias", 50, 0);
    second_enemy.initCharacter( "Pascal", 100, 0);

    if (fight(&hero, &first_enemy)) {
        std::cout << first_enemy.getCharacterName() << " fiel in Ohnmacht!" << hero.getHeroName() << " hat noch " << hero.getHeroHealth() << " Lebenspunkte uebrig!" << std::endl;
        hero.addInventarItem(first_enemy.getItemToLose());
    }else {
        std::cout << hero.getHeroName() << " fiel in Ohnmacht! \n\nGAME OVER!" << std::endl;
        return 0;
    }

    if (fight(&hero, &second_enemy)) {
        std::cout << second_enemy.getCharacterName() << " fiel in Ohnmacht! " << hero.getHeroName() << " hat noch " << hero.getHeroHealth() << " Lebenspunkte uebrig!" << std::endl;
        hero.addInventarItem(second_enemy.getItemToLose());
    }else {
        std::cout << hero.getHeroName() << " fiel in Ohnmacht! \n\nGAME OVER!" << std::endl;
        return 0;
    }

    for ( int i = 0; i < 10; i++) {
        hero.sellItem(i);
    }

    return 0;
}
