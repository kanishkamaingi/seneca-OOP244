/***********************************************************************
// OOP244 Workshop #03 p2: tester program 
//
// File	main.cpp
// Version 1.0
// Date: September 28, 2023
// Author: Yosef Ashibani
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: -KANISHKA            Date: FEBRUARY 8, 2024            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "Vendor.h"
using namespace seneca;
int main() {
    Vendor vendor;
    vendor.setEmpty();
    vendor.takeOrders();
    vendor.displayOrders();
    vendor.clearData();
    return 0;
}