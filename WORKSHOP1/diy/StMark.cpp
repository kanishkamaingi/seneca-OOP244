/*
SUBMITTED BY-
NAME: -KANISHKA
STUDENT ID: 155238223
SENECA EMAIL: KANISHKA1@MYSENECA.CA
DATE OF SUBMISSION: JANUARY 25, 2024
*/

#include <iostream>
using namespace std;

#include "io.h"
#include "graph.h"
#include "file.h"
#include "StMark.h"
#include "file.h"


namespace seneca
{
   const int GRAPH_WIDTH = 65;
   void sort(int size, struct StMark* marks)
   {
      for(int i=0; i < size-1; i++)
      {
         for(int j=0; j < size-i-1; j++)
         {
            if (marks[j].mark<marks[j+1].mark)
            {
               struct StMark temp;
               temp = marks[j];
               marks[j] = marks[j+1];
               marks[j+1] = temp;
            }
         }
      }
   }

   bool printReport(const char *filename)
   {
      int arr[10] = {0};
      bool result1 = openFile(filename);
      if (!result1)
      {
         return false;
      }

      StMark stuData[MAX_NO_RECS+1]={"unknown","unknown",0};
      int size = readMarks(stuData);
      for (int i = 0; i < size; i++)
      {
         if (stuData[i].mark <= 100 && stuData[i].mark >= 91)
         {
            arr[9]++;
         }
         else if (stuData[i].mark <= 90 && stuData[i].mark >= 81)
         {
            arr[8]++;
         }
         else if (stuData[i].mark <= 80 && stuData[i].mark >= 71)
         {
            arr[7]++;
         }
         else if (stuData[i].mark <= 70 && stuData[i].mark >= 61)
         {
            arr[6]++;
         }
         else if (stuData[i].mark <= 60 && stuData[i].mark >= 51)
         {
            arr[5]++;
         }
         else if (stuData[i].mark <= 50 && stuData[i].mark >= 41)
         {
            arr[4]++;
         }
         else if (stuData[i].mark <= 40 && stuData[i].mark >= 31)
         {
            arr[3]++;
         }
         else if (stuData[i].mark <= 30 && stuData[i].mark >= 21)
         {
            arr[2]++;
         }
         else if (stuData[i].mark <= 20 && stuData[i].mark >= 11)
         {
            arr[1]++;
         }
         else
         {
            arr[0]++;
         }
      }

      printGraph(arr, 10 , "Students' mark distribution");

      sort(size, stuData);

      for(int k=0; k<size; k++)
      {
         printf("%-3d: [%-3d] %s %s\n", k+1, stuData[k].mark, stuData[k].name, stuData[k].surname);
      }

      for (int i = 0; i < GRAPH_WIDTH - 25; cout << "-", i++)
            ;

      closeFile();
      return true;
   }
}