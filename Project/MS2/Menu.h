/*
Name: Keith Carlos
Section: NHH
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>

namespace sdds {
    const unsigned int MAX_MENU_ITEMS = 20;
    class Menu;
    class MenuItem {
	  char* m_desc{};
	  void setEmpty();
	  MenuItem();
	  MenuItem(const char* title);
	  MenuItem(const MenuItem& mi) = delete;
	  void operator=(const MenuItem& mi) = delete;
	  ~MenuItem();
	  std::ostream& display(std::ostream& os = std::cout)const;
	  operator bool() const;
	  operator const char* () const;
	  bool isEmpty() const;
	  friend Menu;
    };
    class Menu {
	  MenuItem m_title;
	  MenuItem* m_items[MAX_MENU_ITEMS]{};
	  unsigned int m_ni;
	  std::ostream& display(std::ostream& os = std::cout)const;
    public:
	  Menu(const char* title = "");
	  ~Menu();
	  Menu(const Menu& menu) = delete;
	  void operator=(const Menu& menu) = delete;
	  Menu& operator<<(const char* menuitem);
	  operator bool()const;
	  unsigned int run() const;
	  operator unsigned int() const;
	  operator int() const;
	  unsigned int operator~()const;
	  const char* operator[](unsigned int index) const;
	  std::ostream& displayTitle(std::ostream& os)const;
    };
    std::ostream& operator<<(std::ostream& os, const Menu& m);
}


#endif // !SDDS_MENU_H