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
#include <cstdio>
#include "Bar.h"

using namespace std;

namespace sdds {
    void Bar::setEmpty() {
	  title[0] = '\0';
	  fillChar = '\0';
	  sampleValue = 0;
	  return;
    }
    void Bar::set(const char* titl, char fill, int barValue) {
	  if (barValue > 0 || barValue <= 100) {
		strncpy(title, titl, MAX_TITLE_LEN);
		fillChar = fill;
		sampleValue = barValue;
	  }
	  else setEmpty();
	  return;
    }
    bool Bar::isBarValid() const{
	  bool valid = false;
	  if (sampleValue > 0 && sampleValue <= 100)
		valid = true;
	  return valid;
    }
    void Bar::draw() const {
	  int i;
	  if(isBarValid()){
		cout.setf(ios::fixed);
		cout.fill('.');
		cout.width(MAX_TITLE_LEN);
		cout << left << title
		    << '|';
		for (i = 0; i < sampleValue / 2; i++) {
		    cout << fillChar;
		}
		printf("\n");
	  }
    }
    
}