//
// Created by Pirmin on 21.05.2022.
//

#ifndef KLAUSUR_FACTORY_H
#define KLAUSUR_FACTORY_H

#include <vector>
#include <map>
#include "machine.h"
#include "product.h"


class Factory{
private:
    std::map<int ,Machine*> MachineList;
    std::vector<Product*> ProductStorageA;
    std::vector<Product*> ProductStorageB;

public:

    Factory(){

    }

    ~Factory(){
        ProductStorageA.clear();
        ProductStorageB.clear();
        MachineList.clear();
        std::cout << "Alles storage containers cleared!" << std::endl;
    }

    unsigned addMachine(Machine* m);
    Machine* getMachine(unsigned id);
    void deleteMachine(unsigned id);
    void addProduct(Product* p);
    unsigned getProductACount();
    unsigned getProductBCount();
    void run(unsigned iterations);
};

#endif //KLAUSUR_FACTORY_H
