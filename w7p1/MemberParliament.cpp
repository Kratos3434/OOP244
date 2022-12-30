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
#include <iomanip>
#include "MemberParliament.h"

using namespace std;

namespace sdds {
    MemberParliament::MemberParliament(const char* id, int age) {
	  strcpy(m_idNum, id);
	  m_age = age;
	  strcpy(m_district, "Unassigned");
    }
    void MemberParliament::NewDistrict(const char* district) {
	  char oldDistrict[64];
	  strcpy(oldDistrict, m_district);
	  strcpy(m_district, district);
	  //| MP9403| |          Unassigned--->Scarborough |
	  cout << "|" << setw(8) << right << m_idNum << "| |" << setw(20) << right 
		<< oldDistrict << " ---> " << setw(23) << left << m_district << "|\n";
    }
    std::ostream& MemberParliament::write(std::ostream& os)const{
	  //| MP9566 | 40 | Milton
	  os << "| " << m_idNum << " | " << m_age << " | " << m_district;

	  return os;
    }
    std::istream& MemberParliament::read(std::istream& in) {
	  cout << "Age: ";
	  in >> m_age;
	  cout << "Id: ";
	  in >> m_idNum;
	  cout << "District: ";
	  in >> m_district;

	  return in;
    }
    std::ostream& operator<<(std::ostream& os,const MemberParliament& mp) {
	  return mp.write(os);
    }
    std::istream& operator>>(std::istream& in,MemberParliament& mp) {
	  return mp.read(in);
    }
}