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
#include "FullName.h"

using namespace std;

namespace sdds {
    FullName::FullName():Name() {
	  m_value = nullptr;
    }
    FullName::FullName(const char* name, const char* lastName):Name(name) {
	  if (lastName) {
		m_value = new char[strlen(lastName) + 1];
		strcpy(m_value, lastName);
	  }
	  else m_value = nullptr;
    }
    // Rule of three goes here:
    FullName::FullName(const FullName& fn):Name(fn) {
	  if (fn.m_value) {
		m_value = new char[strlen(fn.m_value) + 1];
		strcpy(m_value, fn.m_value);
	  }
	  else m_value = nullptr;
    }
    FullName& FullName::operator=(const FullName& fn) {
	  (Name&)*this = fn;
	  delete[] m_value;
	  m_value = nullptr;
	  if (fn.m_value) {
		m_value = new char[strlen(fn.m_value) + 1];
		strcpy(m_value, fn.m_value);
	  }
	  return *this;
    }
    FullName::~FullName() {
	  delete[] m_value;
    }

    FullName::operator const char* ()const {
	  return m_value;
    }
    FullName::operator bool() const {
	  return m_value != nullptr && (Name&)*this!=nullptr;
    }
    std::ostream& FullName::display(std::ostream& ostr)const {
	  if (*this) {
		Name::display(ostr) << " " << m_value;
	  }
	  return ostr;
    }
    std::istream& FullName::read(std::istream& istr) {
	  Name::read(istr);
	  char* temp = new char[100];
	  istr.getline(temp,100,'\n');
	  if (istr) {
		delete[] m_value;
		m_value = nullptr;
		if (temp) {
		    m_value = new char[strlen(temp) + 1];
		    strcpy(m_value, temp);
		}
	  }
	  delete[] temp;
	  return istr;
    }
}
