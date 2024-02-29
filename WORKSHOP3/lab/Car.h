// Car.h
/*
SUBMITTED BY-
NAME: -KANISHKA
STUDENT ID: 155238223
SENECA EMAIL: KANISHKA1@MYSENECA.CA
DATE OF SUBMISSION: February 4, 2024
*/
#ifndef SENECA_CAR_H
#define SENECA_CAR_H

namespace seneca
{
    class Car
    {
    private:
        char m_licencePlate[9];
        char *m_makeModel;
        char *m_serviceDesc;
        double m_cost;

    public:

        bool isEmpty() const;
        void setEmpty();
        void deallocateMemory();
        void set(const char plateNo[], const char *carMakeModel, const char *serviceDesc, double serviceCost);
        void display() const;
    };
}
#endif 
