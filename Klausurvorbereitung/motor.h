//
// Created by Pirmin on 16.05.2022.
//

#ifndef VORBEREITUNG_MOTOR_H
#define VORBEREITUNG_MOTOR_H

#include <iostream>

class Motor{

private:

    int speed;

public:

    Motor(){
        //Motor speed initialized with 0
        speed = 0;
        std::cout << "+++ Constructor: Objekt Motor with speed " << speed << " , initialized +++" << std::endl;
    };

    ~Motor() {
        std::cout << "--- Destructor: Objekt Motor destroyed ---" << std::endl;
    }

    int getSpeed()const;

    void setSpeed(int speed);

    void emergencyBrake();


};

#endif //VORBEREITUNG_MOTOR_H
