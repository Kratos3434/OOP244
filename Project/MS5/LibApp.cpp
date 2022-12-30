/*
Name: Keith Carlos
Section: NHH
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "LibApp.h"

using namespace std;

namespace sdds {
    LibApp::LibApp(const char* filename)
	  :m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?"),
        m_publicationMenu("Choose the type of publication:") {
	  m_changed = false;
	  strncpy(m_fileName, filename, 256);
	  NOLP = 0;
	  LLRN = 0;
	  m_mainMenu << "Add New Publication" << "Remove Publication"
		<< "Checkout publication from library" << "Return publication to library";

	  m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
	  m_publicationMenu << "Book" << "Publication";
	  load();
    }
    LibApp::~LibApp() {
	  for (int i = 0; i < NOLP; i++) {
		delete PPA[i];
	  }
    }
    bool LibApp::confirm(const char* message) {
	  Menu menu(message);
	  menu << "Yes";
	  int selection = menu.run();

	  return selection == 1;
    }
    void LibApp::load() {
	  cout << "Loading Data\n";
	  ifstream infile(m_fileName);
	  char type{};
	  int i;
		for (i = 0; infile; i++) {
		    infile >> type;
		    infile.ignore();
		    if (infile) {
			  if (type == 'P')
				PPA[i] = new Publication;
			  else if (type == 'B')
				PPA[i] = new Book;
			  if (PPA[i]) {
				infile >> *PPA[i];
				NOLP++;
				LLRN = PPA[i]->getRef();
			  }
		    }
		}
    }
    void LibApp::save() {
	  cout << "Saving Data\n";
	  ofstream ofs(m_fileName);
	  for (int i = 0; i < NOLP; i++) {
		if(PPA[i]->getRef()!=0)
		    ofs << *PPA[i] << endl;
	  }
    }
    //searchType: 1 = Search all | 2 = Search on loan | 3 = Search available publications
    int LibApp::search(int searchType) {
	  PublicationSelector ps("Select one of the following found matches:", 15);
	  int s, i, resultReturned{};
	  char* title = new char[256];
	  bool matchFound = false;
	  if (searchType == 1) {
		s = m_publicationMenu.run();
		switch (s) {
		case 0:
		    cout << "Aborted!\n";
		case 1:
		    cin.ignore();
		    cout << "Publication Title: ";
		    cin.getline(title, 256);
		    for (i = 0; i < NOLP; i++) {
			  if (PPA[i]->getRef() && *PPA[i]==title && PPA[i]->type() != 'P') {
				matchFound = true;
				ps << *PPA[i];
			  }
		    }
		    if (matchFound) {
			  ps.sort();
			  resultReturned = ps.run();
			  if (resultReturned == 0) cout << "Aborted!\n";
		    }
		    else cout << "No matches found!\n";
		    break;
		case 2:
		    cin.ignore();
		    cout << "Publication Title: ";
		    cin.getline(title, 256);
		    for (i = 0; i < NOLP; i++) {
			  if (PPA[i]->getRef() && *PPA[i]==title && PPA[i]->type() == 'P') {
				matchFound = true;
				ps << *PPA[i];
			  }
		    }
		    if (matchFound) {
			  ps.sort();
			  resultReturned = ps.run();
			  if (resultReturned == 0) cout << "Aborted!\n";
		    }
		    else cout << "No matches found!\n";
		    break;
		}
	  }
	  else if (searchType == 2) {
		s = m_publicationMenu.run();
		switch (s) {
		case 0:
		    cout << "Aborted!\n";
		case 1:
		    cin.ignore();
		    cout << "Publication Title: ";
		    cin.getline(title, 256);
		    for (i = 0; i < NOLP; i++) {
			  if (PPA[i]->getRef() && *PPA[i] == title && PPA[i]->type() != 'P' && PPA[i]->onLoan()) {
				matchFound = true;
				ps << *PPA[i];
			  }
		    }
		    if (matchFound) {
			  ps.sort();
			  resultReturned = ps.run();
			  if (resultReturned == 0) cout << "Aborted!\n";
		    }
		    else cout << "No matches found!\n";
		    break;
		case 2:
		    cin.ignore();
		    cout << "Publication Title: ";
		    cin.getline(title, 256);
		    for (i = 0; i < NOLP; i++) {
			  if (PPA[i]->getRef() && *PPA[i] == title && PPA[i]->type() == 'P' && PPA[i]->onLoan()) {
				matchFound = true;
				ps << *PPA[i];
			  }
		    }
		    if (matchFound) {
			  ps.sort();
			  resultReturned = ps.run();
			  if (resultReturned == 0) cout << "Aborted!\n";
		    }
		    else cout << "No matches found!\n";
		    break;
		}
	  }
	  else if (searchType == 3) {
		s = m_publicationMenu.run();
		switch (s) {
		case 0:
		    cout << "Aborted!\n";
		case 1:
		    cin.ignore();
		    cout << "Publication Title: ";
		    cin.getline(title, 256);
		    for (i = 0; i < NOLP; i++) {
			  if (PPA[i]->getRef() && *PPA[i] == title && PPA[i]->type() != 'P' && !PPA[i]->onLoan()) {
				matchFound = true;
				ps << *PPA[i];
			  }
		    }
		    if (matchFound) {
			  ps.sort();
			  resultReturned = ps.run();
			  if(resultReturned == 0) cout << "Aborted!\n";
		    }
		    else cout << "No matches found!\n";
		    break;
		case 2:
		    cin.ignore();
		    cout << "Publication Title: ";
		    cin.getline(title, 256);
		    for (i = 0; i < NOLP; i++) {
			  if (PPA[i]->getRef() && *PPA[i] == title && PPA[i]->type() == 'P' && !PPA[i]->onLoan()) {
				matchFound = true;
				ps << *PPA[i];
			  }
		    }
		    if (matchFound) {
			  ps.sort();
			  resultReturned = ps.run();
			  if (resultReturned == 0) cout << "Aborted!\n";
		    }
		    else cout << "No matches found!\n";
		    break;
		}
	  }
	  delete[] title;
	  return resultReturned;
    }
    Publication* LibApp::getPub(int libRef) {
	  for (int i = 0; i < NOLP; i++) {
		if (PPA[i]->getRef() == libRef)
		    return PPA[i];
	  }
	  return nullptr;
    }
    void LibApp::returnPub() {
	  int index = -1;
	  int daysOnLoan,daysLate;
	  double penalty;
	  Date d;
	  cout << "Return publication to the library\n";
	  int searchReturnVal = search(2);//Search on Loan
	  if (searchReturnVal > 0) {//search returns 0 by default
		for (int i = 0; i < NOLP; i++) {
		    if (PPA[i]->getRef() == searchReturnVal)
			  index = i;
		}
		if (index > -1) {
		    cout << *PPA[index] << endl;
		    if (confirm("Return Publication?")) {
			  daysOnLoan = d - PPA[index]->checkoutDate();
			  if (daysOnLoan > SDDS_MAX_LOAN_DAYS) {
				daysLate = daysOnLoan - SDDS_MAX_LOAN_DAYS;
				penalty = .50 * daysLate;
				cout << "Please pay $";
				cout << fixed << setprecision(2) << penalty;
				cout.unsetf(ios::fixed);
				cout << " penalty for being " << daysLate << " days late!\n";
			  }
			  PPA[index]->set(0);
			  m_changed = true;
			  cout << "Publication returned\n";
		    }
		}
	  }
    }
    void LibApp::newPublication() {
	  int s;
	  Publication* pub = nullptr;
	  if (NOLP == SDDS_LIBRARY_CAPACITY) {
		cout << "Library is at its maximum capacity!\n";
		return;
	  }
	  else {
		cout << "Adding new publication to the library\n";
		s = m_publicationMenu.run();
		switch (s) {
		case 0: 
		    cout << "Aborted!\n";
		    break;
		case 1:
		    pub = new Book;
		    pub->read(cin);
		    if (cin.fail()) cin.ignore(1000, '\n');
		    else {
			  if (confirm("Add this publication to the library?")) {
				if (pub) {
				    LLRN++;
				    pub->setRef(LLRN);
				    PPA[NOLP] = pub;
				    NOLP++;
				    m_changed = true;
				    cout << "Publication added\n";
				}
				else {
				    cout << "Failed to add publication!\n";
				    delete pub;
				}
			  }
			  else cout << "Aborted!\n";
		    }
		    break;
		case 2:
		    pub = new Publication;
		    pub->read(cin);
		    if (cin.fail()) cin.ignore(1000, '\n');
		    else {
			  if (confirm("Add this publication to the library?")) {
				if (pub) {
				    LLRN++;
				    pub->setRef(LLRN);
				    PPA[NOLP] = pub;
				    NOLP++;
				    m_changed = true;
				    cout << "Publication added\n";
				}
				else {
				    cout << "Failed to add publication!\n";
				    delete pub;
				}
			  }
			  else cout << "Aborted!\n";
		    }
		    break;
		}
	  }
    }
    void LibApp::removePublication() {
	  int searchReturnVal;
	  int index = -1;
	  cout << "Removing publication from the library\n";
	  searchReturnVal = search(1);//search all
	  if (searchReturnVal > 0) {//search returns 0 by default
		for (int i = 0; i < NOLP; i++) {
		    if (PPA[i]->getRef() == searchReturnVal)
			  index = i;
		}
		if (index > -1) {
		    cout << *PPA[index] << endl;
		    if (confirm("Remove this publication from the library?")) {
			  PPA[index]->setRef(0);
			  m_changed = true;
			  cout << "Publication removed\n";
		    }
		}
	  }
    }
    void LibApp::checkOutPub() {
	  int searchReturnVal,num,len,index=-1;
	  cout << "Checkout publication from the library\n";
	  searchReturnVal = search(3);//Search available publication
	  if (searchReturnVal > 0) {//search returns 0 by default
		for (int i = 0; i < NOLP; i++) {
		    if (PPA[i]->getRef() == searchReturnVal)
			  index = i;
		}
		if (index > -1) {
		cout << *PPA[index] << endl;
		if (confirm("Check out publication?")) {
		    cout << "Enter Membership number: ";
			  do {
				cin >> num;
				len = numLen(num);//Check length of int
				if (len != 5) cout << "Invalid membership number, try again: ";
			  } while (len != 5);
			  PPA[index]->set(num);
			  m_changed = true;
			  cout << "Publication checked out\n";
		    }
		}
	  }
    }
    void LibApp::terminateMessage() {
	  cout << "\n-------------------------------------------\n";
	  cout << "Thanks for using Seneca Library Application" << endl;
    }
    void LibApp::run() {
	  int s, ss;
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
			  switch (ss) {
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
	  } while (s != -1);
	  terminateMessage();
    }


}