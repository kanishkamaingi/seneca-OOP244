// Car.cpp
/*
SUBMITTED BY-
NAME: -KANISHKA
STUDENT ID: 155238223
SENECA EMAIL: KANISHKA1@MYSENECA.CA
DATE OF SUBMISSION: February 4, 2024
*/
#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "Car.h"

namespace seneca
{

    bool Car::isEmpty() const
    {
        return (m_makeModel == nullptr ||
                m_serviceDesc == nullptr ||
                !strcmp(m_serviceDesc, "") ||
                !strcmp(m_makeModel, ""));
    }

    void Car::setEmpty()
    {
        strcpy(m_licencePlate, "");
        m_makeModel = nullptr;
        m_serviceDesc = nullptr;
        m_cost = 0.0;
    }

    void Car::deallocateMemory()
    {
        delete[] m_makeModel;
        delete[] m_serviceDesc;
        m_makeModel = nullptr;
        m_serviceDesc = nullptr;
    }

    void Car::set(const char plateNo[], const char *carMakeModel, const char *serviceDesc, double serviceCost)
    {
        deallocateMemory();

        if (serviceDesc != nullptr && carMakeModel != nullptr && strcmp(serviceDesc, "") && strcmp(carMakeModel, ""))
        {
            strcpy(m_licencePlate, plateNo);
            m_makeModel = new char[strlen(carMakeModel) + 1];
            strcpy(m_makeModel, carMakeModel);
            m_serviceDesc = new char[strlen(serviceDesc) + 1];
            strcpy(m_serviceDesc, serviceDesc);
            m_cost = serviceCost;
        }
    }

    void Car::display() const
    {
        if(m_serviceDesc != nullptr && strcmp(m_serviceDesc, "") && m_makeModel !=nullptr && strcmp(m_makeModel, "")){
            cout.width(15);
            cout << left << "License Plate:" << setw(20) << right << m_licencePlate << endl;
            cout.width(15);
            cout << left << "Model:" << setw(20) << right << m_makeModel << endl;
            cout.width(15);
            cout << left << "Service Name:" << setw(20) << right << m_serviceDesc << endl;
            cout.width(15);
            cout << left << "Service Cost:";
            cout.width(20);
            cout.setf(ios::fixed);
            cout << setprecision(2) << right << m_cost << endl;
        }
    }
}