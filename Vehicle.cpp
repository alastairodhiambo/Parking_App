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
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include "Vehicle.h"

namespace sdds{
    
    Vehicle::Vehicle()
    {
        setEmpty();
    }

    Vehicle::Vehicle(const char* plate, const char* model)
    {
        if(plate != nullptr && model != nullptr && plate[0] != '\0' && model[0] != '\0'){
            int lenPlate = strlen(plate);
            int lenModel = strlen(model);
            if (lenPlate <= MAX_PLATE && lenModel >= MIN_MODEL) {
                for (int i = 0; i < lenPlate; i++) {
                    m_plate[i] = toupper(plate[i]);
                }
                
                m_model = model;
                m_spot = 0;
            }
        } else setEmpty();
    }

    Vehicle::~Vehicle(){}

    void Vehicle::setEmpty()
    {
        m_plate[0] = '\0';
        m_model[0] = '\0';
        m_spot = -1;
    }

    bool Vehicle::isEmpty() const
    {
        return m_model[0] == '\0';
    }

    const std::string Vehicle::getLicensePlate() const
    {
        return m_plate;
    }

    const std::string Vehicle::getMakeModel() const
    {
        return m_model;
    }

    void Vehicle::setMakeModel(const char* model)
    {
        int lenModel = strlen(model);
        if(model[0] != '\0' && lenModel >= 2){
            m_model = model;
        }else{
            setEmpty();
        } 
    }

    int Vehicle::getParkingSpot() const
    {
        return m_spot;
    }
    
    void Vehicle::setParkingSpot(int spot)
    {
        if(spot <= 0){
            setEmpty();
        }else m_spot = spot;
    }

    bool operator==(const Vehicle& src, const char* plate)
    {
        bool value = false;
        std::string temp = plate;
        int lenPlate = strlen(plate);

        for(int i = 0; i < lenPlate; i++){
            temp[i] = toupper(temp[i]);
        }

        if(!src.isEmpty() && plate != nullptr && plate[0] != '\0' && src.m_plate == temp){
            value = true;
        }

        return value;
    }

    bool operator==(const Vehicle& src1, const Vehicle& src2)
    {
        return !src1.isEmpty() && !src2.isEmpty() && (src1.m_plate.compare(src2.m_plate) == 0);
    }

    std::istream& Vehicle::read(std::istream& in)
    {
        int spot = 0;
        std::string plate = "";
        std::string model = "";
        

        if(isCsv()){
            in >> spot;
            in.ignore(1, ',');
            std::getline(in, plate, ',');
            int lenPlate = plate.length();
            for(int i = 0; i < lenPlate; i++){
                plate[i] = toupper(plate[i]);
            }
            std::getline(in, model, ',');
        }else {
            int flag = 1;
            std::cout << "Enter Licence Plate Number: ";
            do{
                std::getline(in, plate, '\n');
                int len = plate.length();
                if (len > MAX_PLATE || plate == "") {
                    std::cout << "Invalid Licence Plate, try again: ";
                } else {
                    for(int i = 0; i < len; i++){
                        plate[i] = toupper(plate[i]);
                    }
                    flag = 0;
                }
            }while(flag != 0);

            flag = 1;
            std::cout << "Enter Make and Model: ";
            do{
                std::getline(in, model);
                int lenModel = model.length();
                if (lenModel < 2 || lenModel > 60) {
                    std::cout << "Invalid Make and model, try again: ";
                }else {
                    flag = 0;
                }
            }while(flag != 0);
        }

        if(in.fail()){
            in.clear();
            setEmpty();
        }else{
            m_spot = spot;
            m_plate = plate;
            /* setMakeModel(model); */
            m_model = model;
        }
        
        return in;
    }
    
    std::ostream& Vehicle::write(std::ostream& os) const
    {
        if(isEmpty()){
            os << "Invalid Vehicle Object" << std::endl;
        }else if(isCsv()){
            os << m_spot << ',' << m_plate << ',' << m_model << ',';
        } else{
            os << "Parking Spot Number: ";

            if (m_spot == 0) {
                os << "N/A";
            }else os << m_spot;

            os << std::endl;
            os << "Licence Plate: " << m_plate << std::endl;
            os << "Make and Model: " << m_model << std::endl;
        }
        return os;
    }
}