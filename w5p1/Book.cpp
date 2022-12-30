/*
Name: Keith Carlos
Section: NHH
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Book.h"

using namespace std;
namespace sdds {
    void Book::init_book() {
	  m_title[0] = '\0';
	  m_author[0] = '\0';
	  m_num_chapters = 0;
	  m_num_pages = 0;
    }

    Book::Book() {
	  init_book();
    }

    Book::Book(const char* title_) {
	  init_book();
	  strcpy(m_title, title_);
    }

    Book::Book(const char* title_, const char* author_, double price_) {
	  init_book();
	  strcpy(m_title, title_);
	  strcpy(m_author, author_);
	  m_price = price_;
    }

    // Print a book summary
    void Book::summary() {
	  cout.setf(ios::left);
	  cout << "| ";
	  cout.width(MAX_BOOK_TITEL);
	  cout << m_title << " | ";
	  cout.width(MAX_AUTHOR_NAME);
	  cout << m_author << " | ";
	  cout.width(3);
	  cout << m_num_chapters << "  ";
	  cout.width(4);
	  cout << m_num_pages << " | ";
	  cout.width(6);
	  cout << m_price << " |" << endl;
    }
    Book Book::operator++(int) {
	  m_num_chapters++;
	  return *this;
    }
    int Book::add_chapter(Chapter* chapter) {
	  m_chapters[m_num_chapters++] = *chapter;
	  m_num_pages += (int)*chapter;
	  return m_num_chapters;
    }
    std::ostream& Book::display(std::ostream& os) const {
	  //loop on the chapters
	  //use os <<m_chapters[i]
	  int i;
	  os <<"Title:'" << m_title << "'\n";
	  os <<"Author: '" << m_author << "'\n";
	  for (i = 0; i < m_num_chapters; i++){
             os << m_chapters[i];
	  }
	  return os;
    }
    Book::operator int() const {
	  return m_num_chapters;
    }
    Book::operator bool() const {
	  return m_title && m_title[0] != '\0' && m_author && m_author[0] != '\0' &&
		m_num_pages > 0 && (int)m_chapters[0] > 0;
    }
    Book::operator double() const {
	  return m_price;
    }
    Book::operator const char* () const {
	  return m_title;
    }

    bool Book::operator~() const {
	  return !Book();
    }

    Book& Book::operator+=(Chapter& chapter) {
	  add_chapter(&chapter);
	  return *this;
    }
    Book& Book::operator-=(double discount) {
	  m_price -= discount;
	  return *this;
    }

    std::ostream& operator<<(std::ostream& os,const Book& book) {
	  return book.display(os);
    }
}