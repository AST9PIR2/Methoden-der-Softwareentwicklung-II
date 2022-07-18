//
// Created by Pirmin on 16.05.2022.
//

#include <random>
#include "sensor.h"
#include "exceptions.h"

int Sensor::checkSensor() {
    //Seed for rand function
    srand((unsigned) time(nullptr));

    //Checking possible CriticalDanger/InternalError and getting radom trigger from Sensor
    if (probability(probabilityCriticalDangerException)) {
        throw CriticalDangerException("CriticalDangerException!");
    } else if (probability(probabilityInternalErrorException)){
        throw InternalErrorException("InternalErrorException!");
    } else{
        return (std::rand() % Sensor::maxTrigger + 1);
    }
}



//Probability generator. Stollen from: https://stackoverflow.com/questions/58326619/how-can-i-make-something-happen-x-percentage
//Input in % z.B probability(15) for 15%
int Sensor::probability(int value) {
    std::random_device rd;
    std::mt19937 gen(rd());
    double interval[] = {0,0,1,1};
    double weights[] = { static_cast<double>(100-value), 0, static_cast<double>(value)};
    std::piecewise_constant_distribution<> dist(std::begin(interval),std::end(interval),weights);
    return dist(gen);
}

const std::string &Sensor::getSensorType() const {
    return sensorType;
}

int Sensor::getMaxTrigger() const {
    return maxTrigger;
}











