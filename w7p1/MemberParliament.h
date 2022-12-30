/*
Name: Keith Carlos
Section: NHH
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_MEMBERPARLIAMENT_H
#define SDDS_MEMBERPARLIAMENT_H

#include <iostream>

namespace sdds {
    class MemberParliament {
	  char m_idNum[32];
	  char m_district[64];
	  int m_age;
    public:
	  MemberParliament(const char* id, int age);
	  void NewDistrict(const char* district);
	  std::ostream& write(std::ostream& os) const;
	  std::istream& read(std::istream& in);
    };
    std::ostream& operator<<(std::ostream& os,const MemberParliament& mp);
    std::istream& operator>>(std::istream& in,MemberParliament& mp);
}



#endif
