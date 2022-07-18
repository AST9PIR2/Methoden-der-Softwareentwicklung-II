#include <iostream>
#include "robot.h"
#include "sensor_types.h"


int main() {
/*
    //Motor test bench
    {
        std::cout << "#####################################_Motor test bench_############################################" << std::endl << std::endl;
        Motor motor;
        std::cout << "Motor speed: " << motor.getSpeed() << std::endl;
        motor.setSpeed(0);
        std::cout << "Motor speed: " << motor.getSpeed() << std::endl;
        std::cout << std::endl << "#####################################_Motor test bench_############################################" << std::endl << std::endl;

    }

    //Sensor test bench
    {
        std::cout << "#####################################_Robot test_bench_############################################" << std::endl << std::endl;
        Robot test_bench;
        test_bench.addSensor(new Distancesensor());
        test_bench.addSensor(new Cliffsensor());
        test_bench.addSensor(new Camerasensor());
        test_bench.getSensor(1);
        test_bench.getSensor(2);
        test_bench.getSensor(0);
        //test_bench.deleteSensor(1);
        //test_bench.getSensor(1);
        std::cout << std::endl << "#####################################_Robot test_bench_############################################" << std::endl << std::endl;
    }
*/
    //Run
    {
        std::cout << "#####################################_Run_############################################" << std::endl << std::endl;
        auto robot = new Robot;
        robot->addSensor(new Distancesensor());
        robot->addSensor(new Cliffsensor());
        robot->addSensor(new Camerasensor());
        //robot->eventLoop(5);
        //robot->deleteSensor(1);
        robot->eventLoop(0);
        std::cout << std::endl << "#####################################_Run_############################################" << std::endl << std::endl;

    }

return 0;
}

