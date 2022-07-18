//
// Created by Pirmin on 25.02.2022.
//

#ifndef METHODEN_DER_SOFTWAREENTWICKLUNG_II_ITEM_H
#define METHODEN_DER_SOFTWAREENTWICKLUNG_II_ITEM_H

#include <string>

class Inventar {

private:
    std::string name;
    int gold = 0;
    bool isValid;

public:
    void initItem(const std::string& name, int gold);
    void initItem();
    void initRandomItem();

    const std::string &getItemName();

    //Getter & Setter

    int getItemGold() const;

    int getItemIsValid() const;

};

#endif //METHODEN_DER_SOFTWAREENTWICKLUNG_II_ITEM_H
