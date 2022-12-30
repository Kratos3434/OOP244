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
#include "Name.h"

using namespace std;

namespace sdds {
    Name::Name() {
	  m_value = nullptr;
    }
    Name::Name(const char* name) {
	  if (name) {
		m_value = new char[strlen(name) + 1];
		strcpy(m_value, name);
	  }
	  else m_value = nullptr;
    }
    // Rule of three goes here:
    Name::Name(const Name& name) {
	  if (name.m_value) {
		m_value = new char[strlen(name) + 1];
		strcpy(m_value, name);
	  }
	  else m_value = nullptr;
    }
    Name& Name::operator=(const Name& name) {
	  delete[] m_value;
	  m_value = nullptr;
	  if (name.m_value) {
		m_value = new char[strlen(name) + 1];
		strcpy(m_value, name);
	  }
	  return *this;
    }
    Name::~Name() {
	  delete[] m_value;
    }

    Name::operator const char* ()const {
	  return m_value;
    }
    Name::operator bool()const {
	  return m_value != nullptr;
    }
    std::ostream& Name::display(std::ostream& ostr)const {
	  if (*this) {
		ostr << m_value;
	  }
	  return ostr;
    }
    std::istream& Name::read(std::istream& istr) {
	  char* temp = new char[100];
	  istr >> temp;
	  if (istr) {
		delete[] m_value;
		m_value = nullptr;
		if (temp) {
		    m_value = new char[strlen(temp) + 1];
		    strcpy(m_value, temp);
		    istr.ignore();
		}
	  }
	  delete[] temp;
	  return istr;
    }
    std::ostream& operator<<(std::ostream& ostr, const Name& name) {
	  return name.display(ostr);
    }
    std::istream& operator>>(std::istream& istr, Name& name) {
	  return name.read(istr);
    }
}