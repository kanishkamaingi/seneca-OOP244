/*
SUBMITTED BY-
NAME: -KANISHKA
STUDENT ID: 155238223
SENECA EMAIL: KANISHKA1@MYSENECA.CA
DATE OF SUBMISSION: JANUARY 21, 2024
*/


#ifndef SENECA_IO_H 
#define SENECA_IO_H
namespace seneca{

    // const int MAX_NO_OF_SAMPLES = 20; 
    // const int GRAPH_WIDTH = 65;

    
    void printInt(int value, int fieldWidth);
    
    // returns number of digits in an integer
    int intDigits(int value);
    
    // Performs a fool-proof integer entry assuming the user will only enter numeric values.
    // if the user enters non digit values, the function will hang in an endless loop.
    int getInt(int min, int max);
    
    // moves the cursor backwards
    void goBack(int n);
    
    // displays the user interface menu
    int menu(int noOfSamples);
    
    // Draws a line and adds a label
    void labelLine(int n, const char* label);
    
    // Draws a line
    void line(int n);
}
#endif