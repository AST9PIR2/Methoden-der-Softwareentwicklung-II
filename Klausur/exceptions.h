//
// Created by Pirmin on 20.05.2022.
//

#ifndef KLAUSUR_EXCEPTIONS_H
#define KLAUSUR_EXCEPTIONS_H

#include <stdexcept>

class ErrorFactoryException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class ErrorMachineException : public ErrorFactoryException {
public:
    using ErrorFactoryException::ErrorFactoryException;
};

class ErrorMachineFailureException : public ErrorFactoryException {
public:
    using ErrorFactoryException::ErrorFactoryException;
};


class ErrorMachineExplosionException : public ErrorFactoryException {
public:
    using ErrorFactoryException::ErrorFactoryException;
};

#endif //KLAUSUR_EXCEPTIONS_H
