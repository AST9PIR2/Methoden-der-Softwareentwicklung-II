//
// Created by Pirmin on 21.05.2022.
//

#include <random>
#include "exceptions.h"
#include "factory.h"
#include "machine.h"

void Machine::tick() {
    //Seed for rand function
    srand((unsigned) time(nullptr));

    //Checking possible CriticalDanger/InternalError and getting radom trigger
    if (probability(MachineFailureException)) {
        throw ErrorMachineFailureException("MachineFailureException!");
    } else if (probability(MachineExplosionException)){
        throw ErrorMachineExplosionException("MachineExplosionException!");
    }else {}
}
    



//Probability generator. Stollen from: https://stackoverflow.com/questions/58326619/how-can-i-make-something-happen-x-percentage
//Input in % z.B probability(15) for 15%
int Machine::probability(int value) {
    std::random_device rd;
    std::mt19937 gen(rd());
    double interval[] = {0,0,1,1};
    double weights[] = { static_cast<double>(100-value), 0, static_cast<double>(value)};
    std::piecewise_constant_distribution<> dist(std::begin(interval),std::end(interval),weights);
    return dist(gen);
}

void Machine::setFactory(Factory *f) {
    ID = f;
}

const std::string &Machine::getProductType() const {
    return ProductType;
}

int Machine::getPpz() {
    return Ppz;
}





