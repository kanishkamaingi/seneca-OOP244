/*
SUBMITTED BY-
NAME: -KANISHKA
STUDENT ID: 155238223
SENECA EMAIL: KANISHKA1@MYSENECA.CA
DATE OF SUBMISSION: FEBRUARY 08, 2024
*/

#ifndef SENECA_VENDOR_H
#define SENECA_VENDOR_H
#include "Icecream.h"

namespace seneca
{
    class Vendor{
        private:
            int numOrders;
            Icecream* orders;

        public:
            void setEmpty();
            void takeOrders();
            void displayOrders();
            void clearData();
    };
}
#endif