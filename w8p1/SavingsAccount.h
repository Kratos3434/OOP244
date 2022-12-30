/*
Name: Keith Carlos
Section: NHH
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_SAVINGSACCOUNT_H
#define SDDS_SAVINGSACCOUNT_H
#include <iostream>
#include "Account.h"
namespace sdds {
    class SavingsAccount:public Account {
	  double m_interestRate{};
    public:
	  SavingsAccount(double, double);
	  void monthEnd();
	  void display(std::ostream&) const;
    };
}
#endif // !SDDS_SAVINGSACCOUNT_H
