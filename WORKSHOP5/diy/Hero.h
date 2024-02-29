/***********************************************************************
// OOP244 Workshop #5 p2: tester program
//
// File	main_prof.cpp
// Version 1.0
// Author Mohammad Shamas
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// -KANISHKA       February 22, 2022
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SENECA_HERO_H
#define SENECA_HERO_H
#include "Power.h"
#include <iostream>

namespace seneca {
    const int MAX_NAME_LEN = 50;

    class Hero
    {
        private:
        char m_name[MAX_NAME_LEN];
        Power *powers;
        int m_numPower;
        int m_powerLevel;

        public:
        Hero();
        Hero(const char* name, Power* powerList, int numPower);
        ~Hero();
        std::ostream &display(std::ostream &os = std::cout) const;
        Hero& operator+=(Power &powers);
        Hero& operator-=(int value);
        friend bool operator<(const Hero& hero1, const Hero& hero2);
        friend bool operator>(const Hero& hero1, const Hero& hero2);
        friend void operator>>(Power &power, Hero &hero);
        friend void operator<<(Hero &hero, Power &power);
         
    };
}
#endif