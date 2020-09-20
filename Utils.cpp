/* Citation and Sources...
Final Project Milestone 4
Module: Utils
Filename: Utils.h
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
#include <string.h>


namespace sdds{

    bool yesNo(std::istream& in, std::ostream& os){
        
        std::string str;

        bool value = false;
        int flag = 1;
        do{
            in >> str;
            in.ignore(2000, '\n');
            
            if(strcmp("Y", str.c_str()) == 0 || strcmp("y", str.c_str()) == 0){
                value = true;
                flag = 0;
            }else if(strcmp("N", str.c_str()) == 0 || strcmp("n", str.c_str()) == 0){
                value = false;
                flag = 0;
            }else{
                os << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            }
        }while(flag != 0);

        return value;
    } 
}