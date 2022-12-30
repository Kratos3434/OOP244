/*
Name: Keith Carlos
Section: NHH
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_HERO_H
#define SDDS_HERO_H
#include <iostream>
#include "Power.h"

namespace sdds {
    class Hero {
	  char heroName[MAX_NAME_LENGTH];
	  Power* powerList;
	  int numPowers;
	  int powerLevel;
	  void setEmpty();
    public:
	  Hero();
	  Hero(const char* name, Power* power, int numPower);
	  std::ostream& display(std::ostream& ostr = std::cout) const;
	  Hero& operator+=(Power&);
	  Hero& operator-=(int);
	  void deallocate();
	  ~Hero();
	  int getPowerLevel() const;
    };
    bool operator<(Hero& hero1,Hero& hero2);
    bool operator>(Hero& hero1,Hero& hero2);
    void operator>>(Power&, Hero&);
    void operator<<(Hero&, Power&);
    std::ostream& operator<<(std::ostream& os, const Hero& hero);
}

#endif