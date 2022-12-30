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
#include "Book.h"

using namespace std;

namespace sdds {
    Book::Book():Publication() {
	  m_name = nullptr;
    }
    //Rule of Three
    Book::Book(const Book& book):Publication(book) {
	  if (book.m_name) {
		m_name = new char[strlen(book.m_name) + 1];
		strcpy(m_name, book.m_name);
	  }
	  else m_name = nullptr;
    }
    Book& Book::operator=(const Book& book) {
	  (Publication&)*this = book;
	  delete[] m_name;
	  m_name = nullptr;
	  if (book.m_name) {
		m_name = new char[strlen(book.m_name) + 1];
		strcpy(m_name, book.m_name);
	  }
	  else m_name = nullptr;
	  return *this;
    }
    Book::~Book() {
	  delete[] m_name;
    }

    char Book::type()const {
	  return 'B';
    }
    std::ostream& Book::write(std::ostream& os) const {
	  Publication::write(os);
	  if (Publication::conIO(os)) {
		os << " ";
		if (strlen(m_name) > SDDS_AUTHOR_WIDTH) {
		    for (int i = 0; i < SDDS_AUTHOR_WIDTH; i++)
			  os << m_name[i];
		}
		else {
		    os.setf(ios::left);
		    os.width(SDDS_AUTHOR_WIDTH);
		    os.fill(' ');
		    os << m_name;
		    os.unsetf(ios::left);
		}
		os << " |";
	  }
	  else {
		os << '\t';
		os << m_name;
	  }
	  return os;
    }
    std::istream& Book::read(std::istream& istr) {
	  char* name = new char[256];
	  Publication::read(istr);
	  if (Publication::conIO(istr)) {
		istr.ignore(1000, '\n');
		cout << "Author: ";
		istr.get(name, 256,'\n');
	  }
	  else {
		istr.ignore(1000, '\t');
		istr.get(name, 256, '\n');
	  }
	  if (istr) {
		delete[] m_name;
		m_name = nullptr;
		if (name) {
		    m_name = new char[strlen(name) + 1];
		    strcpy(m_name, name);
		}
	  }
	  delete[] name;
	  return istr;
    }
    void Book::set(int member_id) {
	  Publication::set(member_id);
	  Publication::resetDate();
    }
    Book::operator bool() const {
	  return m_name != nullptr && Publication::operator bool();
    }
}