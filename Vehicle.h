/* Citation and Sources...
Final Project Milestone 5
Module: Vehicle
Filename: Vehicle.h
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

#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H

#include <iostream>
#include <string>
#include "ReadWritable.h"

namespace sdds{

    const int MAX_PLATE = 8;
    const int MIN_MODEL = 2;


    class Vehicle : public ReadWritable{
        std::string m_plate;
        std::string m_model;
        int m_spot;
        Vehicle(const Vehicle&) = delete;
        Vehicle& operator=(const Vehicle&) = delete;
    
    protected:
        void setEmpty();
        bool isEmpty() const;
        const std::string getLicensePlate() const;
        const std::string getMakeModel() const;
        void setMakeModel(const char*);

    public:
        Vehicle();
        Vehicle(const char*, const char*);
        ~Vehicle();
        int getParkingSpot() const;
        void setParkingSpot(int);
        friend bool operator==(const Vehicle&, const char*);
        friend bool operator==(const Vehicle&, const Vehicle&);
        std::istream& read(std::istream& = std::cin);
        std::ostream& write(std::ostream& = std::cout) const;
    };

    bool operator==(const Vehicle&, const char*);
    bool operator==(const Vehicle&, const Vehicle&);

}

#endif