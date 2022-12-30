/*
Name: Keith Carlos
Section: NHH
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_BAR_H
#define SDDS_BAR_H

namespace sdds {
    const int MAX_TITLE_LEN = 20;
    class Bar {
	  char title[MAX_TITLE_LEN];
	  char fillChar;
	  int sampleValue;
    public:
	  void setEmpty();
	  void set(const char* titl, char fill, int barValue);
	  bool isBarValid() const;
	  void draw() const;
    };
}
#endif // !SDDS_BAR_H
