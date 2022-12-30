/*
Name: Keith Carlos
Section: NHH
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"

using namespace std;

namespace sdds {
    SavingsAccount::SavingsAccount(double initBalance, double interestRate) {
	  credit(initBalance);
	  if (interestRate < 0) m_interestRate = 0.0;
	  else m_interestRate = interestRate;
    }
    void SavingsAccount::monthEnd() {
	  double interest = balance() * m_interestRate;
	  credit(interest);
    }
    void SavingsAccount::display(std::ostream& os) const {
	  os << "Account type: Savings\n";
	  os << "Balance: $" << fixed << setprecision(2) << balance() << "\n";
	  os << "Interest Rate (%): " << fixed << setprecision(2) << m_interestRate * 100 << "\n";

    }
}