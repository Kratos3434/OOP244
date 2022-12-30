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
#include "Hero.h"


namespace sdds {
    void Hero::setEmpty() {
	  heroName[0] = '\0';
	  numPowers = 0;
	  powerLevel = 0;
	  powerList = nullptr;
    }
    Hero::Hero() {
	  setEmpty();
    }
    Hero::Hero(const char* name, Power* power, int numPower) {
	  int i, raritySum = 0;
	  setEmpty();
	  strcpy(heroName, name);
	  numPowers = numPower;
	  powerList = new Power[numPower];
	  for (i = 0; i < numPowers; i++) {
		powerList[i] = power[i];
	  }
	  for (i = 0; i < numPowers; i++) {
		raritySum += powerList[i].checkRarity();
	  }
	  powerLevel = raritySum * numPowers;
    }
    void Hero::deallocate() {
	  delete[] powerList;
    }
    Hero::~Hero() {
	  deallocate();
    }
    std::ostream& Hero::display(std::ostream& ostr) const {
	  int i;
	  ostr << "Name: " << heroName << "\n";
	  ostr << "List of available powers: ";
          ostr<<"\n";
	  for (i = 0; i < numPowers; i++) {
		ostr << "  Name: " << powerList[i].checkName() << ", Rarity: " << powerList[i].checkRarity() << "\n";
	  }
	  ostr << "Power Level: " << powerLevel;
	  return ostr;
    }
    Hero& Hero::operator+=(Power& power) {
	  int i,raritySum = 0;
	  Power* temp;
	  temp = new Power[numPowers];
	  for (i = 0; i < numPowers; i++) {
		temp[i] = powerList[i];
	  }
	  deallocate();
	  numPowers++;
	  powerList = new Power[numPowers];
	  for (i = 0; i < numPowers-1; i++) {
		powerList[i] = temp[i];
	  }
	  powerList[numPowers-1] = power;
	  for (i = 0; i < numPowers; i++) {
		raritySum += powerList[i].checkRarity();
	  }
	  powerLevel = raritySum * numPowers;
          delete[] temp;
	  return *this;
    }
    Hero& Hero::operator-=(int num) {
	  powerLevel -= num;
	  return *this;
    }
    int Hero::getPowerLevel() const {
	  return powerLevel;
    }
    bool operator<(Hero& hero1, Hero& hero2) {
	  bool isLessThan = false;
	  if (hero1.getPowerLevel() < hero2.getPowerLevel())
		isLessThan = true;
	  return isLessThan;
    }
    bool operator>(Hero& hero1, Hero& hero2) {
	  bool isGreaterThan = false;
	  if (hero1.getPowerLevel() > hero2.getPowerLevel())
		isGreaterThan = true;
	  return isGreaterThan;
    }
    void operator>>(Power& power, Hero& hero) {
	  hero += power;
    }
    void operator<<(Hero& hero, Power& power) {
	  hero += power;
    }
    std::ostream& operator<<(std::ostream& os, const Hero& hero) {
	  return hero.display(os);
    }
   
}

