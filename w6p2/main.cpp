// Workshop 6: Classes with Resources
// Version: 1.0
// Author: Nargis Khan, Cornel Barna
// Description:
// This file tests lab section of your workshop
/////////////////////////////////////////////

#include<iostream>
#include<cstring>
#include"Basket.h"
#include"Basket.h" //intentional

using namespace std;
using namespace sdds;

void printHeader(const char* title)
{
    char oldFill = cout.fill('-');
    cout.width(40);
    cout << "" << endl;

    cout << "|> " << title << endl;

    cout.fill('-');
    cout.width(40);
    cout << "" << endl;
    cout.fill(oldFill);
}

int main()
{
    sdds::Fruit fruits[]{
	    {"apple",  0.65},
	    {"banana", 1.25},
	    {"pear",   0.50},
	    {"mango",  0.75},
	    {"plum",   2.00},
    };

    {
	  printHeader("T1: Default Constructor");

	  Basket aBasket;
	  cout << aBasket;

	  // conversion to bool operator
	  if (aBasket)
		cout << "Test failed: the basket should be empty!\n";
	  else
		cout << "Test succeeded: operator said the basket is empty!\n";

	  cout << endl;
    }

    {
	  printHeader("T2: Custom Constructor");

	  Basket aBasket(fruits, 2, 6.99);
	  cout << aBasket;

	  // conversion to bool operator
	  if (aBasket)
		cout << "Test succeeded: operator said the basket has content!\n";
	  else
		cout << "Test failed: the basket should NOT be empty!\n";

	  cout << endl;
    }

    {
	  printHeader("T3: += operator");

	  Basket aBasket;
	  aBasket += fruits[2];
	  (aBasket += fruits[0]) += fruits[4];
	  aBasket.setPrice(12.234);

	  cout << aBasket;
	  cout << endl;
    }

    {
	  printHeader("T4: Copy Constructor");

	  Basket b1;
	  Basket b2(b1);

	  cout << "Basket #1 -> " << b1;
	  cout << "Basket #2 -> " << b2;

	  b1 += fruits[3];
	  b1.setPrice(3.50);

	  Basket b3(b1);
	  cout << "Basket #3 -> " << b3;
	  cout << endl;
    }

    {
	  printHeader("T5: Copy Assignment");

	  Basket b1, b2, b3(fruits, 5, 19.95);

	  b1 = b2;
	  cout << "Basket #1 -> " << b1;
	  cout << "Basket #2 -> " << b2;

	  b1 = b3;
	  cout << "Basket #1 -> " << b1;

	  b3 = b2;
	  cout << "Basket #3 -> " << b3;
    }

    return 0;
}