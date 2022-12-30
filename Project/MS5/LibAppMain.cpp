// Final Project Milestone 5
// LipApp Main
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#include "LibApp.h"
#include "Date.h"
int main() {
    sdds::sdds_day = 10;
    sdds::sdds_mon = 12;
    sdds::sdds_year = 2021;
    sdds::sdds_test = true;
    sdds::LibApp theApp("LibRecsSmall.txt");
    theApp.run();
    return 0;
}


