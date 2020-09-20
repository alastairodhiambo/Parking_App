/* Citation and Sources...
Final Project Milestone 5
Module: Motorcycle
Filename: Motorcycle.h
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
#ifndef SDDS_MOTORCYCLE_H
#define SDDS_MOTORCYCLE_H

#include <iostream>
#include <string>
#include "Vehicle.h"


namespace sdds{
    
    const int INV = -1;
    const int Y = 1;
    const int N = 0;

    class Motorcycle : public Vehicle{

        int m_sidecar;
        Motorcycle(const Motorcycle&) = delete;
        Motorcycle& operator=(const Motorcycle&) = delete;
    public:
        Motorcycle();
        Motorcycle(const char*, const char*);
        std::istream& read(std::istream& = std::cin);
        std::ostream& write(std::ostream& = std::cout) const;
    };
}

#endif