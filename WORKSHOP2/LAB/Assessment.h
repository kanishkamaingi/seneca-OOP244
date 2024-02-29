/*
SUBMITTED BY:
NAME: -KANISHKA
STUDENT ID: 155238223
STUDENT EMAIL: kanishka1@myseneca.ca
SUBMISSION DATE: 28 JANUARY, 2024
*/

#ifndef SENECA_ASSESSMENT_H
#define SENECA_ASSESSMENT_H

namespace seneca
{
    struct Assessment
    {
        double *m_mark;
        char *m_title;
    };

    // Reads one integer from the fptr file into the value reference
    // and returns true if it was successful, otherwise, it will return false
    bool read(int &value, FILE *fptr);

    // Reads one double from the fptr file into the value reference
    // and returns true if it was successful, otherwise, it will return false
    bool read(double &value, FILE *fptr);

    // Skips a comma and then reads a cstring no longer than 60 characters from the fptr file into the address, cstr
    // and returns true if it was successful, otherwise, it will return false
    bool read(char *cstr, FILE *fptr);

    bool read(Assessment& assess, FILE* fptr);

    void freeMem(Assessment*& aptr, int size);

    int read(Assessment*& aptr, FILE* fptr);

}

#endif