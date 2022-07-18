//
// Created by Pirmin on 21.05.2022.
//

#include <iomanip>
#include <thread>
#include "factory.h"
#include "exceptions.h"

//Adding new machine to factory
unsigned Factory::addMachine(Machine* m) {
    //maxMachines = more than 9998 machines seems unrealistic for such a simple factory
    for(int i = 0; i < 9999; i++) {
        //Check if ID is occupied
        if (!MachineList.count(i)) {
            MachineList.insert({i, m});
            std::cout << "New maschine with output: Product " <<m->getProductType() << ", added to factory" << std::endl;
            return i;
        }
    }
    throw ErrorFactoryException("*** Preventing buffer overflow, max 1000 Sensors aloud! ***");
    return 0;
}

Machine* Factory::getMachine(unsigned id) {
    //Check if requested id exists
    try {
        std::cout << "SEARCH RESULTS FOR: ID_" << std::setfill('0') << std::setw(sizeof(int)) << id << ", Type: " << std::endl;
        return MachineList.at(id);
    } catch (...) {
        //throw RobotException("*** Getting requested Sensor failed! No valid ID! ***");
    }
    return 0;
}

void Factory::deleteMachine(unsigned id) {
    //Check if requested id exists
    try{
        std::cout << "Machine " << MachineList.at(id)->getProductType() << ", destroyed" << std::endl;
        MachineList.erase(id);
    }catch (...){
        throw ErrorFactoryException("*** Destroying requested machine failed! No valid ID! ***");
    }

}

//Adding a new product to the storage
void Factory::addProduct(Product *p) {
    if(p->getType() == 1){
        ProductStorageA.push_back(p);
    }else if ((p->getType() == 2)){
        ProductStorageB.push_back(p);
    }else{
        throw ErrorFactoryException("Could not identify requested product, therefore it can not be sorted");
    }

}

unsigned Factory::getProductACount() {
    return ProductStorageA.size();
}

unsigned Factory::getProductBCount() {
    return ProductStorageB.size();
}

void Factory::run(unsigned int iterations) {

    //Adding new machines
    addMachine(new MachineA());
    addMachine(new MachineB());

    //Endless run config
    bool infinite = false;
    if(iterations == 0){
        infinite = true;
    }

    //Check if infinite or x loops
    while(infinite || iterations >0){
        iterations--;
        int run_condition;
        //Loop trough list to check all machines
        for( auto it = MachineList.begin(); it != MachineList.end();++it){
            try {
                //Run tick and check no exeption is thrown
                it->second->tick();
                std::this_thread::sleep_for(std::chrono::seconds(1));
                for(int i = 0; i < it->second->getPpz(); i++){
                    if (it->second->getProductType() == "A") {
                        addProduct(new ProductA);
                        std::cout << "Product " << it->second->getProductType() << ", added to storage A" << std::endl;
                    } else if (it->second->getProductType() == "B") {
                        addProduct(new ProductB);
                        std::cout << "Product " << it->second->getProductType() << ", added to storage B" << std::endl;
                    } else {
                        throw ErrorFactoryException("Machine or Product not defined");
                    }
                }
            } catch(ErrorMachineFailureException& e){
                std::cout << std::endl << "*** " << e.what() << " *** "  << std::endl << std::endl;
                //In case of an exception production is on hold for 3 sec
                int timer = 3;
                std::cout << "Status frozen frozen for " << timer << " sec " << std::endl;
                for (; timer > 0; timer--) {
                    std::cout << timer << " " << std::flush;
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                }
                std::cout << std::endl;
                ++it;
            } catch(ErrorMachineExplosionException& e){
                std::cout << std::endl << "*** " << e.what() << " *** "   << std::endl << std::endl;
                std::cout <<  " Machine " << it->second->getProductType() << ", with ID " << std::setfill('0') << std::setw(sizeof(int)) << it->first << "destroyed!" << std::endl << std::endl;
                deleteMachine(it->first);
                std::cout << std::endl;
                break;
            }
        }
    }
    std::cout << "Im Produktlager A befinden sich:" << getProductACount() << " Teile." << std::endl;
    std::cout << "Im Produktlager B befinden sich:" << getProductBCount() << " Teile." << std::endl;
}
