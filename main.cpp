#include <iostream>
#include "hero.h"
#include "character.h"
#include "item.h"

bool fight(Hero_t *hero, Character_t *enemy) {

    while (1) {
        attack(hero, enemy);
        attack(enemy, hero);
        //std::cout << "hero = " << hero->health << ", enemy = " << enemy->health << std::endl;
        if (enemy->health <= 0) {
            return true;
        } else if (hero->health <= 0) {
            return false;
        }

    }
}

int main() {

    Hero_t hero;
    Character_t first_enemy;
    Character_t second_enemy;

    initHero(&hero, (char*) "Annina", 300, 0);
    initCharacter(&first_enemy, (char*) "Matthias", 50, 0);
    initCharacter(&second_enemy, (char*) "Pascal", 100, 0);

    if (fight(&hero, &first_enemy) == true) {
        std::cout << first_enemy.name << " fiel in Ohnmacht! " << hero.name << " hat noch " << hero.health << " Lebenspunkte uebrig!" << std::endl;
    }else {
        std::cout << hero.name << " fiel in Ohnmacht! \n\nGAME OVER!" << std::endl;
        return 0;
    }

    initItem(&hero.index[0], (char*) "Zaubertrank", 250);
    std::cout << "Gegenstand " << hero.index[0].name << " wurde zum Inventar der Heldin hinzugefügt." << std::endl;

    if (fight(&hero, &second_enemy) == true) {
        std::cout << second_enemy.name << " fiel in Ohnmacht! " << hero.name << " hat noch " << hero.health << " Lebenspunkte uebrig!" << std::endl;
    }else {
        std::cout << hero.name << " fiel in Ohnmacht! \n\nGAME OVER!" << std::endl;
        return 0;
    }

    initItem(&hero.index[1], (char*) "Schwert", 280);
    std::cout << "Gegenstand " << hero.index[1].name << " wurde zum Inventar der Heldin hinzugefügt." << std::endl;

    for ( int i = 0; i < 10; i++) {
        sellItem(&hero,i);
    }



    return 0;
}
