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
#include "Basket.h"

using namespace std;

namespace sdds {
    void Basket::setEmpty() {
	  m_fruits = nullptr;
	  m_cnt = 0;
	  m_price = 0;
    }
    Basket::Basket() {
	  setEmpty();
    }
    Basket::Basket(Fruit* fruit, int size, double price) {
	  if (fruit && size > 0 && price > 0) {
		m_cnt = size;
		m_fruits = new Fruit[size + 1];
		for (int i = 0; i < size; i++) {
		    m_fruits[i] = fruit[i];
		}
		m_price = price;
	  }
	  else setEmpty();
    }
    Basket::Basket(const Basket& basket) {
	  setEmpty();
	  (*this) = basket;
    }
    Basket& Basket::operator=(const Basket& basket) {
	  deallocate();
	  m_fruits = new Fruit[basket.m_cnt];
	  m_cnt = basket.m_cnt;
	  for (int i = 0; i < m_cnt; i++)
		m_fruits[i] = basket.m_fruits[i];
	  m_price = basket.m_price;
	  return *this;

    }
    void Basket::deallocate() {
	  delete[] m_fruits;
    }
    Basket::~Basket() {
	  deallocate();
    }
    void Basket::setPrice(double price) {
	  m_price += price;
    }
    bool Basket::isEmpty() const{
	  return m_fruits == nullptr || m_price == 0;
    }
    Basket::operator bool() const {
	  return !isEmpty();
    }
    Basket& Basket::operator+=(Fruit& fruit) {
		Fruit* temp;
		temp = new Fruit[m_cnt + 1];
		for (int i = 0; i < m_cnt; i++)
		    temp[i] = m_fruits[i];
		deallocate();
		m_fruits = temp;
		m_fruits[m_cnt] = fruit;
		m_cnt++;
	  return *this;
    }
    std::ostream& Basket::display(std::ostream& os) const {
	  if (isEmpty()) os << "The basket is empty!\n";
	  else {
		os << "Basket Content:\n";
		for (int i = 0; i < m_cnt; i++) {
		    os << setw(10) << m_fruits[i].m_name << ": " << fixed << setprecision(2) << m_fruits[i].m_qty << "kg\n";
		}
		os << "Price: " << m_price << "\n";
	  }
	  return os;
    }
    std::ostream& operator<<(std::ostream& os, Basket& basket) {
	  return basket.display(os);
    }
}