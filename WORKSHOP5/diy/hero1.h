#ifndef SENECA_HERO_H__
#define SENECA_HERO_H__
#include <iostream>
using namespace std;
#include "Power.h"
namespace seneca{
    class Hero{
    private:
        char m_name[MAX_NAME_LENGTH];
        Power* m_power;
        int m_numPowers;
        int m_powerLevel;
    public:
        Hero();
        Hero(const char* name, Power* powerList, int numPowers);
        ~Hero();
        
        std::ostream& display(std::ostream& ostr = std::cout);
        Hero& operator+=(Power& power);
        Hero& operator-=(int value);
        bool operator<(Hero& hero);
        bool operator>(Hero& hero);
        friend void operator>>(Hero &hero, Power &power);
        friend void operator<<(Hero &hero, Power &power);
    };
}
#endif