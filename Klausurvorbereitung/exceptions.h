
#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <stdexcept>

class RobotException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class MotorException : public RobotException {
public:
    using RobotException::RobotException;
};

class CriticalDangerException : public RobotException {
public:
    using RobotException::RobotException;
};


class InternalErrorException : public RobotException {
public:
    using RobotException::RobotException;
};



#endif /* EXCEPTIONS_H_ */
