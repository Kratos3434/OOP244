/*
Name: Keith Carlos
Section: NNN
Email: kwcarlos@myseneca.ca
Student ID: 127638211
*/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
    bool openFile(const char filename[]);
    void closeFile();
    int noOfRecords();
    bool read(char name[]);
    bool read(int &studentNum);
    bool read(char& studentGrade);
}
#endif // !SDDS_FILE_H_