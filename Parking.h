/* Citation and Sources...
Final Project Milestone 6
Module: Parking
Filename: Parking.h
Version 2.0
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

#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H

#include <iostream>
#include "Menu.h"
#include "Vehicle.h"

namespace sdds{

    const int MAX_SPOTS = 100;

    class Parking{
        char* m_filename;
        Menu m_parkingMenu;
        Menu m_vehicleMenu;
        int m_noOfSpots;
        Vehicle* m_parkingSpots[MAX_SPOTS];
        int m_noOfParked;
        Parking(const Parking&) = delete;
        Parking& operator=(const Parking&) = delete;
        bool isEmpty() const;
        void parkingStatus();
        void parkVehicle();
        void returnVehicle();
        void listParked() const;
        bool closeParking();
        bool exitParking();
        bool loadDataFile();
        void saveDataFile();
        void setEmpty();
    public:
        Parking();
        Parking(const char*, int);
        ~Parking();
        int run();
    };
}

#endif