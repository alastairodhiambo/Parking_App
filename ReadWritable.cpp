/* Citation and Sources...
Final Project Milestone 4
Module: ReadWritable
Filename: ReadWritable.cpp
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
#include "ReadWritable.h"


namespace sdds{

    ReadWritable::ReadWritable()
    {
        m_csvFlag = false;
    }

    ReadWritable::~ReadWritable(){}
    
    bool ReadWritable::isCsv() const
    {
        return m_csvFlag;
    }

    void ReadWritable::setCsv(bool value)
    {
        m_csvFlag = value;
    }

    //Helper Functions
    std::istream& operator>>(std::istream& in, ReadWritable& rw)
    {
        rw.read(in);
        return in;
    }

    std::ostream& operator<<(std::ostream& os, ReadWritable& rw)
    {
        rw.write(os);
        return os;
    }
}