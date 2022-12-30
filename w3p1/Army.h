/*
Name: Keith Carlos
Section: NNN
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_ARMY_H
#define SDDS_ARMY_H

namespace sdds {
    const int MAX_NAME_LEN = 50;
    class Army {
	  char nationality[MAX_NAME_LEN];
	  int numUnits;
	  double power;
    public:
	  //member functions
	  void setEmpty();
	  void createArmy(const char* country, double pow, int troops);;
	  void updateUnits(int troops);
	  const char* checkNationality() const;
	  int checkCapacity() const;
	  double checkPower() const;
	  bool isEmpty() const;
	  bool isStrongerThan(const Army& army)const;
    };
    void battle(Army& arm1, Army& arm2);
    void displayDetails(const Army* armies, int size);


}
#endif // !SDDS_ARMY_H
