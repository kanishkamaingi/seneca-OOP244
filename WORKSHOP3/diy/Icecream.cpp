/*
SUBMITTED BY-
NAME: -KANISHKA
STUDENT ID: 155238223
SENECA EMAIL: KANISHKA1@MYSENECA.CA
DATE OF SUBMISSION: FEBRUARY 08, 2024
*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <limits>
using namespace std;
#include "Icecream.h"

namespace seneca
{

    void Icecream::getOrder()
    {
        cout << "Select flavour:" << endl;
        cout << "----------------" << endl;
        cout << "1: Chocolate" << endl;
        cout << "2: Strawberry" << endl;
        cout << "3: Mango" << endl;
        cout << "4: Tutti fruit" << endl;
        cout << "5: Almond crunch" << endl;
        cout << "----------------" << endl;

        int done = false;
        do
        {
            cout << "> ";
            cin >> flavor;
            if (cin)
            {
                if (flavor < 1 || flavor > 5)
                    cout << "Invlid value(1<=val<=5)" << endl;

                else
                    done = true;
            }

            else
            {
                // failure, reset cin until a good value is given
                cin.clear();
                cin.ignore(10000, '\n'); // flush; ignores next 10000 garbage characters or until \n, whichever comes first. Assumption the garbage value given is not more than 10000
                cout << "Invalid entry, retry" << endl;
            }
        } while (!done);

        // displayError(flavor, 5);

        cout << "Number of Scoops (max 3)" << endl;

        int flag = false;
        do
        {
            cout << "> ";
            cin >> numScoops;
            if (cin)
            {
                if (numScoops < 1 || numScoops > 3)
                    cout << "Invlid value(1<=val<=3)" << endl;

                else
                    flag = true;
            }

            else
            {
                // failure, reset cin until a good value is given
                cin.clear();
                cin.ignore(10000, '\n'); // flush; ignores next 10000 garbage characters or until \n, whichever comes first. Assumption the garbage value given is not more than 10000
                cout << "Invalid entry, retry" << endl;
            }
        } while (!flag);

        // displayError(numScoops, 3);
        cout << "Vanilla wafer cone?" << endl;
        cout << "(Y)es/(N)o ";
        int temp = 0;
        while (!temp)
        {
            cout << "> ";
            cin >> vanillaWafer;
            if (strcmp(vanillaWafer, "y") != 0 &&
                strcmp(vanillaWafer, "n") != 0 &&
                strcmp(vanillaWafer, "Y") != 0 &&
                strcmp(vanillaWafer, "N") != 0)
            {
                cout << "Only Y or N are acceptable:" << endl;
            }
            else
                temp = 1;
        };
    }

    void Icecream::printOrder()
    {
        // double price=0.0;
        cout.width(27);
        cout << left << "Order details:" << setw(8) << right << "Price" << endl;
        cout.width(35);
        cout << left << "-----------------------------------" << endl;
        cout << left << "Number of scoops, " << numScoops << " total: ";
        cout << setw(8) << right << setprecision(2) << fixed << (numScoops * 5.00) << endl;
        price += numScoops * 5.00;
        switch (flavor)
        {
        case 1:
            cout.width(27);
            cout << left << "Chocolate flavour:" << setw(8) << right << setprecision(2)
                 << fixed << (numScoops * 1.00) << endl;
            price += (numScoops * 1.00);
            break;

        case 2:
            cout << "Strawberry flavour" << endl;
            break;

        case 3:
            cout << "Mango flavour" << endl;
            break;

        case 4:
            cout << "Tutti fruit flavour" << endl;
            break;

        case 5:
            cout << "Almond fruit flavour" << endl;
            break;

            // default:
            //     break;
        }

        if (!strcmp(vanillaWafer, "y") || !strcmp(vanillaWafer, "Y"))
        {
            cout.width(27);
            cout << left << "Vanilla Wafer:" << setw(8) << right << "5.00" << endl;
            price += 5.00;
        }
        else if (!strcmp(vanillaWafer, "n") || !strcmp(vanillaWafer, "N"))
        {
            cout.width(27);
            cout << left << "Vanilla Wafer:" << setw(8) << right << "0.00" << endl;
            price += 0.00;
        }

        cout.width(27);
        cout << left << "Price:" << setw(8) << right << setprecision(2) << fixed << price;
    }

    int Icecream::getVal()
    {
        return price;
    }

}