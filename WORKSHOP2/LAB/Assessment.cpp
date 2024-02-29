/*
SUBMITTED BY:
NAME: -KANISHKA
STUDENT ID: 155238223
STUDENT EMAIL: kanishka1@myseneca.ca
SUBMISSION DATE: 28 JANUARY, 2024
*/

#include <iostream>
#include<string.h>
using namespace std;
#include "Assessment.h"

namespace seneca
{
    #define MAX_CHARS 60
    bool read(int &value, FILE *fptr)
    {
        int result = fscanf(fptr, "%d", &value);
        return result == 1;
    }

    bool read(double &value, FILE *fptr)
    {
        int result = fscanf(fptr, "%lf", &value);
        return result == 1;
    }

    bool read(char *cstr, FILE *fptr)
    {
        int result = fscanf(fptr, ",%60[^\n]\n", cstr);
        return result == 1;
    }

    bool read(Assessment& assess, FILE* fptr)
    {
        double tempMarks{};
        char tempString[MAX_CHARS+1];

        if (!read(tempMarks, fptr))  return false;

        if (!read(tempString, fptr)) return false;

        assess.m_mark = new double;
        *assess.m_mark = tempMarks;

        assess.m_title = new char[strlen(tempString)+1];
        strcpy(assess.m_title, tempString);

        return true;
        

    }

    void freeMem(Assessment*& aptr, int size)
    {
        int i;
        for(i=0; i<size; i++)
        {
            delete aptr[i].m_mark;
            delete[] aptr[i].m_title;
        }

        delete[] aptr;
        aptr = nullptr;
    }

    int read(Assessment*& aptr, FILE* fptr)
    {
        int numRecords{};

        read(numRecords, fptr);

        aptr = new Assessment[numRecords];
        bool temp =1;
        int numReads{};

        for(int i=0; i<numRecords && temp; i++)
        {
            temp = read(aptr[i], fptr);
            if(temp) numReads++;

        }

        if (numReads != numRecords)
        {
            freeMem(aptr, numReads);
            return 0;
        }
        
        return numReads;
        
    }

}
