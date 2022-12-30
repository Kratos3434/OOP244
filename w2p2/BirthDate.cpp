/*
Name: Keith Carlos
Section: NNN
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor 
provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include "BirthDate.h"

using namespace std;

namespace sdds {
    Employee* employees;
    FILE* fptr;
    int numEmployees,matches=0;
    bool openFile(const char filename[]) {
	  fptr = fopen(filename, "r");
	  return fptr != NULL;
    }
    bool beginSearch(const char* filename) {
	  bool ok = false;
	  if (openFile(filename)) {
		cout << "Birthdate search program" << endl;
		ok = true;
	  }
	  else printf("Data file %s not found!\n",filename);
	  return ok;
    }
    void sort() {
	  int i, j;
	  Employee temp;
	  for (i = matches - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
		    if (employees[j].year > employees[j + 1].year) {
			  temp = employees[j];
			  employees[j] = employees[j + 1];
			  employees[j + 1] = temp;
		    }
		}
	  }
    }
    int noOfMatches(int month) {
	  char name[31];
	  int y, m, d,matches = 0;
	  while (fscanf(fptr, "%[^,],%d/%d/%d\n", name, &m, &d, &y) != -1) {
		matches += (m == month);
	  }
	  rewind(fptr);
	  return matches;
    }
    bool readBirthDate(int month) {
	  bool ok = false;
	  int i = 0, y, m, d;
	  char name[31]="\0";
	  matches = noOfMatches(month);
	  employees = new Employee[matches];
	  if (matches > 0) {
		while (fscanf(fptr, "%[^,],%d/%d/%d\n", name,&m, &d, &y) !=-1 && i<matches) {
		    if (m==month) {
				employees[i].name = new char[strlen(name) + 1];
				strcpy(employees[i].name, name);
				employees[i].month = m;
				employees[i].day = d;
				employees[i].year = y;
				i++;
				ok = true;
		    }
		}
	  }
	  rewind(fptr);
	  return ok;
    }
    void displayBirthdays() {
	  int i;
	  printf("%d birthdates found:\n", matches);
	  for (i = 0; i < matches; i++) {
		printf("%d) %s:\n%d-%d-%d\n", i+1,employees[i].name, 
		    employees[i].year, employees[i].month, employees[i].day);
		printf("===================================\n");
	  }
	  
	  return;
    }
    void deallocate() {
	  for (int i = 0; i < matches; i++) {
		delete[] employees[i].name;
	  }
	  delete[] employees;
    }
    void closeFile() {
	  if (fptr) fclose(fptr);
    }
    void endSearch() {
	  closeFile();
	  printf("Birthdate Search Program Closed.\n");
	  return;
    }
}