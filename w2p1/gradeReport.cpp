/*
Name: Keith Carlos
Section: NNN
Email: kwcarlos@myseneca.ca
Student ID: 127638211
*/

/* ------------------------------------------------------
Workshop 2 part 1
Module: N/A
Filename: gradeReport.cpp
  in submission this file will be replaced with main_prof.cpp
  that loads "simpsons.csv" instead
Version 1
Revision History
-----------------------------------------------------------
Date       Reason
-----------------------------------------------------------*/
#include "Student.h"
using namespace sdds;
int main() {
    if (load("simpsons.csv")) {
        display();
    }
    deallocateMemory();
    return 0;
}