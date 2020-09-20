/* Citation and Sources...
Final Project Milestone 5
Module: Car
Filename: Car.cpp
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
#include "Car.h"
#include "Utils.h"



namespace sdds{
    Car::Car()
    {
        m_carwash = INVALID;
    }

    Car::Car(const char* plate, const char* model) : Vehicle(plate, model)
    {
        if((plate == nullptr) || (model == nullptr) || (plate[0] == '\0') || (model[0] == '\0')) m_carwash = INVALID;
    }

    std::istream& Car::read(std::istream& in)
    {
        int carWashTemp = INVALID;
        if(isCsv()){
            Vehicle::read(in);
            in >> carWashTemp;
            in.ignore(2000, '\n');
            if(carWashTemp == YES || carWashTemp == NO)m_carwash = carWashTemp;
        }else{
            std::cout << std::endl;
            std::cout << "Car information entry" << std::endl;
            Vehicle::read(in);
            std::cout << "Carwash while parked? (Y)es/(N)o: ";
            if(yesNo()){m_carwash = YES;}else{m_carwash = NO;}
        }
        return in;
    }
    
    
    std::ostream& Car::write(std::ostream& os) const
    {
        if(isEmpty()){
            os << "Invalid Car Object";
        }else{
            if(isCsv()){
                os << "C,";
            }else{
                os << "Vehicle type: Car" << std::endl;
            }

            Vehicle::write(os);
            
            if(isCsv()){
                os << m_carwash;
            }else{
                if(m_carwash == YES){
                    os << "With Carwash";
                }else if(m_carwash == NO){
                    os << "Without Carwash";
                }
            }
        }
        os << std::endl;
        
        return os;
    }

}