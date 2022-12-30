/*
Name: Keith Carlos
Section: NHH
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Minister.h"

using namespace std;

namespace sdds {
    Minister::Minister(const char* id, int age, int year,const char* name,const char* district):MemberParliament(id,age) {
	  NewDistrict(district);
	  m_year = year;
	  strcpy(m_ministerName, name);
    }
    void Minister::changePM(const char* pm) {
	  strcpy(m_ministerName, pm);
    }
    void Minister::assumeOffice(double year) {
	  m_year = (int)year;
    }
    std::ostream& Minister::write(std::ostream& os) const{
	  //| [ID] | [age] | [DISTRICT] | [PM] / [Year Assumed Office]
	  MemberParliament::write(os);
	  os <<" | " << m_ministerName << "/" << m_year;
	  return os;
    }
    std::istream& Minister::read(std::istream& in) {
	  MemberParliament::read(in);
	  cout << "Reports TO: ";
	  in >> m_ministerName;
	  cout << "Year Assumed Office: ";
	  in >> m_year;

	  return in;
    }
    std::ostream& operator<<(std::ostream& os,const Minister& m) {
	  return m.write(os);
    }
    std::istream& operator>>(std::istream& in, Minister& m) {
	  return m.read(in);
    }
}