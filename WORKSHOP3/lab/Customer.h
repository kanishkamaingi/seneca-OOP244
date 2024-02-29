// Customer.h
/*
SUBMITTED BY-
NAME: -KANISHKA
STUDENT ID: 155238223
SENECA EMAIL: KANISHKA1@MYSENECA.CA
DATE OF SUBMISSION: February 4, 2024
*/
#ifndef SENECA_CUSTOMER_H
#define SENECA_CUSTOMER_H

#include "Car.h"

namespace seneca
{
    class Customer
    {
    private:
        int m_id;
        char *m_name;
        const Car *m_car;

    public:
        
        bool isEmpty() const;
        void setEmpty();
        void deallocateMemory();
        void set(int customerId, const char *name, const Car *car);
        void display() const;
        const Car &car() const;
    };
}
#endif 