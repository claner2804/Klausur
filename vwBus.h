//
// Created by Claudia Steiner on 18.05.24.
//

#ifndef KLAUSUR_VWBUS_H
#define KLAUSUR_VWBUS_H

#include "car.h"
#include <iostream>
#include <cstdlib>
#include "exceptions.h"

//		○ 8 Passagierplätze
//		○ Führerscheinklasse: 2
//		○ Hat eine 5% Wahrscheinlichkeit eine BrokenMotorException zu werfen.
//		○ Hat eine 10% Wahrscheinlichkeit eine ElectronicsFaultException zu werfen.
//Eine EmissionsTooDirtyException kann bei diesem Fahrzeug nicht vorkommen.

class VwBus : public Car{

    int passengerSeats = 8;

    int requiredDriversLicense = 2;

    std::string name = "VW Bus";

public:

    virtual std::string getName() override {
        return name;
    }

    int getRequiredDrivingLicense() override {
        return requiredDriversLicense;
    }

    int getPassengerCount() override {
        return passengerSeats;
    }

    //Hat eine 5% Wahrscheinlichkeit eine BrokenMotorException zu werfen.
    bool isBrokenMotor()  {
        if (rand() % 100 < 5) {
            return true;
        } else {
            return false;
        }
    }

    //Hat eine 10% Wahrscheinlichkeit eine ElectronicsFaultException zu werfen.
    bool isElectronicsFault()  {
        if (rand() % 100 < 10) {
            return true;
        } else {
            return false;
        }
    }

    //Eine EmissionsTooDirtyException kann bei diesem Fahrzeug nicht vorkommen.
    bool isEmissionsTooDirty()  {
        return false;
    }

    bool checkCar() override {
        if (isBrokenMotor()) {
            throw BrokenMotorException("VW Bus hat einen kaputten Motor.");
        } else if (isElectronicsFault()) {
            throw ElectronicsFaultException("VW Bus hat einen Elektronikfehler.");
        } else {
            return true;
        }
    }



    VwBus() {
        std::cout << "VW Bus hinzugefügt" << std::endl;
    }

    ~VwBus() {
        std::cout << "VW Bus verkauft" << std::endl;
    }


};


#endif //KLAUSUR_VWBUS_H
