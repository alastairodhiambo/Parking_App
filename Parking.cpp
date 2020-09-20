/* Citation and Sources...
Final Project Milestone 6
Module: Parking
Filename: Parking.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include "Parking.h"
#include "Menu.h"
#include "Utils.h"
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"


using namespace std;

namespace sdds{

    Parking::Parking()
    {
        setEmpty();
    }

    Parking::Parking(const char* datafile, int noOfSpots)
    {
        if(datafile != nullptr && datafile[0] != '\0' && noOfSpots >= 10 && noOfSpots <= MAX_SPOTS){
            int len = strlen(datafile);
            m_filename = nullptr;
            m_filename = new char[len + 1];
            strcpy(m_filename, datafile);
            m_noOfSpots = noOfSpots;
            m_noOfParked = 0;
            for(int i = 0; i < MAX_SPOTS; i++){
                m_parkingSpots[i] = nullptr;
            }

            if(loadDataFile()){
                m_parkingMenu = "Parking Menu, select an action:";
                m_parkingMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Close Parking (End of day)" << "Exit Program";

                m_vehicleMenu = Menu("Select type of the vehicle:", 1);
                m_vehicleMenu << "Car" << "Motorcycle" << "Cancel";
            }else{
                std::cout << "Error in data file" << std::endl;
            }
        }else setEmpty();
    }

    void Parking::setEmpty()
    {
        m_filename = nullptr;
        for (int i = 0; i < MAX_SPOTS; i++) {
            m_parkingSpots[i] = nullptr;
        }
        m_noOfParked = 0;
        m_noOfSpots = 0;
    }

    bool Parking::isEmpty() const
    {
        return m_filename == nullptr;
    }

    void Parking::parkingStatus()
    {
        std::cout << "****** Seneca Valet Parking ******" << endl;
        std::cout << "*****  Available spots: " << left << setw(4) << (m_noOfSpots - m_noOfParked) << right << " *****" << endl;
    }

    void Parking::parkVehicle()
    {
        
        if(m_noOfSpots == m_noOfParked){
            std::cout << "Parking is full" << std::endl;
        }else{
            int flag = 0;
            int run = m_vehicleMenu.run();
            
            if(run == 1 || run == 2){
                for(int i = 0; i < m_noOfSpots && flag != 1; i++){
                    if(m_parkingSpots[i] == nullptr){
                        if(run == 1) {
                            m_parkingSpots[i] = new Car();
                        }else m_parkingSpots[i] = new Motorcycle();

                        m_parkingSpots[i]->setCsv(false);
                        cin >> *m_parkingSpots[i];
                        m_parkingSpots[i]->setParkingSpot(i+1);
                        m_noOfParked++;
                        std::cout << endl << "Parking Ticket" << endl;
                        cout << *m_parkingSpots[i];
                        flag = 1;
                    }
                }
                std::cout << endl;
            }else if(run==3){
                std::cout << "Parking cancelled" << endl;
            }else{};
        }
    }

    void Parking::returnVehicle()
    {
        std::cout << "Return Vehicle" << endl;
        int flag = 1;
        std::cout << "Enter Licence Plate Number: ";
        do{
            string plate = "";
            getline(cin, plate,'\n');
            int lenPlate = plate.length();
            if (lenPlate > 8) {
                std::cout << "Invalid Licence Plate, try again: ";
            } else {
                for(int i = 0; i < lenPlate; i++){
                    plate[i] = toupper(plate[i]);
                }

                int check = 0;
                for(int i = 0; i < m_noOfSpots && check != 1; i++){
                    if(*m_parkingSpots[i] == plate.c_str()){
                        std::cout << endl << "Returning: " << endl;
                        m_parkingSpots[i]->setCsv(false);
                        cout << *m_parkingSpots[i] << endl;
                        delete m_parkingSpots[i];
                        m_parkingSpots[i] = nullptr;
                        m_noOfParked--;
                        check = 1;
                    }
                }

                if(check == 0){
                    std::cout << "License plate " << plate << " Not Found" << endl;
                }

                flag = 0;
            }
        }while(flag != 0);
    }

    void Parking::listParked() const
    {
        std::cout << "*** List of parked vehicles ***" << endl;
        for(int i = 0; i < m_noOfSpots; i++){
            if(m_parkingSpots[i] != nullptr){
                m_parkingSpots[i]->setCsv(false);
                cout << *m_parkingSpots[i];
                std::cout << "-------------------------------" << endl;
            }
            
        }
    }

    bool Parking::closeParking()
    {
        bool value = false;
        if(m_noOfParked == 0){
            std::cout << "Closing Parking" << endl;
            value = true;
        }else{
            std::cout << "This will Remove and tow all remaining vehicles from the parking!" << endl << "Are you sure? (Y)es/(N)o: ";
            if(yesNo()){
                std::cout << "Closing Parking" << endl;
                for(int i = 0; i < m_noOfSpots; i++){
                    if(m_parkingSpots[i] != nullptr){
                        std::cout << endl << "Towing request" << endl << "*********************" << endl;
                        m_parkingSpots[i]->setCsv(false);
                        cout << *m_parkingSpots[i];
                        delete m_parkingSpots[i];
                        m_parkingSpots[i] = nullptr;
                        m_noOfParked--;
                    }
                }
                value = true;
            }else cout << "Aborted!" << endl;
        }
        return value;
    }

    bool Parking::exitParking()
    {
        std::cout << "This will terminate the program!" << endl;
        std::cout << "Are you sure? (Y)es/(N)o: ";
        bool value = yesNo();
        return value;
    }

    bool Parking::loadDataFile()
    {
        bool value = true;

        if(!isEmpty()){
            ifstream datafile;
            datafile.open(m_filename);

            if(datafile){
                int flag = 0;
                do{
                    char vehicleType = '\0';
                    Vehicle *V = nullptr;

                    datafile.get(vehicleType);
                    datafile.ignore();
                    
                    if(vehicleType == 'M' || vehicleType == 'C'){
                        if (vehicleType == 'M') {
                            V = new Motorcycle();
                        }
                        else if (vehicleType == 'C') {
                            V = new Car();
                        }
                        else {};
                        
                        V->setCsv(true);
                        datafile >> *V;

                        if(V != nullptr){
                            int index = V->getParkingSpot() - 1;
                            m_parkingSpots[index] = V;
                            m_noOfParked++;
                        }else{
                            value = false;
                            delete V;
                            V = nullptr;
                        }
                    }else flag = 1;
                }while(flag != 1 && m_noOfParked < m_noOfSpots);
            }
        }
        return value;
    }
    
    void Parking::saveDataFile()
    {
        ofstream datafile;
        datafile.open(m_filename);
        if(datafile){
            for(int i = 0; i < m_noOfSpots; i++){
                if(m_parkingSpots[i] != nullptr){
                    m_parkingSpots[i]->setCsv(true);
                    datafile << *m_parkingSpots[i];
                }
            }
        }
        datafile.close();
    }

    int Parking::run()
    {
        int value = 1;
        if(!isEmpty()){
            while(value != 0){
                parkingStatus();
                switch(m_parkingMenu.run()){
                case 1:
                    parkVehicle();
                    break;
                case 2:
                    returnVehicle();
                    break;
                case 3:
                    listParked();
                    break;
                case 4:
                    if(closeParking()) value = 0;
                    break;
                case 5:
                    if(exitParking()){

                        std::cout << "Exiting program!" << endl;
                        value = 0;
                    } 
                    
                    break;
                default:
                    value = 0;
                }
            };
        }
        return value;
    }

    Parking::~Parking()
    {
        saveDataFile();
        for(int i = m_noOfSpots-1; i >= 0; i--){
                if(m_parkingSpots[i] != nullptr){
                    delete m_parkingSpots[i];
                    m_parkingSpots[i] = nullptr;
                    m_noOfParked--;
                }
        }
        if(m_filename != nullptr) delete [] m_filename;
        m_filename = nullptr;
    }
}