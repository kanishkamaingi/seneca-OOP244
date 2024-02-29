/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.cpp
// Version v0.8 Oct 21st 2023
// Author  Jitesh Arora
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: -KANISHKA                 Date: FEBRUARY 18, 2024            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include "bankaccount.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>

using namespace std;

namespace seneca
{
    // Default Constructor with default arguments
    bankAccount::bankAccount(const char *name, bool checking)
    {
        m_userName[0] = '\0'; // Empty string implies is account is not open
        setup(name, checking);
    }

    // Open bank account: setup can only be done once!
    bool bankAccount::setup(const char *name, bool checking)
    {
        if (isOpen())
            return false;
        if (name == nullptr)
            return false;

        strcpy(m_userName, name);
        m_monthlyTransactions = 0;
        m_checking = checking;
        m_funds = 0;
        return true;
    }

    // Account is open if user name string is not empty
    bool bankAccount::isOpen() const
    {
        return (m_userName[0] != '\0');
    }

    bankAccount::operator bool() const
    {
        if (isOpen())
            return true;
        else
            return false;
    }

    bankAccount::operator double() const
    {
        return m_funds;
    }

    bankAccount &bankAccount::operator++()
    {

        if (isOpen() && m_funds > 0)
        {
            if (m_checking)
            {
                m_interest = m_funds * 0.005;
                m_funds += m_interest;
            }
            else
            {
                m_interest = m_funds * 0.025;
                m_funds += m_interest;
            }
        }
        return *this;
    }

    bankAccount &bankAccount::operator--()
    {
        if (isOpen())
        {
            if (m_checking)
            {
                m_fees = m_monthlyTransactions * 1.25;
                m_funds -= m_fees;
            }
            else
            {
                m_fees = m_monthlyTransactions * 3.50;
                m_funds -= m_fees;
            }
        }
        return *this;
    }

    bool bankAccount::operator+=(double amount)
    {
        if (isOpen())
        {
            m_funds += amount;
            m_monthlyTransactions++;
            cout << "Deposit $" << fixed << setprecision(2) 
                 << amount << " for " << m_userName << endl;
            return true;
        }
        return false;
    }

    bool bankAccount::operator-=(double amount)
    {
        if (isOpen())
        {
            m_funds -= amount;
            m_monthlyTransactions++;
            cout << "Withdraw $" << fixed << setprecision(2) 
                 << amount << " for " << m_userName << endl;
            return true;
        }
        return false;
    }

    bool bankAccount::operator==(const bankAccount &check) const
    {
        if (strcmp(m_userName, check.m_userName) == 0 
            && m_funds - check.m_funds < 0.001 
            && m_checking == check.m_checking)
        {
            return true;
        }
        return false;
    }

    bool bankAccount::operator>(double amount) const
    {
        if (isOpen())
        {
            if ((double)m_funds > (double)amount)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        {
            return false;
        }
    }

    bool bankAccount::operator<=(double amount) const
    {
        if (isOpen())
        {
            if ((double)m_funds <= (double)amount)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    bool bankAccount::operator<<(bankAccount &account)
    {
        if (isOpen() && account.isOpen() && account.m_funds > 0)
        {
            cout << "Transfer $" << account.m_funds << " from " 
                 << account.m_userName << " to " << m_userName << endl;
            operator+=(account.m_funds);
            account.operator-=(account.m_funds);
            return true;
        }
        return false;
    }

    void bankAccount::display(void) const
    {

        if (isOpen())
        {
            cout << "Display Account -> User:" << right << setw(16) << setfill('-') << m_userName << " | ";
            (m_checking) ? cout << "Checking" : cout << " Savings";
            cout << " | Balance: $ " << right << setw(7) << fixed << setprecision(2) << setfill(' ') << m_funds << " | "
                 << "Transactions:" << setw(3) << setfill('0') << m_monthlyTransactions << endl;
        }
        else
        {
            cout << "Display Account -> User:------- NOT OPEN" << endl;
        }
    }

    bool operator>(double lhs, const bankAccount &rhs)
    {
        if ((bool)rhs)
        {
            if (rhs.operator>((double)lhs))
            {
                return false;
            }
        }
        return true;
    }

    bool operator<=(double lhs, const bankAccount &rhs)
    {
        if ((bool)rhs)
        {

            if (rhs.operator<=((double)rhs))
            {
                return true;
            }
        }
        return false;
    }

}