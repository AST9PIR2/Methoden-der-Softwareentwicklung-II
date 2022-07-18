//
// Created by Pirmin on 16.05.2022.
//

#include "motor.h"
#include "exceptions.h"

//return Motor speed
int Motor::getSpeed() const {
    return speed;
}

//Check if requested speed is valid and change speed accordingly
void Motor::setSpeed(int speed) {
    if (speed >= 0 && speed <= 10) {
        std::cout << "Motor speed change from " << Motor::getSpeed() << " to " << speed << std::endl;
        Motor::speed = speed;
    } else {
        throw MotorException("Set Motor speed failed: Value out of range!");
    }

}

void Motor::emergencyBrake() {
    std::cout << std::endl << "!!! Emergency Brake! Motor stopped! !!!" << std::endl << std::endl;
    speed = 0;
}

