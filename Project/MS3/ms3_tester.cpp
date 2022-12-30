// Final Project Milestone 3
// File	ms3_tester.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include "Publication.h"
#include "Utils.h"
#include "Date.h"


using namespace std;
using namespace sdds;

//Please use putty for termial client on Matrix (https://www.putty.org/)

#ifdef _MSC_VER  // Windows Console Colors
const char col_grey[] = "\033[38;5;8m";
const char col_red[] = "\033[38;5;9m";
const char col_green[] = "\033[38;5;10m";
const char col_yellow[] = "\033[38;5;11m";
const char col_blue[] = "\033[38;5;12m";
const char col_pink[] = "\033[38;5;13m";
const char col_cyan[] = "\033[38;5;14m";
const char col_white[] = "\033[38;5;15m";
const char col_end[] = "\033[0m";
#else // Linux or Mac Console Colors
const char col_grey[] = "\e[38;5;8m";
const char col_red[] = "\e[38;5;9m";
const char col_green[] = "\e[38;5;10m";
const char col_yellow[] = "\e[38;5;11m";
const char col_blue[] = "\e[38;5;12m";
const char col_pink[] = "\e[38;5;13m";
const char col_cyan[] = "\e[38;5;14m";
const char col_white[] = "\e[38;5;15m";
const char col_end[] = "\e[0m";
#endif

void revert2Orignal();
Publication readPublication(istream& istr);
Publication getNextRec(ifstream& ifstr);

int main() {
    sdds::sdds_test = true;
    Publication pd;
    revert2Orignal();
    cout << "An Invalid publication printout:" << endl;
    cout << ">" << pd << "<" << endl;
    cout << "Enter the following: " << endl
        << col_red << "P1234" << col_end << endl
        << "------------------------------" << endl;
    pd = readPublication(cin);
    if (!cin) {
        cin.clear();
        cin.ignore(1000, '\n');
    }
    else {
        cout << "This is not supposed to be printed!" << endl;
    }
    cout << "You entered:" << endl;
    cout << ">" << pd << "<" << endl;
    cout << "Enter the following: " << endl
        << col_red << "P123" << endl
        << "Seneca Weekly" << endl
        << "2022/13/17" << col_end << endl
        << "------------------------------" << endl;
    pd = readPublication(cin);
    if (!cin) {
        cin.clear();
        cin.ignore(1000, '\n');
    }
    else {
        cout << "This is not supposed to be printed!" << endl;
    }
    cout << "You entered:" << endl;
    cout << ">" << pd << "<" << endl;
    cout << "Enter the following: " << endl
        << col_red << "P123" << endl
        << "Seneca Weekly" << endl
        << "2022/7/17" << col_end << endl
        << "------------------------------" << endl;
    pd = readPublication(cin);
    cout << "You entered:" << endl;
    cout << col_green << pd << col_end << endl;
    cout << "And the title is agian: \"" << (const char*)pd << "\"" << endl;
    pd.set(12345);
    if (pd.onLoan()) {
        cout << "Now this publication is on loan to a member with the id: 12345" << endl;
        pd.resetDate();
        cout << "The checkout date is: " << pd.checkoutDate() << endl;
        pd.setRef(9999);
        cout << "The library unique reference id is: " << pd.getRef() << endl;
        cout << col_green << pd << col_end << endl;
        cout << "----------------------------------------------------------------" << endl;
    }
    cout << "Adding the periodical publication to the end of the data file:" << endl;
    ofstream fileout("Periodicals.txt", ios::app);
    if (pd) {
        cout << "appeneded to the file" << endl;
        fileout << pd << endl;
    }
    fileout.close();
    cout << endl << "Contents of the file:" << endl;
    ifstream filein("Periodicals.txt");
    char pType{};
    for (int row = 1; filein; row++) {
        filein >> pType;
        if (pType != 'P') {
            cout << "The Record type signature is supposed to be B, but it is: " << pType << endl;
            filein.setstate(ios::failbit);
        }
        filein.ignore();
        pd = getNextRec(filein);
        if (filein) {
            if (pd == "Seneca Weekly") cout << col_blue;
            cout << (pd.onLoan() ? "|*" : "| ");
            cout.width(4);
            cout.fill(' ');
            cout.setf(ios::right);
            cout << row << (pd.onLoan() ? "*" : " ");
            cout.unsetf(ios::right);
            cout << pd << (pd == "Star" ? "<<<" : "") << endl;
            if (pd == "Seneca Weekly") cout << col_end;
        }
    }
    return 0;
}

void revert2Orignal() {
    ifstream infile("PeriodicalsOriginal.txt");
    ofstream outfile("Periodicals.txt");
    char ch{};
    while (infile.get(ch)) {
        outfile.put(ch);
    }
}

Publication readPublication(istream& istr) {
    Publication P;
    istr >> P;
    return P;
}
Publication getNextRec(ifstream& ifstr) {
    Publication P;
    ifstr >> P;
    ifstr.ignore(1000, '\n');
    return P;
}