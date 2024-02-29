// Customer.cpp
/*
SUBMITTED BY-
NAME: -KANISHKA
STUDENT ID: 155238223
SENECA EMAIL: KANISHKA1@MYSENECA.CA
DATE OF SUBMISSION: February 4, 2024
*/
#include <iostream>
#include<iomanip>
using namespace std;
#include <cstring>
#include "Customer.h"

namespace seneca
{
   

    bool Customer::isEmpty() const
    {
        return (m_car == nullptr || m_name == nullptr || !strcmp(m_name, ""));
    }

    void Customer::setEmpty()
    {
        m_id = 0;
        m_name = nullptr;
        m_car = nullptr;
    }

    void Customer::deallocateMemory()
    {
        delete[] m_name;
        m_name = nullptr;
    }

    void Customer::set(int customerId, const char *name, const Car *car)
    {
        deallocateMemory();
        if (name != nullptr && car != nullptr && strcmp(name, ""))
        {
            m_id = customerId;
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
            m_car = car;
        }
    }

    void Customer::display() const
    {
        cout << left << setw(15) << "Customer ID:" << right << setw(20) << m_id << endl;
        cout << left << setw(15) << "First Name:" << right << setw(20) << m_name << endl;
        if (m_car != nullptr)
        {
            m_car->display();
        }
    }

    const Car &Customer::car() const
    {
        return *m_car;
    }
}
