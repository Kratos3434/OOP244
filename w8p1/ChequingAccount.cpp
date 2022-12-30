/*
Name: Keith Carlos
Section: NHH
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#include <iostream>
#include "ChequingAccount.h"

using namespace std;

namespace sdds {
    ChequingAccount::ChequingAccount(double initBalance, double transacFee, double monthEndFee) {
	  credit(initBalance);
	  if (transacFee > -1) m_transacFee = transacFee;
	  else m_transacFee = 0.0;
	  if (monthEndFee > -1) m_monthlyFee = monthEndFee;
	  else m_monthlyFee = 0.0;
    }
    bool ChequingAccount::credit(double addBalance) {
	  bool succeed = false;
	  if (Account::credit(addBalance)) {
		Account::debit(m_transacFee);
		succeed = true;
	  }
	  return succeed;
    }
    bool ChequingAccount::debit(double debitBalance) {
	  bool succeed = false;
	  if (Account::debit(debitBalance)) {
		Account::debit(m_transacFee);
		succeed = true;
	  }
	  return succeed;
    }
    void ChequingAccount::monthEnd() {
	  Account::debit(m_monthlyFee);
    }
    void ChequingAccount::display(std::ostream& os) const {
	  os << "Account type: Chequing\n";
	  os << "Balance: $" << balance() << "\n";
	  os << "Per Transaction Fee: " << m_transacFee << "\n";
	  os << "Monthly Fee: " << m_monthlyFee << "\n";
    }
}