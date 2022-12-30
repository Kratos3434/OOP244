/*
Name: Keith Carlos
Section: NHH
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#include <iostream>
#include "Streamable.h"

using namespace std;

namespace sdds {
    std::ostream& operator<<(std::ostream& os, const Streamable& S) {
	  if (S) {
		return S.write(os);
	  }
	  return os;
    }
    std::istream& operator>>(std::istream& is, Streamable& S) {
	  return S.read(is);
    }
}