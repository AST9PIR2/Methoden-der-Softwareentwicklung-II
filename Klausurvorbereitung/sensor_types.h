//
// Created by Pirmin on 16.05.2022.
//

#ifndef VORBEREITUNG_SENSOR_TYPES_H
#define VORBEREITUNG_SENSOR_TYPES_H

#include <utility>

#include "sensor.h"

class Distancesensor : public Sensor{

public:


    Distancesensor() : Sensor("Distancesensor",6,15,5){
        std::cout << "+++ Constructor: Objekt "<< getSensorType() << " with maxTrigger "<< getMaxTrigger() << " , initialized +++" << std::endl;
    }

};

class Cliffsensor : public Sensor{

public:
    Cliffsensor() : Sensor("Cliffsensor",4,15,5){
        std::cout << "+++ Constructor: Objekt "<< getSensorType() << " with maxTrigger "<< getMaxTrigger() << " , initialized +++" << std::endl;
    }

};

class Camerasensor : public Sensor{

public:


    Camerasensor() : Sensor("Camerasensor",9,15,5){
        std::cout << "+++ Constructor: Objekt "<< getSensorType() << " with maxTrigger "<< getMaxTrigger() << " , initialized +++" << std::endl;
    }
};


#endif //VORBEREITUNG_SENSOR_TYPES_H
