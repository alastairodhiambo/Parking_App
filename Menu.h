/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.h
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

#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include <iostream>

namespace sdds{

    const int MAX_NO_OF_ITEMS = 10;

    class Menu;

    class MenuItem{
        friend class Menu;
        char* m_name;

        MenuItem();
        MenuItem(const char*);
        std::ostream& write(std::ostream& = std::cout) const;
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;
        ~MenuItem();
    };

    class Menu{
        char* m_title;
        MenuItem *m_menuItems[MAX_NO_OF_ITEMS];
        int m_count;
        int m_indentation;
        
        void stringSet(const char*);
        bool stringCheck(const char*) const;
        std::ostream& indentLine(std::ostream& = std::cout) const;
        void menuItemsNull();
        void setEmpty();
        void init(const Menu&);
        void deallocTitle();
        void deallocMenuItems();

    public:
        Menu();
        Menu(const char*, int = 0);
        Menu(const Menu&);
        Menu& operator=(const Menu&);
        explicit operator bool() const;
        bool isEmpty() const;
        std::ostream& display(std::ostream& = std::cout) const;
        void operator=(const char*);
        void add(const char*);
        int run(std::istream& = std::cin, std::ostream& = std::cout) const;
        operator int() const;
        ~Menu();
    };

    Menu& operator<<(Menu& m, const char* item);
}

#endif