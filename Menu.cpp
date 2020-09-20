/* Citation and Sources...
Final Project Milestone 6
Module: Menu
Filename: Menu.cpp
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
#include <ios>
#include <string.h>
#include "Menu.h"

namespace sdds{

    /********* MENU ITEM *********/
    MenuItem::MenuItem()
    {
        m_name = nullptr;
    }

    MenuItem::MenuItem(const char* name)
    {
        if(name != nullptr && name[0] != '\0'){
            int len = strlen(name);
            m_name = new char[len+1];
            strcpy(m_name, name);
        }else m_name = nullptr;
    }

    std::ostream& MenuItem::write(std::ostream& os) const
    {
        if(m_name != nullptr) os << m_name << std::endl;

        return os;
    }
    
    MenuItem::~MenuItem()
    {
        delete [] m_name;
        m_name = nullptr;
    }

    /*****************************/
    
    /********* MENU *********/
    Menu::Menu()
    {
        setEmpty();
    }

    Menu::Menu(const char* title, int indentation)
    {
        if(stringCheck(title)){
            stringSet(title);
            m_indentation = indentation;
            m_count = 0;
            menuItemsNull();
        } else setEmpty();
    }

    Menu::Menu(const Menu& src)
    {
        init(src);
    }

    Menu& Menu::operator=(const Menu& src)
    {
        if(this != &src){
            deallocTitle();
            deallocMenuItems();
            init(src);
        }
        return *this;
    }
    
    Menu::operator bool() const
    {
        return m_title != nullptr;
    }
    
    bool Menu::isEmpty() const{
        return (!*this);
    }
    
    std::ostream& Menu::display(std::ostream& os) const
    {
        if(*this){
            indentLine(os);
            os << m_title << std::endl;
            if(m_count == 0){
                os << "No items to display!" << std::endl;
            }else{
                for(int i = 0; i < m_count; i++){
                    indentLine(os);
                    os << i+1 << "- ";
                    m_menuItems[i]->write(os);
                }
                indentLine(os);
                os << "> ";
            }

        }else if(isEmpty()){
            os << "Invalid Menu!" << std::endl;
        }

        return os;
    }
    
    void Menu::operator=(const char* newTitle)
    {
        deallocTitle();
        if(stringCheck(newTitle)){
            stringSet(newTitle);
        } else {
            deallocMenuItems();
            setEmpty();
        }
        
    }

    void Menu::add(const char* item)
    {
        if(item == nullptr){
            deallocTitle();
            deallocMenuItems();
            setEmpty();

        }else if(m_count < MAX_NO_OF_ITEMS && !isEmpty()){
            m_menuItems[m_count] = new MenuItem(item);
            m_count++;
        }else;
    }
    
    int Menu::run(std::istream& in, std::ostream& os) const
    {
        int choice = 0;
        display(os);
        if(m_count != 0){
            do{
                in >> choice;
                in.ignore(2000, '\n');

                if (in.fail() || choice == 0) {
                    os << "Invalid Integer, try again: ";
                    in.clear();
                } else if (choice <= 0 || choice > m_count) {
                    os << "Invalid selection, try again: ";
                }
            }while(!(choice > 0 && choice <= m_count));
        }

        return choice;
    }

    Menu::operator int() const
    {
        return run();
    }

    Menu::~Menu()
    {
        deallocTitle();
        deallocMenuItems();
    }

    Menu& operator<<(Menu& m, const char* item)
    {
        m.add(item);
        return m;
    }

    //Other Functions:

    //Sets the m_title variable to the given string.
    void Menu::stringSet(const char* newString)
    {
        int len = strlen(newString);
        m_title = new char[len + 1];
        strcpy(m_title, newString);
    }

    //Checks to see if the given string is valid
    bool Menu::stringCheck(const char* newString) const
    {
        return newString != nullptr && newString[0] != '\0';
    }

    std::ostream& Menu::indentLine(std::ostream& os) const
    {
        if(m_indentation > 0){
            for(int i = 0; i < m_indentation; i++){
                os << "    ";
            }
        }
        return os;
    }

    void Menu::menuItemsNull()
    {
        for(int i = 0; i < MAX_NO_OF_ITEMS; i++){
            m_menuItems[i] = nullptr;
        }
    }

    void Menu::setEmpty()
    {
        m_title = nullptr;
        menuItemsNull();
        m_count = 0;
        m_indentation = 0;
    }

    void Menu::init(const Menu& source)
    {
        if(source){
            m_count = source.m_count;
            m_indentation = source.m_indentation;
            stringSet(source.m_title);

            menuItemsNull();

            if(m_count > 0){
                for (int i = 0; i < m_count; i++){
                    m_menuItems[i] = new MenuItem(source.m_menuItems[i]->m_name);
                }
            }
        }else setEmpty();
    }

    void Menu::deallocTitle()
    {
        if(*this) delete [] m_title;
        m_title = nullptr;
    }

    void Menu::deallocMenuItems()
    {
        for(int i = m_count - 1; i >= 0; i--){
            if(m_menuItems[i] != nullptr){
                delete m_menuItems[i];
                m_menuItems[i] = nullptr;
            }
            
        }
    }
}