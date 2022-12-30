/*
Name: Keith Carlos
Section: NHH
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#include <iostream>
#include "LibApp.h"

using namespace std;

namespace sdds {
    LibApp::LibApp() 
	  :m_mainMenu("Seneca Library Application"),m_exitMenu("Changes have been made to the data, what would you like to do?") {
	  m_changed = false;
	  m_mainMenu << "Add New Publication" << "Remove Publication"
		<< "Checkout publication from library" << "Return publication to library";

	  m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
	  load();
    }
    bool LibApp::confirm(const char* message) {
	  Menu menu(message);
	  menu << "Yes";
	  int selection = menu.run();

	  return selection == 1;
    }
    void LibApp::load() {
	  cout << "Loading Data\n";
    }
    void LibApp::save() {
	  cout << "Saving Data\n";
    }
    void LibApp::search() {
	  cout << "Searching for publication\n";
    }

    void LibApp::returnPub() {
	  search();
	  cout << "Returning publication\n";
	  cout << "Publication returned\n";
	  m_changed = true;
    }
    void LibApp::newPublication() {
	  cout << "Adding new publication to library\n";
	  if (confirm("Add this publication to library?")) {
		m_changed = true;
		cout << "Publication added\n";
	  }
    }
    void LibApp::removePublication() {
	  cout << "Removing publication from library\n";
	  search();
	  if (confirm("Remove this publication from the library?")) {
		m_changed = true;
		cout << "Publication removed\n";
	  }
    }
    void LibApp::checkOutPub() {
	  search();
	  if (confirm("Check out publication?")) {
		m_changed = true;
		cout << "Publication checked out\n";
	  }
    }
    void terminateMessage() {
	  cout << "\n-------------------------------------------\n";
	  cout << "Thanks for using Seneca Library Application" << endl;
    }
    void LibApp::run() {
	  int s,ss;
	  do {
           s = m_mainMenu.run();
	     switch (s) {
	     case 1: 
		   newPublication();
		   cout << "\n";
		   break;
	     case 2: 
		   removePublication();
		   cout << "\n";
		   break;
	     case 3: 
		   checkOutPub();
		   cout << "\n";
		   break;
	     case 4: 
		   returnPub();
		   cout << "\n";
		   break;
	     case 0:
		   if (!m_changed) s = -1;
		   else {
			 ss = m_exitMenu.run();
			 switch(ss) {
			 case 1:
			     save();
			     s = -1;
			     break;
			 case 2:
			     cout << "\n";
			     break;
			 case 0:
			     if (confirm("This will discard all the changes are you sure?"))
				   s = -1;
			     else cout << "\n";
			     break;
			 }
		   }
	     }
	  } while (s!=-1);
	  terminateMessage();
    }
    

}