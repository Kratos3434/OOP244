/*
Name: Keith Carlos
Section: NHH
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_MINISTER_H
#define SDDS_MINISTER_H

#include <iostream>
#include "MemberParliament.h"

namespace sdds {
    class Minister:public MemberParliament {
	  char m_ministerName[50];
	  int m_year;
    public:
	  Minister(const char* id, int age, int year,const char* district,const char* name);
	  void changePM(const char* pm);
	  void assumeOffice(double year);
	  std::ostream& write(std::ostream& os)const;
	  std::istream& read(std::istream& in);
    };
    std::ostream& operator<<(std::ostream& os,const Minister& m);
    std::istream& operator>>(std::istream& in, Minister& m);
}
#endif // !SDDS_MINISTER_H
