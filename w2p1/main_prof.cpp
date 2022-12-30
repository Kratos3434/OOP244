/* ------------------------------------------------------
Workshop 2 part 1
Module: N/A
Filename: main_prof.cpp
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