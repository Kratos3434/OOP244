/*
Name: Keith Carlos
Section: NHH
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_CHEQUINGACCOUNT_H
#define SDDS_CHEQUINGACCOUNT_H
#include <iostream>
#include "Account.h"

namespace sdds {
    class ChequingAccount :public Account {
	  double m_transacFee{};
	  double m_monthlyFee{};
    public:
	  ChequingAccount(double, double, double);
	  bool credit(double);
	  bool debit(double);
	  void monthEnd();
	  void display(std::ostream&) const;
    };
}
#endif // !SDDS_CHEQUINGACCOUNT_H
