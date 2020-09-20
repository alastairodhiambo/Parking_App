/* Citation and Sources...
Final Project Milestone 5
Module: Car
Filename: Car.h
Version 1.0
Author Alastair Odhiambo
Revision History
-----------------------------------------------------------
Date Reason
2020/?/? ..
2020/?/? ..
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds{
    
    const int INVALID = -1;
    const int YES = 1;
    const int NO = 0;


    class Car : public Vehicle{
        int m_carwash;
        Car(const Car&) = delete;
        Car& operator=(const Car&) = delete;
    public:
        Car();
        Car(const char*, const char*);
        std::istream& read(std::istream& = std::cin);
        std::ostream& write(std::ostream& = std::cout) const;
    };
}

#endif