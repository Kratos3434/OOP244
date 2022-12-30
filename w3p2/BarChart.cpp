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
#include "BarChart.h"

namespace sdds {
    void BarChart::init(const char* title, int noOfSampels, char fill) {
	   titleOfChart = new char[strlen(title) + 1];
	   strcpy(titleOfChart, title);
	   numSamples = noOfSampels;
	   addedSamples = 0;
	   FillChar = fill;
	   b = new Bar[numSamples];
    }
    void BarChart::add(const char* bar_title, int value) {
	  b[addedSamples].set(bar_title, FillChar, value);
	  addedSamples++;
    }
    bool BarChart::isValid() const {
	  bool valid = false;
	  if (addedSamples == numSamples) {
		for (int i = 0; i < numSamples; i++) {
		    if (b[i].isBarValid())
			  valid = true;
		}
	  }
	  return valid;
    }
    void BarChart::draw()const {
	  if (isValid()) {
		printf("%s\n", titleOfChart);
		printf("-----------------------------------------------------------------------\n");
		for (int i = 0; i < numSamples; i++) {
		    b[i].draw();
		}
		printf("-----------------------------------------------------------------------\n");
	  }
	  else {
		printf("Invalid Chart!\n");
	  }
	  return;
    }
    void BarChart::deallocate() {
	  delete[] titleOfChart;
	  delete[] b;
    }
}