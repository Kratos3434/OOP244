/*
Name: Keith Carlos
Section: NHH
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#include <iostream>
#include "Account.h"

using namespace std;

namespace sdds {
    Account::Account() { m_currBalance = 0.0; }
    Account::Account(double amount) {
	  if (amount < 0 || amount == '\0')
		m_currBalance = 0.0;
	  else m_currBalance = amount;
    }
    bool Account::credit(double toBeAdded) {
	  bool succeed = false;
	  if (toBeAdded > -1) {
		succeed = true;
		m_currBalance += toBeAdded;
	  }
	  return succeed;
    }
    bool Account::debit(double toBeSubtracted) {
	  bool succeed = false;
	  if (toBeSubtracted > -1) {
		succeed = true;
		m_currBalance -= toBeSubtracted;
	  }
	  return succeed;
    }

    double Account::balance() const {
	  return m_currBalance;
    }
}