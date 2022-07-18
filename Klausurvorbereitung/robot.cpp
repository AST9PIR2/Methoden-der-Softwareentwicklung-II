//
// Created by Pirmin on 16.05.2022.
//
#include "robot.h"
#include "sensor.h"
#include "motor.h"
#include "exceptions.h"
#include <iomanip>
#include <thread>
#include <algorithm>

int Robot::addSensor(Sensor* sensor) {
    //maxSesnors = more than 9998 sensors seems unrealistic for such a simple robot
    for(int i = 0; i < 9999; i++) {
        //Check if ID is occupied
        if (!SensorList.count(i)) {
            SensorList.insert({i, sensor});
            std::cout << "NEW SENSOR ADDED TO LIST: ID_" << std::setfill('0') << std::setw(sizeof(int)) << SensorList.find(i)->first << ", Type: " << sensor->getSensorType() << std::endl;
            return i;
        }
    }
    throw RobotException("*** Preventing buffer overflow, max 1000 Sensors aloud! ***");
}


Sensor *Robot::getSensor(int id) {
    //Check if requested id exists
    try {
        std::cout << "SEARCH RESULTS FOR: ID_" << std::setfill('0') << std::setw(sizeof(int)) << id << ", Type: " << SensorList.at(id)->getSensorType() << std::endl;
        return SensorList.at(id);
    } catch (...) {
        throw RobotException("*** Getting requested Sensor failed! No valid ID! ***");
    }
}

void Robot::deleteSensor(int id) {
    //Check if requested id exists
    try{
        std::cout << "DELETED SENSOR : ID_" << std::setfill('0') << std::setw(sizeof(int)) << id << ", Type: " << SensorList.at(id)->getSensorType() << std::endl;
        SensorList.erase(id);
    }catch (...){
        throw RobotException("*** Deleting requested Sensor failed! No valid ID! ***");
    }

}

void Robot::eventLoop(int iterations) {

    //Endless run config
    bool infinite = false;
    if(iterations == 0){
        infinite = true;
    }

    auto motor = new Motor;

    //Check if infinite or x loops
    while(infinite || iterations >0){
        iterations--;
        auto temp = 0;
        int run_condition = 0;
        //Loop trough list to check all sensors
            for( auto it = SensorList.begin(); it != SensorList.end();it++){
                try{
                    auto runcase = it->second->checkSensor();
                    if (runcase > temp){
                        temp = runcase;
                        motor->setSpeed(11 - temp);
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                    }

                } catch(CriticalDangerException& e){
                    std::cout << std::endl << "*** " << e.what() << " *** " << *it << std::endl << std::endl;
                    motor->emergencyBrake();
                    run_condition = 1;
                    break;
                } catch(InternalErrorException& e){
                    std::cout << std::endl << "*** " << e.what() << " *** " << *it << std::endl << std::endl;
                    run_condition = 1;
                    motor->setSpeed(1);
                    break;
                }
            }
            if(run_condition == 1){
                std::cout << "Status frozen frozen for 5 sec " << std::endl;
                for (int i = 5; i  > 0; i--){
                    std::cout << i << " " << std::flush;
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                }
                std::cout <<std::endl;
            }
        }
    }




