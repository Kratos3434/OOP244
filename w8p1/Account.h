/*
Name: Keith Carlos
Section: NHH
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_ACCOUNT_H
#define SDDS_ACCOUNT_H
#include <iostream>
#include "iAccount.h"

namespace sdds {
    class Account:public iAccount {
	  double m_currBalance{};
    public:
	  Account();
	  Account(double);
	  bool credit(double);
	  bool debit(double);
    protected:
	  double balance() const;
    };
}

#endif // !SDDS_ACCOUNT_H
