/* Citation and Sources...
Final Project Milestone 5
Module: Motorcycle
Filename: Motorcycle.cpp
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
#include "Motorcycle.h"
#include "Utils.h"

namespace sdds{
    Motorcycle::Motorcycle()
    {
        m_sidecar = INV;
    }

    Motorcycle::Motorcycle(const char* plate, const char* model) : Vehicle(plate, model)
    {
        if((plate == nullptr) || (model == nullptr) || (plate[0] == '\0') || (model[0] == '\0')) m_sidecar = INV;
    }

    std::istream& Motorcycle::read(std::istream& in)
    {
        int sidecarTemp = INV;
        if(isCsv()){
            Vehicle::read(in);
            in >> sidecarTemp;
            in.ignore(2000, '\n');
            if(sidecarTemp == Y || sidecarTemp == N)
            m_sidecar = sidecarTemp;
        }else{
            std::cout << std::endl;
            std::cout << "Motorcycle information entry" << std::endl;
            Vehicle::read(in);
            std::cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
            if(yesNo()){m_sidecar = Y;}else{m_sidecar = N;}
        }
        return in;
    }
    
    
    std::ostream& Motorcycle::write(std::ostream& os) const
    {
        if(m_sidecar == INV){
            os << "Invalid Motorcycle Object" << std::endl;
        }else{

            if(isCsv()){
                os << "M,";
            }else{
                os << "Vehicle type: Motorcycle" << std::endl;
            }

            Vehicle::write(os);
        
            if(isCsv()){
                os << m_sidecar << std::endl;
            }else if(m_sidecar == Y){
                os << "With Sidecar" << std::endl;
            }
        } 

        return os;
    }

}