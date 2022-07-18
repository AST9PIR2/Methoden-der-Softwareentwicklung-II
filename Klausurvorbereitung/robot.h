//
// Created by Pirmin on 16.05.2022.
//

#ifndef VORBEREITUNG_ROBOT_H
#define VORBEREITUNG_ROBOT_H


#include <memory>
#include <map>
#include "sensor.h"
#include <utility>

class Robot {

private:

    std::map<int ,Sensor*> SensorList;

public:

    Robot(){

    };

     ~Robot(){

         for (auto sensor : SensorList) {
             delete sensor.second;
         }
         SensorList.clear();

         std::cout << "--- Destructor: Objekt Robot destroyed ---" << std::endl;
     };

    int addSensor(Sensor* sensor);
    Sensor* getSensor(int id);
    void deleteSensor(int id);
    void eventLoop(int iterations);

};

inline std::ostream& operator<<(std::ostream& out,const std::pair<int ,Sensor*>& c) {
    out << "SENSOR : ID_" << std::setfill('0') << std::setw(sizeof(int)) << c.first << ", Type: " << c.second->getSensorType() <<". ";
    return out;
}


#endif //VORBEREITUNG_ROBOT_H
