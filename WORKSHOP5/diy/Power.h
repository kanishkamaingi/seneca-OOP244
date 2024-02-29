/***********************************************************************
// OOP244 Workshop #5 p2: tester program
//
// File	main_prof.cpp
// Version 1.0
// Author Mohammad Shamas
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// -KANISHKA       February 22, 2022
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SENECA_POWER_H
#define SENECA_POWER_H


namespace seneca {
	const int MAX_NAME_LENGTH = 50;

	class Power{
		char m_name[MAX_NAME_LENGTH + 1];
		int m_rarity;

	public:
		Power();
		Power(const char* name, int rarity);
		void setEmpty();
		void createPower(const char* name, int rarity);

		const char* checkName() const;
		int checkRarity() const;
		bool isEmpty() const;
	};
	void displayDetails(Power* powers, int size);
}
#endif
