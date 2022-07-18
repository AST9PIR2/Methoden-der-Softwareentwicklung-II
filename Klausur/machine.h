//
// Created by Pirmin on 21.05.2022.
//

#ifndef KLAUSUR_MACHINE_H
#define KLAUSUR_MACHINE_H

#include <map>

class Factory;

class Machine {
private:
    int Ppz;
    int MachineFailureException;
    int MachineExplosionException;
    std::string ProductType;
    Factory * ID;


public:

    Machine(int Ppz, int MachineFailureException, int MachineExplosionException,std::string ProductType ) :
            Ppz(Ppz), MachineFailureException(MachineFailureException),
            MachineExplosionException(MachineExplosionException), ProductType(ProductType) {

    }

    virtual ~Machine() {

    }

    void tick();

    const std::string &getProductType() const;

    int probability(int Ppz);

    int getPpz();

    void setFactory(Factory* f);

};

class MachineA : public Machine {
public:
    MachineA() : Machine(2,15,2,"A") {

    }

    ~MachineA() {

    }

};

class MachineB : public Machine {
public:
    MachineB() : Machine(3,20,3,"B") {

    }

    ~MachineB() {

    }

};

#endif //KLAUSUR_MACHINE_H
