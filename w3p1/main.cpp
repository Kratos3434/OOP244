/* ------------------------------------------------------
Workshop 3 part 1
Module: N/A
Autor: Mohammad Shamas
Filename: main.cpp
Version 1.0
-------------------------------------------------------*/

#include <iostream>
#include "Army.h"
using namespace std;
using namespace sdds;

int main() {

    Army armies[6]{};

    armies[0].createArmy("Atlantis", 500.5, 1000);
    armies[1].createArmy("", 100.0, 100);
    armies[2].createArmy("Ambrosia", 215.0, 520);
    armies[3].createArmy("United States of Auradon", 220.5, 751);
    armies[4].createArmy("Azmenistan", 250.0, 750);
    armies[5].createArmy(nullptr, 250.5, 750);

    //Test 1
    cout << "----------------------------------------" << endl;
    cout << "1. Testing the validation logic." << endl;
    cout << "(only 4 armies should be valid (0,2,3,4) )" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < 6; i++)
    {
	  cout << "armies[" << i << "]: "
		<< (armies[i].isEmpty() ? "not valid" : "valid") << endl;
    }
    cout << "----------------------------------------" << endl << endl;
    //Test 2
    cout << "----------------------------------------" << endl;
    cout << "2. Testing the display function." << endl;
    cout << "----------------------------------------" << endl;
    displayDetails(armies, 6);
    cout << "----------------------------------------" << endl << endl;
    // Test 3
    cout << "----------------------------------------" << endl;
    cout << "3. Testing the member functions without the update." << endl;
    cout << "----------------------------------------" << endl;
    Army backup;
    backup.createArmy("Foreigners", 100, 100);
    cout << backup.checkNationality()
	  << ','
	  << backup.checkCapacity()
	  << ','
	  << backup.checkPower() << endl;
    cout << "----------------------------------------" << endl << endl;
    // Test 4
    cout << "----------------------------------------" << endl;
    cout << "4. Testing the member functions with the update." << endl;
    cout << "----------------------------------------" << endl;
    backup.updateUnits(100);
    cout << backup.checkNationality()
	  << ','
	  << backup.checkCapacity()
	  << ','
	  << backup.checkPower() << endl;
    cout << "----------------------------------------" << endl << endl;
    // Test 5
    cout << "----------------------------------------" << endl;
    cout << "5. Testing the battle function." << endl;
    cout << "----------------------------------------" << endl;
    battle(armies[0], armies[2]);
    battle(armies[3], armies[4]);
    displayDetails(armies, 6);
    cout << "----------------------------------------" << endl << endl;
    return 0;
}