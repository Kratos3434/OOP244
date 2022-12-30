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
#include "Menu.h"
#include "Utils.h"

using namespace std;

namespace sdds {
    void MenuItem::setEmpty() {
	  m_desc = nullptr;
    }
    MenuItem::MenuItem() { setEmpty(); }
    MenuItem::MenuItem(const char* title) {
	  if (title) {
		m_desc = new char[strlen(title) + 1];
		strcpy(m_desc, title);
	  }
	  else setEmpty();
    }
    MenuItem::~MenuItem() {
	  delete[] m_desc;
    }
    std::ostream& MenuItem::display(std::ostream& os)const {
	  if (!isEmpty()) os << m_desc;
	  return os;
    }
    bool MenuItem::isEmpty() const {
	  return m_desc == nullptr || m_desc[0] == '\0';
    }
    MenuItem::operator bool() const {
	  return !isEmpty();
    }
    MenuItem::operator const char* () const {
	  return m_desc;
    }
    std::ostream& Menu::displayTitle(std::ostream& os)const {
	  m_title.display(os);
	  return os;
    }
    std::ostream& Menu::display(std::ostream& os)const {
	  displayTitle(os);
	  if (m_title) os << "\n";
	  for (unsigned int i = 0; i < m_ni; i++) {
		os << setfill(' ') << setw(2) << i + 1 << "- ";
		m_items[i]->display() << "\n";
	  }
	  os << " 0- Exit\n";
	  os << "> ";
	  return os;
    }
    Menu::Menu(const char* title) {
	  m_title.m_desc = new char[strlen(title) + 1];
	  strcpy(m_title.m_desc, title);
	  m_ni = 0;
    }
    Menu::~Menu() {
	  for (unsigned int i = 0; i < m_ni; i++) {
		delete m_items[i];
	  }
    }
    Menu& Menu::operator<<(const char* menuitem) {
	  if (m_ni != MAX_MENU_ITEMS) {
		m_items[m_ni] = new MenuItem(menuitem);
		m_ni++;
	  }
	  return *this;
    }
    Menu::operator bool()const {
	  return m_ni > 0;
    }
    unsigned int Menu::run() const {
	  display();
	  int selection = inputIntRange(0, m_ni);
	  return selection;
    }
    Menu::operator unsigned int() const {
	  return m_ni;
    }
    Menu::operator int() const {
	  return m_ni;
    }
    unsigned int Menu::operator~()const {
	  display();
	  int selection = inputIntRange(0, m_ni);
	  return selection;
    }
    std::ostream& operator<<(std::ostream& os, const Menu& m) {
	  return m.displayTitle(os);
    }
    const char* Menu::operator[](unsigned int index) const {
	  if (index <= m_ni) return m_items[index]->m_desc;
	  return m_items[index % m_ni]->m_desc;
    }
}