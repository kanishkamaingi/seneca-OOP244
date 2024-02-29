#include <iostream>
#include <cstring>
using namespace std;
#include "hero1.h"
namespace seneca
{
    Hero::Hero()
    {
        m_power = nullptr;
        m_powerLevel = 0;
        m_numPowers = 0;
        strcpy(m_name, "");
    }
    Hero::Hero(const char *name, Power *powerList, int numPowers)
    {
        strcpy(m_name, name);
        int powerLevel = 0;
        m_power = new Power[numPowers + 1];
        for (int i = 0; i < numPowers; i++)
        {
            m_power[i] = powerList[0];
            powerLevel += powerList[0].checkRarity();
        }
        powerLevel *= numPowers;
        m_powerLevel = powerLevel;
        m_numPowers = numPowers;
    }
    std::ostream &Hero::display(std::ostream &ostr)
    {
        ostr << "Name: " << m_name << endl;

        ostr << "List of available powers:" << endl;
        for (int i = 0; i < m_numPowers; i++)
        {
            if (!m_power[i].isEmpty())
            {
                ostr << "  Name: " << m_power[i].checkName() << ", "
                     << "Rarity: " << m_power[i].checkRarity() << endl;
            }
        }
        ostr << "Power Level: " << m_powerLevel;
        return ostr;
    }

    Hero::~Hero()
    {
        delete[] m_power;
        m_power = nullptr;
        //m_numPower=0;
        //m_powerLevel=0;
        //delete[] m_name;

    }

    Hero& Hero::operator+=(Power &power)
    {
        int i;
        Power* temp = new Power[m_numPowers + 1];
        for(i = 0; i < m_numPowers; i++){
            temp[i] = m_power[i];
        }
        temp[i] = power;
        delete[]  m_power;
        m_power = temp;

        m_powerLevel=0;
        for (int i = 0; i < m_numPowers; ++i)
        {
            m_powerLevel += m_power[i].checkRarity();
            // cout<<m_powerLevel<<endl;
        }
        m_powerLevel *= m_numPowers;
 
        return *this;
    }
    Hero& Hero::operator-=(int value){
        m_powerLevel -= value;
        return *this;
    }
    bool Hero::operator<(Hero &hero){
        return m_numPowers < hero.m_numPowers;
    }
    bool Hero::operator>(Hero &hero){
        return m_numPowers > hero.m_numPowers;
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