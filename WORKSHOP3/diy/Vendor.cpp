/*
SUBMITTED BY-
NAME: -KANISHKA
STUDENT ID: 155238223
SENECA EMAIL: KANISHKA1@MYSENECA.CA
DATE OF SUBMISSION: FEBRUARY 08, 2024
*/

#include <iostream>
#include "iomanip"
using namespace std;
#include "Vendor.h"
#include "Icecream.h"

namespace seneca
{
    void Vendor::setEmpty()
    {
        orders = nullptr;
        numOrders = 0;
    }

    void Vendor::takeOrders()
    {
        cout << "Seneca Icecream shop" << endl;
        cout << "          @" << endl;
        cout << "        (' .)" << endl;
        cout << "       (*.`. )" << endl;
        cout << "        \\###/" << endl;
        cout << "         \\#/" << endl;
        cout << "          V" << endl;
        cout << "How many Icecreams?" << endl
             << "> ";
        cin >> numOrders;

        orders = new Icecream[numOrders];

        for (int i = 0; i < numOrders; i++)
        {
            cout << "Order number " << i + 1 << ":" << endl;
            orders[i].getOrder();
        }
    }

    void Vendor::displayOrders()
    {
        double tPrice = 0;

        cout << "\n********** Order Summary **********" << endl;

        for (int i = 0; i < numOrders; i++)
        {
            cout << "Order No: " << i + 1 << ":" << endl;
            orders[i].printOrder();
            cout<<endl;
            if(i!=numOrders-1) cout<< endl;
            tPrice += orders[i].getVal();
        }
        cout << "-----------------------------------" << endl;
        cout.width(27);
        cout << left << "Price:" << setw(8) << right << fixed << setprecision(2) << tPrice << endl;
        cout.width(27);
        cout << left << "Tax:" << setw(8) << right << fixed << setprecision(2) << (tPrice * 0.13) << endl;
        cout.width(27);
        cout << left << "Total Price ($): " << setw(8) << right << fixed << setprecision(2) << tPrice + (tPrice * 0.13) << endl;
    }

    void Vendor::clearData()
    {
        delete[] orders;
        orders = nullptr;
        numOrders = 0;
    }
}
