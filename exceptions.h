//
// Created by Claudia Steiner on 18.05.24.
//

#ifndef KLAUSUR_EXCEPTIONS_H
#define KLAUSUR_EXCEPTIONS_H


#include <stdexcept>
#include <string>
#include <iostream>

//klasse CarRentalException erbt von runtime_error und gibt die Fehlermeldung dessen Konstruktor
class CarRentalException : public std::runtime_error {
public:
    explicit CarRentalException(const std::string& message) : std::runtime_error(message) {}
};


class BrokenMotorException : public CarRentalException {
public:
    explicit BrokenMotorException(const std::string& message) : CarRentalException(message) {}

};


class ElectronicsFaultException   : public CarRentalException {
public:
    explicit ElectronicsFaultException (const std::string& message) : CarRentalException(message) {}

};

class EmissionsTooDirtyException : public CarRentalException {
public:
    explicit EmissionsTooDirtyException(const std::string& message) : CarRentalException(message) {}
};

class NoCarFoundException : public CarRentalException {
public:
    explicit NoCarFoundException(const std::string& message) : CarRentalException(message) {}
};

class InvalidCarException : public CarRentalException {
public:
    explicit InvalidCarException(const std::string& message) : CarRentalException(message) {}
};




#endif //KLAUSUR_EXCEPTIONS_H
