/***********************************************************************
// OOP244 Workshop #4 p2: tester program
//
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Vanshaj         
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Guitar.h"
using namespace std;

namespace seneca{
   const char* GuitarStr::material() const {
      return m_material;
   }
   double GuitarStr::gauge() const {
      return m_gauge;
   }
   GuitarStr::GuitarStr() {};

   GuitarStr::GuitarStr(const char* ma, double ga) {
      strncpy(m_material, ma, MAT_LEN);
      m_gauge = ga;
   };

      Guitar::Guitar(const char* mod){
         strcpy(m_model,mod);
         m_strings = nullptr;
         m_numStrings = 0;
      }

      Guitar::Guitar(GuitarStr strs[], int ns, const char* mod){
         if( ns <= 0){
            Guitar();
         }
         else{
            m_strings = new GuitarStr[ns+1];
            for(int i = 0; i < ns; i++)
            {
               m_strings[i] = strs[i];
            }
            m_numStrings = ns;  
            strcpy(m_model, mod);
         }


      }
      Guitar::~Guitar(){
         delete[] m_strings;
         m_strings = nullptr;

      }

      bool Guitar::changeString(const GuitarStr& gs, int sn){
         if( sn < m_numStrings){
            m_strings[sn] = gs;
            return true;
         }
         return false;
      }

      void Guitar::reString(GuitarStr strs[], int ns){
         delete[] m_strings;
         // m_strings = nullptr;
         Guitar();
         m_strings = new GuitarStr[ns+1];
            for(int i = 0; i < ns; i++)
            {
               m_strings[i] = strs[i];
            }
            m_numStrings = ns;  
      }

      void Guitar::deString(){
         delete[] m_strings;
         m_numStrings = 0;
         m_strings = nullptr;
      }

      bool Guitar::strung() const{
         if(m_numStrings)
         {
            return true;
         }
         return false;
      }

      bool Guitar::matchGauge(double ga) const{
         for(int i = 0; i < m_numStrings; i++){
            if(m_strings[i].gauge() == ga )
            {
               return true;
            } 
         }
         return false;
      }

      std::ostream& Guitar::display(std::ostream& os) const{
         if(m_strings == nullptr){
            os<<"***Empty Guitar***"<<endl;
            return os;
         }

         os<<"Guitar Model: "<<m_model<<endl;
         os<<"Strings: "<<m_numStrings<<endl;

         if(strung()){
            for(int i = 0; i < m_numStrings ; i++){
               os << "#" << setw(2) <<left<< i + 1 << setw(10) << m_strings[i].material() 
               << " | " << fixed << setprecision(1) << m_strings[i].gauge() << endl;
            }
         }
         return os;
      }
}
