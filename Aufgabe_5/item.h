//
// Created by Pirmin on 25.02.2022.
//

#ifndef METHODEN_DER_SOFTWAREENTWICKLUNG_II_ITEM_H
#define METHODEN_DER_SOFTWAREENTWICKLUNG_II_ITEM_H

#include <string>
#include <iostream>
#include <memory>

class Inventar {

private:
    std::string name;
    int gold = 0;
    std::string name_array[10] = {"Schwert", "Trank", "Kräuter", "Pilz", "Stein", "Fisch",
                                  "Blume", "Fleisch", "Salz", "Pelz" };

public:
    Inventar(){
        name = name_array[std::rand() % 10];
        gold = (std::rand() % 300) + 10;
    }

    ~Inventar() {
        std::cout << "Destructor: Item destroyed" << std::endl;
    }

    //Getter

    const std::string &getItemName();

    int getItemGold() const;

};


#endif //METHODEN_DER_SOFTWAREENTWICKLUNG_II_ITEM_H
