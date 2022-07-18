//
// Created by Pirmin on 27.03.2022.
//


#include <iostream>
#include "character.h"
#include "hero.h"
#include "sorcerer.h"
#include "fighter.h"

int main() {
    srand((unsigned)time(0));
    Hero Held("Coco");
    {
        Sorcerer ErsterGegner("Fidibus");
        //Hero Held("Coco");
        std::cout << Held << std::endl;

        while (true) {
            Held.attack(&ErsterGegner);
            ErsterGegner.attack(&Held);
            if (ErsterGegner.getCharacterHealth() <= 0) {
                std::cout << ErsterGegner.getCharacterName() << " fiel in Ohnmacht! " << Held.getCharacterName()
                          << " hat noch " << Held.getCharacterHealth() << " Lebenspunkte uebrig!" << std::endl;
                Held.addInventarItem( ErsterGegner.retrieveRandomLoot());
                break;
            } else if (Held.getCharacterHealth() <= 0) {
                std::cout << Held.getCharacterName() << " fiel in Ohnmacht! \n\nGAME OVER!" << std::endl;
                return 0;
            }

        }
    }

    {
        Fighter ZweiterGegner("Haudrauf");

        while (true) {
            Held.attack(&ZweiterGegner);
            ZweiterGegner.attack(&Held);
            if (ZweiterGegner.getCharacterHealth() <= 0) {
                std::cout << ZweiterGegner.getCharacterName() << " fiel in Ohnmacht! " << Held.getCharacterName()
                          << " hat noch " << Held.getCharacterHealth() << " Lebenspunkte uebrig!" << std::endl;
                Held.addInventarItem(ZweiterGegner.retrieveRandomLoot());
                break;
            } else if (Held.getCharacterHealth() <= 0) {
                std::cout << Held.getCharacterName() << " fiel in Ohnmacht! \n\nGAME OVER!" << std::endl;
                return 0;
            }

        }
    }

    for ( int i = 0; i < 10; i++) {
        Held.sellItem(i);
    }

    return 0;
}
