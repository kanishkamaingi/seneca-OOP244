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

#include <iostream>
#include <string.h>
using namespace std;
#include "Hero.h"
namespace seneca
{
    Hero::Hero()
    {
        powers = nullptr;
        m_numPower = 0;
        m_powerLevel = 0;
        m_name[0] = '\0';
    }

    Hero::Hero(const char *name, Power *powerList, int numPower)
    {
        // Hero();
        m_powerLevel = 0;
        strcpy(m_name, name);
        if (powerList && numPower > 0)
        {
            powers = new Power[numPower];
            for (int i = 0; i < numPower; i++)
            {
                powers[i] = powerList[i];
            }
        }
        
        m_numPower = numPower;
        for (int i = 0; i < m_numPower; ++i)
        {
            m_powerLevel += powers[i].checkRarity();
        }
        m_powerLevel *= m_numPower;
    }

    Hero::~Hero()
    {
        delete[] powers;
        powers = nullptr;
        //m_numPower=0;
        //m_powerLevel=0;
        //delete[] m_name;

    }
    std::ostream &Hero::display(std::ostream &os) const
    {
        os << "Name: " << m_name << endl;

        os << "List of available powers: " <<endl;
        for (int i = 0; i < m_numPower; i++)
        {
            if (!powers[i].isEmpty())
            {
                os << "  Name: " << powers[i].checkName() << ", "
                     << "Rarity: " << powers[i].checkRarity() << endl;
            }
        }
        os << "Power Level: " << m_powerLevel;
        return os;
    }

    Hero &Hero::operator+=(Power &power)
    {
        Power *newPowers = new Power[m_numPower + 1];
        for (int i = 0; i < m_numPower; i++)
        {
            newPowers[i] = powers[i];
        }
        newPowers[m_numPower] = power;
        delete[] powers;
        powers = newPowers;

        m_numPower++;
        m_powerLevel=0;
        for (int i = 0; i < m_numPower; ++i)
        {
            m_powerLevel += powers[i].checkRarity();
            // cout<<m_powerLevel<<endl;
        }
        m_powerLevel *= m_numPower;
 
        return *this;
    }

    Hero &Hero::operator-=(int value)
    {
        m_powerLevel -= value;
        return *this;
    }

    bool operator<(const Hero &hero1, const Hero &hero2)
    {
        return hero1.m_powerLevel < hero2.m_powerLevel;
    }

    bool operator>(const Hero &hero1, const Hero &hero2)
    {
        return hero1.m_powerLevel > hero2.m_powerLevel;
    }

    void operator>>(Power &power, Hero &hero)
    {
        hero += (power);
    }
    void operator<<(Hero &hero, Power &power)
    {
        hero += (power);
    }
}