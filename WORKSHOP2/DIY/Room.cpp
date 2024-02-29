/*
SUBMITTED BY-
NAME: -KANISHKA
STUDENT ID: 155238223
SENECA EMAIL: KANISHKA1@MYSENECA.CA
DATE OF SUBMISSION: February 1, 2024
*/

#include <iostream>
using namespace std;
#include <cstring>
#include "Room.h"
#include "Guest.h"

namespace seneca {
    void set(Room& room, int numberOfGuests, const char* roomNumber) {
        strcpy(room.m_roomNumber, roomNumber);
        room.m_noOfGuests = numberOfGuests;
        room.m_guests = new Guest[numberOfGuests];
        for(int i = 0; i < numberOfGuests; ++i) {
            set(room.m_guests[i], nullptr, nullptr, 0); // Initialize guests
        }
    }

    void print(const Room& room) {
        if(room.m_noOfGuests!=0) std::cout << "Room Number: " << room.m_roomNumber << std::endl;
        if (room.m_noOfGuests == 0) {
            std::cout << "Empty Room!" << std::endl;
        } else {
            for (int i = 0; i < room.m_noOfGuests; ++i) {
                std::cout << "    ";
                print(room.m_guests[i]);
            }
        }
    }

    void book(Room& room) {
        char roomNumber[100];
        int numberOfGuests;

        // std::cout << "--- Enter the following:" << std::endl;
        std::cout << "Room number: ";
        std::cin >> roomNumber;
        std::cout << "Number of guests: ";
        std::cin >> numberOfGuests;

        set(room, numberOfGuests, roomNumber);

        for (int i = 0; i < numberOfGuests; ++i) {
            std::cout << i + 1 << ":" << std::endl;
            book(room.m_guests[i]);
        }
    }

    // void vacate(Room& room) {
    //     delete[] room.m_guests;
    //     room.m_guests = nullptr;
    //     room.m_noOfGuests = 0;
    // }

    void vacate(Room& room)
	{
		room.m_roomNumber[0] = '\0';
		if (room.m_guests) {
			for (int i = 0; i < room.m_noOfGuests; i++) {
				vacate(room.m_guests[i]);
			}

			delete[] room.m_guests;
			room.m_guests = nullptr;  
			
		}
		room.m_noOfGuests = 0;
		
	}
}

