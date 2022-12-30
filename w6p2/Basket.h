/*
Name: Keith Carlos
Section: NHH
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H

#include <iostream>

namespace sdds {
    struct Fruit
    {
	  char m_name[30 + 1]; // the name of the fruit
	  double m_qty;        // quantity in kilograms
    };
    class Basket {
	  Fruit* m_fruits;
	  int m_cnt;
	  double m_price;
	  void setEmpty();
    public:
	  Basket();
	  Basket(Fruit* fruit, int size, double price);
	  Basket(const Basket& basket);
	  Basket& operator=(const Basket& basket);
	  void deallocate();
	  ~Basket();
	  void setPrice(double price);
	  operator bool() const;
	  Basket& operator+=(Fruit& fruit);
	  std::ostream& display(std::ostream& os) const;
	  bool isEmpty() const;

    };
    std::ostream& operator<<(std::ostream& os, Basket& basket);
}

#endif