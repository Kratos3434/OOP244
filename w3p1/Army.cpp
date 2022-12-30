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
#include <cstring>
#include <cstdio>
#include "Army.h"

using namespace std;

namespace sdds {
    void Army::setEmpty() {
	  nationality[0] = '\0';
	  numUnits = 0;
	  power = 0;
	  return;
    }
    void Army::createArmy(const char* country, double pow, int troops){
	  if (country && strlen(country) > 0 && pow > 0 && troops > 0) {
		strncpy(nationality, country, MAX_NAME_LEN);
		numUnits = troops;
		power = pow;
	  }
	  else setEmpty();
	  return;
    }
    void Army::updateUnits(int troops){ 
	  numUnits += troops;
	  power += (double)troops / 4.0;
	  return;
    }
    const char* Army::checkNationality() const{
	  return nationality;
    }
    int Army::checkCapacity() const{
	  return numUnits;
    }
    double Army::checkPower() const{
	  return power;
    }
    bool Army::isEmpty() const{
	  bool ok = false;
	  if (nationality[0] == '\0' && numUnits == 0 && power == 0)
		ok = true;
	  return ok;
    }
    bool Army::isStrongerThan(const Army& army)const{
	  double p1 = checkPower();
	  double p2 = army.checkPower();
	  bool powerful = false;
	  if (p1 > p2) powerful = true;
	  return powerful;
    }
void battle(Army& arm1, Army& arm2){
    if (!arm1.isEmpty() && !arm2.isEmpty()) {
	  if (arm1.isStrongerThan(arm2)) {
		printf("In battle of %s and %s, %s is victorious!\n",
		    arm1.checkNationality(), arm2.checkNationality(), arm1.checkNationality());
		arm2.updateUnits(-1 * arm2.checkCapacity() / 2);
	  }
	  else {
		printf("In battle of %s and %s, %s is victorious!\n",
		    arm1.checkNationality(), arm2.checkNationality(), arm2.checkNationality());
		arm1.updateUnits(-1 * arm1.checkCapacity() / 2);
	  }
    }
    return;
}
void displayDetails(const Army* armies, int size){
    printf("Armies reporting to battle: ");
    printf("\n");
    int i;
    for (i = 0; i < size; i++) {
	  if (!armies[i].isEmpty()) {
		cout.setf(ios::fixed);
		cout.precision(1);
		cout << "Nationality: " << armies[i].checkNationality() << ", Units Count: " 
		    << armies[i].checkCapacity() << ", Power left: " << armies[i].checkPower() << endl;

	  }
    }
    return;
}
}