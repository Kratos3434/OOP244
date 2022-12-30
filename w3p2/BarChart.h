/*
Name: Keith Carlos
Section: NHH
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_BARCHART_H
#define SDDS_BARCHART_H
#include "Bar.h"

namespace sdds {
    class BarChart {
	  char* titleOfChart;
	  Bar* b;
	  char FillChar;
	  int barSize;
	  int numSamples;
	  int addedSamples;
    public:
	  void init(const char* title, int noOfSampels, char fill);
	  void add(const char* bar_title, int value);
	  void draw()const;
	  void deallocate();
	  bool isValid() const;

    };
}


#endif