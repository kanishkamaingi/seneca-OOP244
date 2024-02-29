/*
SUBMITTED BY-
NAME: -KANISHKA
STUDENT ID: 155238223
SENECA EMAIL: KANISHKA1@MYSENECA.CA
DATE OF SUBMISSION: JANUARY 25, 2024
*/

#ifndef SENECA_GRAPH_H 
#define SENECA_GRAPH_H

namespace seneca{

    
 
    // Fills the samples array with the statistic samples
    void getSamples(int samples[], int noOfSamples);

    // Finds the largest sample in the samples array, if it is larger than 70,
    // otherwise it will return 70. 
    int findMax(int samples[], int noOfSamples);

    // Prints a scaled bar relevant to the maximum value in samples array
    void printBar(int val, int max);

    // Prints a graph comparing the sample values visually 
    void printGraph(int samples[], int noOfSamples, const char* label);

}
#endif