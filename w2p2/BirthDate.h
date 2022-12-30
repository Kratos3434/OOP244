/*
Name: Keith Carlos
Section: NNN
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_BIRTHDATE_H_
#define SDDS_BIRTHDATE_H_

namespace sdds {
    struct Employee {
	  char* name;
	  int month;
	  int day;
	  int year;
    };

    bool beginSearch(const char* filename);
    bool readBirthDate(int month);
    void sort();
    void displayBirthdays();
    void deallocate();
    void endSearch();
    int noOfMatches(int month);

    bool openFile(const char filename[]);
    void closeFile();
}

#endif