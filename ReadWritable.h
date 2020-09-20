/* Citation and Sources...
Final Project Milestone 4
Module: ReadWritable
Filename: ReadWritable.h
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

#ifndef SDDS_READWRITABLE_H
#define SDDS_READWRITABLE_H

#include <iostream>

namespace sdds{
    class ReadWritable{
        bool m_csvFlag;
    
    public:
        ReadWritable();
        virtual ~ReadWritable();
        bool isCsv() const;
        void setCsv(bool value);
        virtual std::istream& read(std::istream& = std::cin) = 0;
        virtual std::ostream& write(std::ostream& = std::cout) const = 0;
    };

    std::istream& operator>>(std::istream&, ReadWritable&);
    std::ostream& operator<<(std::ostream&, ReadWritable&);

}

#endif