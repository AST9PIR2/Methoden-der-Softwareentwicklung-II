//
// Created by Pirmin on 20.05.2022.
//

#include <vector>
#include <thread>
#include <iostream>
#include "exceptions.h"
#include <algorithm>

#include "product.h"
#include "machine.h"
#include "factory.h"

int main() {
    /*
    {
        auto productA = new ProductA;
        auto productB = new ProductB;
        productA->getType();
        productB->getType();
        std::cout << "Produkt A: " << productA->getType() << std::endl;
        std::cout << "Produkt A: " << productB->getType() << std::endl;
    }*/
    /*
    {

        auto machine_test = new MachineA();
        for(int i = 0; i <20;i++)
        {
            machine_test->tick();
        }

    }*/

    {
        auto factory = new Factory;
        factory->run(1000);
        delete factory;

    }

    return 0;
}
