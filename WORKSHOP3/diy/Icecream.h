/*
SUBMITTED BY-
NAME: -KANISHKA
STUDENT ID: 155238223
SENECA EMAIL: KANISHKA1@MYSENECA.CA
DATE OF SUBMISSION: FEBRUARY 08, 2024
*/

#ifndef SENECA_ICECREAM_H
#define SENECA_ICECREAM_H

namespace seneca{
    class Icecream{
        private:
            int flavor;
            int numScoops;
            char vanillaWafer[20];
            double price=0.0;
        public:
            void getOrder();
            void printOrder();
            int getVal();
            //int displayError(int option, int maxNum);
    };
}
#endif