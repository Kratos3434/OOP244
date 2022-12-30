// Workshop 5:
// Version: 1.0
// Author: Aras Azimipanah
// Description:
// This file tests the lab section of your workshop
/////////////////////////////////////////////
#include <iostream>
#include "Book.h"
#include "Chapter.h"
using namespace std;
using namespace sdds;

void print_test_section_separator() {
    // For ease of reading tester output
    cout << "---------------------------------------------------------------------" << endl;
}

int main() {
    /*Python Book*/
    Book python = { "Fluent Python", "Luciano Romalho", 38.5 };
    Chapter py_chapter = { "Introduction", 1, 10, 5000 };
    python += py_chapter;

    /*CPP Book*/
    Book cpp("Object Oriented Programming using C++", "Bjarne Stroustrup", 89.56);
    Chapter chapters[] = {
       {"Introduction", 1, 10, 4853},
       {"Language History",2, 23, 12000},
       {"Varibales",3, 30, 16400},
       {"Flow Control",4,  33, 18450}
    };
    for (int i = 0; i < 4; i++) {
        cpp += chapters[i];
        // Test proper implementation of the postfix ++
        cout << "'" << (const char*)(cpp) << "' book now has " << (int)cpp << " chpaters!" << endl;
    }

    Book books[] = {
        //Empty Books
        {},
        {"Java Programming"},
        {"Go Programming", "Alan Donovan", 0},
        {"Java Programming", "Joshua Bloch",35.0 },
        // Non Empty Books
        python,
        cpp
    };

    for (int i = 0; i < 6; i++) {
        if (books[i])
            cout << (const char*)books[i] << " is not empty!" << endl;
        if (!books[i])
            cout << (const char*)books[i] << " is empty!" << endl;
    }
    print_test_section_separator();

    // Test Insertion operator overloads 
    // This will test both insertion operators for Book and Chapter classes!
    cout << cpp;
    print_test_section_separator();

    // Show cpp and python books summary
    cout << "Orignal prices:" << endl;
    cpp.summary();
    python.summary();
    print_test_section_separator();

    // Books going on sale!
    python -= 7.0;
    cpp -= 8.5;
    cout << "After discount prices:" << endl;
    cpp.summary();
    python.summary();
    print_test_section_separator();

    // Individual typecast tests
    cout << "'" << (const char*)(cpp) << "' book has " << (int)cpp << " chapters." << endl;
    cout << "Final price of '" << (const char*)(cpp) << "' book: $" << (double)cpp << endl;
    cout << "First chpater of '" << (const char*)(cpp) <<
        "' book has " << (int)chapters[0] << " pages and an avarage of " <<
        (double)chapters[0] << " words per page." << endl;


    return 0;
}