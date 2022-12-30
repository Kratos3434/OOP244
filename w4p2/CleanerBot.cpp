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
#include "CleanerBot.h"

using namespace std;

namespace sdds {
    void CleanerBot::resetInfo() {
	  m_location = nullptr;
	  m_battery = 0;
	  m_brush = 0;
	  m_active = NULL;
    }
    CleanerBot::CleanerBot() {
	  resetInfo();
    }
    CleanerBot::CleanerBot(const char* location, double battery, int brush, bool active) {
	  if (location && battery > 0 && brush > 0) {
		m_location = new char[strlen(location) + 1];
		strcpy(m_location, location);
		m_battery = battery;
		m_brush = brush;
		m_active = active;
	  }
	  else resetInfo();
    }
    void CleanerBot::deallocate() {
	  delete[] m_location;
    }
    CleanerBot::~CleanerBot() {
	  deallocate();
    }
    CleanerBot& CleanerBot::set(const char* location, double battery, int brush, bool active) {
	  deallocate();
	  if (location && battery > 0 && brush > 0) {
		m_location = new char[strlen(location) + 1];
		strcpy(m_location, location);
		m_battery = battery;
		m_brush = brush;
		m_active = active;
	  }
	  else resetInfo();

	  return *this;
    }
    void CleanerBot::setLocation(const char* location) {
	  m_location = new char[strlen(location) + 1];
	  strcpy(m_location, location);
    }
    void CleanerBot::setActive(bool active) {
	  m_active = active;
    }
    const char* CleanerBot::getLocation() const {
	  return m_location;
    }
    double CleanerBot::getBattery() const {
	  return m_battery;
    }
    int CleanerBot::getBrush() const {
	  return m_brush;
    }
    bool CleanerBot::isActive() const {
	  return m_active;
    }
    bool CleanerBot::isValid() const {
	  bool valid = false;
	  if (m_location && m_battery > 0 && m_brush > 0)
		valid = true;
	  return valid;
    }
    bool CleanerBot::low() const {
	  return m_location && m_battery < 30 && m_brush > 0;
    }
    void displayReportHeader() {
	  cout << "         ------ Cleaner Bots Report -----\n";
	  cout << "     ---------------------------------------\n";
	  cout << "| Location   | Battery |  Number of Brushes | Active |\n";
	  cout << "|------------+---------+--------------------+--------|\n";
    }
    void displayWarningHeader(int toBeCharged) {
	  cout << "|====================================================|\n";
	  cout << "| LOW BATTERY WARNING:                               |\n";
	  cout << "|====================================================|\n";
	  cout << "| Number of robots to be charged: " << setw(19) << toBeCharged << "|\n";
	  cout << "| Sorting robots based on their available power:     |\n";
	  cout << "| Location   | Battery |  Number of Brushes | Active |\n";
	  cout << "|------------+---------+--------------------+--------|\n";
    }
    void CleanerBot::display() const{
	  //| Kitchen | 88.6 | 5 | YES |
	  cout << "| " << setw(11) << left << getLocation();
	  cout << "|" << setw(8) << right << fixed << setprecision(1) << getBattery();
	  cout << " |" << setw(19) << right << getBrush();
	  cout << " | " << setw(7) << left << (isActive() ? "YES" : "NO") << "|\n";
    }
    int sortBattery(const void* f, const void* s) {
	  const CleanerBot* first = (const CleanerBot*)f;
	  const CleanerBot* second = (const CleanerBot*)s;

	  if (first->getBattery() > second->getBattery()) return -1;
	  if (first->getBattery() < second->getBattery()) return 1;

	  return 0;
    }
    int report(CleanerBot* bot, short num_bots) {
	  int i;
	  int toBeCharged = 0;
	  displayReportHeader();
	  for (i = 0; i < num_bots; i++) {
		if (bot[i].isValid()) {
		    bot[i].display();
		}
	  }
	  cout << "\n";
	  for (i = 0; i < num_bots; i++) {
		if (bot[i].low()) {
		    toBeCharged++;//count how many bots are low in battery
		}
	  }
	  if (toBeCharged > 0) {
		displayWarningHeader(toBeCharged);
		qsort(bot, num_bots, sizeof(CleanerBot), sortBattery);//idk if it's ok to use this..
		for (i = 0; i < num_bots; i++) {
		    if (bot[i].isValid()) {
			  bot[i].display();
		    }
		}
		cout << "|====================================================|" << endl;
	  }
	 
		
	  return 0;
    }
}