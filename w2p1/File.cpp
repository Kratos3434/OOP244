/*
Name: Keith Carlos
Section: NNN
Email: kwcarlos@myseneca.ca
Student ID: 127638211
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }
    bool read(char name[]) {

        return fscanf(fptr, "%[^,],", name) == 1;
    }
    bool read(int& studentNum) {
        return fscanf(fptr, "%d,", &studentNum) == 1;
    }
    bool read(char& studentGrade) {
        return fscanf(fptr, "%c\n", &studentGrade) == 1;
    }
}