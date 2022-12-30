/*
Name: Keith Carlos
Section: NHH
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include <iostream>
#include "Menu.h"
#include "Publication.h"
#include "Book.h"
#include "Lib.h"
#include "PublicationSelector.h"

namespace sdds {

    class LibApp {
        bool m_changed{};
        Menu m_mainMenu;
        Menu m_exitMenu;
        Menu m_publicationMenu;
        char m_fileName[256]{};
        Publication* PPA[SDDS_LIBRARY_CAPACITY]{};
        int NOLP; //Number Of Loaded Publications
        int LLRN; //Last Library Reference Number

        bool confirm(const char* message);
        void load();  // prints: "Loading Data"<NEWLINE>
        void save();  // prints: "Saving Data"<NEWLINE>
        int search(int searchType);  // prints: "Searching for publication"<NEWLINE>

        void returnPub();  /*  Calls the search() method.
                               prints "Returning publication"<NEWLINE>
                               prints "Publication returned"<NEWLINE>
                               sets m_changed to true;
                           */
        void newPublication();
        void removePublication();
        void checkOutPub();
        Publication* getPub(int libRef);
    public:
        LibApp(const char* filename);
        ~LibApp();
        void run();
        void terminateMessage();
    };
}
#endif // !SDDS_LIBAPP_H