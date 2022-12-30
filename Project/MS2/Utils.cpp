/***********************************************************************
// OOP244 Utils Module:
// File  utils.cpp
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
/*
Name: Keith Carlos
Section: NHH
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/
#include <iostream>
using namespace std;
#include "Utils.h"
namespace sdds {
    int inputIntRange(int minRange, int maxRange) {
        int i;
        bool fail;
        do {
            cin >> i;
            fail = cin.fail();
            if (fail) {
                cout << "Invalid Selection, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else if (i<minRange || i>maxRange) {
                cout << "Invalid Selection, try again: ";
                cin.clear();
            }
        } while (i<minRange || i>maxRange || fail);
        cin.clear();
        return i;
    }
}