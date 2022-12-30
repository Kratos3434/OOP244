/*
Name: Keith Carlos
Section: NHH
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include "Publication.h"
#include "Lib.h"

namespace sdds {
    class Book:public Publication {
	  char* m_name{};
    public:
	  Book();
	  //Rule of Three
	  Book(const Book& book);
	  Book& operator=(const Book& book);
	  ~Book();

	  char type()const;
	  std::ostream& write(std::ostream& os) const;
	  std::istream& read(std::istream& istr);
	  void set(int member_id);
	  operator bool() const;
    };
}
#endif // !SDDS_BOOK_H
