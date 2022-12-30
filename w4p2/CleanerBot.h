/*
Name: Keith Carlos
Section: NHH
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_CLEANERBOT_H
#define SDDS_CLEANERBOT_H


namespace sdds {
    class CleanerBot {
	  char* m_location;
	  double m_battery;
	  int m_brush;
	  bool m_active;
	  void resetInfo();
    public:
	  CleanerBot();
	  CleanerBot(const char* location, double battery, int brush, bool active);
	  ~CleanerBot();
	  CleanerBot& set(const char* location, double battery, int brush, bool active);
	  void setLocation(const char* location);
	  void setActive(bool active);
	  const char* getLocation() const;
	  double getBattery() const;
	  int getBrush() const;
	  bool isActive() const;
	  bool isValid() const;
	  void display() const;
	  bool low() const;
	  void deallocate();
	  
    };
    void displayReportHeader();
    void displayWarningHeader(int toBeCharged);
    int sortBattery(const void* f, const void* s);
    int report(CleanerBot* bot, short num_bots);
    

}

#endif // !SDDS_CLEANERBOT_H
