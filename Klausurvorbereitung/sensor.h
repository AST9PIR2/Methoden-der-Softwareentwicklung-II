//
// Created by Pirmin on 16.05.2022.
//

#ifndef VORBEREITUNG_SENSOR_H
#define VORBEREITUNG_SENSOR_H

#include <iostream>
#include <chrono>
#include <memory>
#include <utility>
#include <iomanip>


class Sensor{

protected:

    std::string sensorType;
    int maxTrigger = 0;
    int probabilityCriticalDangerException;
    int probabilityInternalErrorException;

public:

    Sensor( std::string sensorType, int maxTrigger, int probabilityCriticalDangerException, int probabilityInternalErrorException) :
            sensorType(sensorType), maxTrigger(maxTrigger), probabilityCriticalDangerException(probabilityCriticalDangerException),
            probabilityInternalErrorException(probabilityInternalErrorException) {
    }

    ~Sensor() {
        std::cout << "--- Destructor: Objekt Sensor destroyed ---" << std::endl;
    }


    const std::string &getSensorType() const;

    int getMaxTrigger() const;

    int checkSensor();

    int probability(int value);

};


#endif //VORBEREITUNG_SENSOR_H
