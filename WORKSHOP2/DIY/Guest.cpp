/*
SUBMITTED BY-
NAME: -KANISHKA
STUDENT ID: 155238223
SENECA EMAIL: KANISHKA1@MYSENECA.CA
DATE OF SUBMISSION: February 1, 2024
*/

#include <iostream>
#include <cstring>
#include "Guest.h"
#include "Room.h"

namespace seneca {
    void set(Guest& guest, const char* first, const char* last, int age) {
        // guest.m_firstName = nullptr;
        // guest.m_lastName = nullptr;
        // if (guest.m_firstName)
        //     delete[] guest.m_firstName;
        // if (guest.m_lastName)
        //     delete[] guest.m_lastName;

        vacate(guest);



        if (first && last && strlen(first) > 0 && strlen(last) > 0) {
            guest.m_firstName = new char[strlen(first)+1];
            strcpy(guest.m_firstName, first);

            guest.m_lastName = new char[strlen(last)+1];
            strcpy(guest.m_lastName, last);
        }
        else {
            guest.m_firstName = nullptr;
            guest.m_lastName = nullptr;
        }

        guest.m_adult = (age >= 18);
    }

    void print(const Guest& guest) {
        if (guest.m_firstName!= nullptr && guest.m_lastName!=nullptr) {
            std::cout << guest.m_firstName << " " << guest.m_lastName;
            if (!guest.m_adult)
                std::cout << "(Child)";
        }
        else {
            std::cout << "Vacated!";
        }
        std::cout << std::endl;
    }

    void book(Guest& guest) {
        char firstName[100];
        char lastName[100];
        int age;

        std::cout << "Name: ";
        std::cin >> firstName;
        std::cout << "Lastname: ";
        std::cin >> lastName;
        std::cout << "Age: ";
        std::cin >> age;

        set(guest, firstName, lastName, age);
    }

    void vacate(Guest& guest) {
        //if (guest.m_firstName)
        delete[] guest.m_firstName;
        //if (guest.m_lastName)
        delete[] guest.m_lastName;
        guest.m_firstName = nullptr;
        guest.m_lastName = nullptr;
    }
}
